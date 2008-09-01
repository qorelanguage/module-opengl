/*
  qore-opengl.h
  
  Qore Programming Language

  Copyright 2003 - 2008 David Nichols

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef _QORE_OPENGL_H

#define _QORE_OPENGL_H

// to get ext prototypes with mesa
#define GL_GLEXT_PROTOTYPES 1

#include "gl.h"

DLLLOCAL void addOpenGLConstants();
DLLLOCAL void addOpenGLExtConstants();

DLLLOCAL void initOpenGLExt();
DLLLOCAL void initOpenGLU();

DLLLOCAL extern QoreNamespace opengl_ns;

#endif 
