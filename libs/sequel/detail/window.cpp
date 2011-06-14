
/* Copyright (c) 2011, Stefan Eilemann <eile@eyescale.ch> 
 *
 * This library is free software; you can redistribute it and/or modify it under
 * the terms of the GNU Lesser General Public License version 2.1 as published
 * by the Free Software Foundation.
 *  
 * This library is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more
 * details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#include "window.h"

#include "config.h"
#include "pipe.h"
#include "renderer.h"

#include <eq/sequel/renderer.h>

namespace seq
{
namespace detail
{

Window::Window( eq::Pipe* parent )
        : eq::Window( parent ) 
{}

Window::~Window()
{
}

Config* Window::getConfig()
{
    return static_cast< Config* >( eq::Window::getConfig( ));
}

Pipe* Window::getPipe()
{
    return static_cast< Pipe* >( eq::Window::getPipe( ));
}

seq::Renderer* Window::getRenderer()
{
    return getPipe()->getRenderer();
}

detail::Renderer* Window::getRendererImpl()
{
    return getPipe()->getRendererImpl();
}

bool Window::configInitGL( const uint128_t& initID )
{
    co::Object* initData = getConfig()->getInitData();
    seq::Renderer* const renderer = getRenderer();
    return renderer->initGL( initData );
}

bool Window::configExitGL()
{
    seq::Renderer* const renderer = getRenderer();
    return renderer->exitGL();
}

}
}
