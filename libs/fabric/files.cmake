# Copyright (c) 2010 Daniel Pfeifer <daniel@pfeifer-mail.de>
#               2010 Stefan Eilemann <eile@eyescale.ch>

set(EQ_FABRIC_FORWARD_HEADERS
    ../fabric/api.h
    ../fabric/base.h
    ../fabric/canvas.h
    ../fabric/canvasPackets.h
    ../fabric/channel.h
    ../fabric/colorMask.h
    ../fabric/commands.h
    ../fabric/config.h
    ../fabric/configPackets.h
    ../fabric/configVisitor.h
    ../fabric/client.h
    ../fabric/drawableConfig.h
    ../fabric/elementVisitor.h
    ../fabric/eye.h
    ../fabric/error.h
    ../fabric/frustum.h
    ../fabric/global.h
    ../fabric/layout.h
    ../fabric/layoutPackets.h
    ../fabric/iAttribute.h
    ../fabric/init.h
    ../fabric/leafVisitor.h
    ../fabric/log.h
    ../fabric/node.h
    ../fabric/nodeType.h
    ../fabric/object.h
    ../fabric/observer.h
    ../fabric/packets.h
    ../fabric/packetType.h
    ../fabric/paths.h
    ../fabric/pipe.h
    ../fabric/pipePackets.h
    ../fabric/pixel.h
    ../fabric/pixelViewport.h
    ../fabric/projection.h
    ../fabric/range.h
    ../fabric/renderContext.h
    ../fabric/segment.h
    ../fabric/serializable.h
    ../fabric/server.h
    ../fabric/serverPackets.h
    ../fabric/subPixel.h
    ../fabric/task.h
    ../fabric/types.h
    ../fabric/viewport.h
    ../fabric/view.h
    ../fabric/visitorResult.h
    ../fabric/wall.h
    ../fabric/window.h
    ../fabric/windowPackets.h
    ../fabric/zoom.h
  )

set(EQ_FABRIC_HEADERS
   ../fabric/nameFinder.h
  )

set(EQ_FABRIC_SOURCES
    ../fabric/canvas.ipp
    ../fabric/channel.ipp
    ../fabric/client.cpp
    ../fabric/colorMask.cpp
    ../fabric/config.ipp
    ../fabric/eye.cpp
    ../fabric/frustum.cpp
    ../fabric/global.cpp
    ../fabric/iAttribute.cpp
    ../fabric/init.cpp
    ../fabric/layout.ipp
    ../fabric/node.ipp
    ../fabric/object.cpp
    ../fabric/observer.ipp
    ../fabric/pixel.cpp
    ../fabric/pipe.ipp
    ../fabric/projection.cpp
    ../fabric/range.cpp
    ../fabric/renderContext.cpp
    ../fabric/segment.ipp
    ../fabric/server.ipp
    ../fabric/subPixel.cpp
    ../fabric/view.ipp
    ../fabric/viewport.cpp
    ../fabric/window.ipp
    ../fabric/wall.cpp
    ../fabric/zoom.cpp
  )

