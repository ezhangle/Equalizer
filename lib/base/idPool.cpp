
/* Copyright (c) 2005-2008, Stefan Eilemann <eile@equalizergraphics.com> 
   All rights reserved. */

#include "idPool.h"

#include <eq/base/debug.h>

using namespace eqBase;
using namespace std;

#define COMPRESS_INTERVAL 10000

IDPool::IDPool( const uint32_t initialCapacity )
        : _compressCounter(0)
{
    if( initialCapacity )
    {
        Block* block = new Block();
        block->start = 1;
        block->range = initialCapacity;
        
        _freeIDs.push_front( block );
    }
}

IDPool::~IDPool()
{
    while( !_freeIDs.empty( ))
    {
        Block* block = _freeIDs.front();
        _freeIDs.pop_front();
        delete block;
    }
    while( !_blockCache.empty( ))
    {
        Block* block = _blockCache.front();
        _blockCache.pop_front();
        delete block;
    }
}

uint32_t IDPool::genIDs( const uint32_t range )
{
    CHECK_THREAD( _thread );

    const uint32_t id = _genIDs( range );
    if( id )
        return id;

    _compressIDs();
    return _genIDs( range );
}

uint32_t IDPool::_genIDs( const uint32_t range )
{
    for( list<Block*>::iterator i = _freeIDs.begin(); i != _freeIDs.end(); ++i )
    {
        Block* block = *i;

        if( range <= block->range )
        {
            uint32_t start = block->start;

            block->range -= range;
            block->start += range;

            if( block->range == 0 )
            {
                _freeIDs.erase( i );
                _blockCache.push_front( block );
            }

            return start;
        }
    }
    return EQ_ID_INVALID;
}

void IDPool::freeIDs( const uint32_t start, const uint32_t range )
{
    CHECK_THREAD( _thread );

    Block* block;

    if( _blockCache.empty( ))
        block = new Block;
    else
    {
        block = _blockCache.front();
        _blockCache.pop_front();
    }

    block->start = start;
    block->range = range;
    _freeIDs.push_front( block );

    _compressCounter++;
    if( ( _compressCounter % COMPRESS_INTERVAL) == 0 )
        _compressIDs();
}

void IDPool::_compressIDs()
{
    list<Block*> blocks;
    bool         compress = true;
    
    while( compress )
    {
        blocks.clear();
        compress = false;

        while( !_freeIDs.empty( ))
        {
            Block* block = _freeIDs.front();
            _freeIDs.pop_front();

            for( list<Block*>::iterator iter = _freeIDs.begin(); 
                 iter != _freeIDs.end(); ++iter )
            {
                Block* block2 = *iter;
                
                if(( block->start + block->range ) == block2->start )
                {
                    block->range += block2->range;

                    list<Block*>::iterator iter2 = iter;
                    ++iter;
                    _freeIDs.erase( iter2 );

                    _blockCache.push_front( block2 );
                    compress = true;
                }
                else if( block->start == ( block2->start + block2->range ))
                {
                    block->start  = block2->start;
                    block->range += block2->range;

                    list<Block*>::iterator iter2 = iter;
                    ++iter;
                    _freeIDs.erase( iter2 );

                    _blockCache.push_front( block2 );
                    compress = true;
                }
            }
            
            blocks.push_front( block );
        }

        _freeIDs.swap( blocks );
    }
}
