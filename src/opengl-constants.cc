/*
  opengl.cc
  
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

#include <qore/Qore.h>

#include "qore-opengl.h"

void addOpenGLConstants()
{
#if defined GL_VERSION_2_1
   opengl_ns.addConstant("GL_VERSION_MAJOR",                       new QoreBigIntNode(2));
   opengl_ns.addConstant("GL_VERSION_MINOR",                       new QoreBigIntNode(1));
#elif defined GL_VERSION_2_0
   opengl_ns.addConstant("GL_VERSION_MAJOR",                       new QoreBigIntNode(2));
   opengl_ns.addConstant("GL_VERSION_MINOR",                       new QoreBigIntNode(0));
#elif defined GL_VERSION_1_5
   opengl_ns.addConstant("GL_VERSION_MAJOR",                       new QoreBigIntNode(1));
   opengl_ns.addConstant("GL_VERSION_MINOR",                       new QoreBigIntNode(5));
#elif defined GL_VERSION_1_4
   opengl_ns.addConstant("GL_VERSION_MAJOR",                       new QoreBigIntNode(1));
   opengl_ns.addConstant("GL_VERSION_MINOR",                       new QoreBigIntNode(4));
#elif defined GL_VERSION_1_3
   opengl_ns.addConstant("GL_VERSION_MAJOR",                       new QoreBigIntNode(1));
   opengl_ns.addConstant("GL_VERSION_MINOR",                       new QoreBigIntNode(3));
#elif defined GL_VERSION_1_2
   opengl_ns.addConstant("GL_VERSION_MAJOR",                       new QoreBigIntNode(1));
   opengl_ns.addConstant("GL_VERSION_MINOR",                       new QoreBigIntNode(2));
#elif defined GL_VERSION_1_1
   opengl_ns.addConstant("GL_VERSION_MAJOR",                       new QoreBigIntNode(1));
   opengl_ns.addConstant("GL_VERSION_MINOR",                       new QoreBigIntNode(1));
#endif

   opengl_ns.addConstant("GL_ACCUM",                                   new QoreBigIntNode(GL_ACCUM));
   opengl_ns.addConstant("GL_LOAD",                                    new QoreBigIntNode(GL_LOAD));
   opengl_ns.addConstant("GL_RETURN",                                  new QoreBigIntNode(GL_RETURN));
   opengl_ns.addConstant("GL_MULT",                                    new QoreBigIntNode(GL_MULT));
   opengl_ns.addConstant("GL_ADD",                                     new QoreBigIntNode(GL_ADD));
   opengl_ns.addConstant("GL_NEVER",                                   new QoreBigIntNode(GL_NEVER));
   opengl_ns.addConstant("GL_LESS",                                    new QoreBigIntNode(GL_LESS));
   opengl_ns.addConstant("GL_EQUAL",                                   new QoreBigIntNode(GL_EQUAL));
   opengl_ns.addConstant("GL_LEQUAL",                                  new QoreBigIntNode(GL_LEQUAL));
   opengl_ns.addConstant("GL_GREATER",                                 new QoreBigIntNode(GL_GREATER));
   opengl_ns.addConstant("GL_NOTEQUAL",                                new QoreBigIntNode(GL_NOTEQUAL));
   opengl_ns.addConstant("GL_GEQUAL",                                  new QoreBigIntNode(GL_GEQUAL));
   opengl_ns.addConstant("GL_ALWAYS",                                  new QoreBigIntNode(GL_ALWAYS));
   opengl_ns.addConstant("GL_CURRENT_BIT",                             new QoreBigIntNode(GL_CURRENT_BIT));
   opengl_ns.addConstant("GL_POINT_BIT",                               new QoreBigIntNode(GL_POINT_BIT));
   opengl_ns.addConstant("GL_LINE_BIT",                                new QoreBigIntNode(GL_LINE_BIT));
   opengl_ns.addConstant("GL_POLYGON_BIT",                             new QoreBigIntNode(GL_POLYGON_BIT));
   opengl_ns.addConstant("GL_POLYGON_STIPPLE_BIT",                     new QoreBigIntNode(GL_POLYGON_STIPPLE_BIT));
   opengl_ns.addConstant("GL_PIXEL_MODE_BIT",                          new QoreBigIntNode(GL_PIXEL_MODE_BIT));
   opengl_ns.addConstant("GL_LIGHTING_BIT",                            new QoreBigIntNode(GL_LIGHTING_BIT));
   opengl_ns.addConstant("GL_FOG_BIT",                                 new QoreBigIntNode(GL_FOG_BIT));
   opengl_ns.addConstant("GL_DEPTH_BUFFER_BIT",                        new QoreBigIntNode(GL_DEPTH_BUFFER_BIT));
   opengl_ns.addConstant("GL_ACCUM_BUFFER_BIT",                        new QoreBigIntNode(GL_ACCUM_BUFFER_BIT));
   opengl_ns.addConstant("GL_STENCIL_BUFFER_BIT",                      new QoreBigIntNode(GL_STENCIL_BUFFER_BIT));
   opengl_ns.addConstant("GL_VIEWPORT_BIT",                            new QoreBigIntNode(GL_VIEWPORT_BIT));
   opengl_ns.addConstant("GL_TRANSFORM_BIT",                           new QoreBigIntNode(GL_TRANSFORM_BIT));
   opengl_ns.addConstant("GL_ENABLE_BIT",                              new QoreBigIntNode(GL_ENABLE_BIT));
   opengl_ns.addConstant("GL_COLOR_BUFFER_BIT",                        new QoreBigIntNode(GL_COLOR_BUFFER_BIT));
   opengl_ns.addConstant("GL_HINT_BIT",                                new QoreBigIntNode(GL_HINT_BIT));
   opengl_ns.addConstant("GL_EVAL_BIT",                                new QoreBigIntNode(GL_EVAL_BIT));
   opengl_ns.addConstant("GL_LIST_BIT",                                new QoreBigIntNode(GL_LIST_BIT));
   opengl_ns.addConstant("GL_TEXTURE_BIT",                             new QoreBigIntNode(GL_TEXTURE_BIT));
   opengl_ns.addConstant("GL_SCISSOR_BIT",                             new QoreBigIntNode(GL_SCISSOR_BIT));
   opengl_ns.addConstant("GL_ALL_ATTRIB_BITS",                         new QoreBigIntNode(GL_ALL_ATTRIB_BITS));
   opengl_ns.addConstant("GL_POINTS",                                  new QoreBigIntNode(GL_POINTS));
   opengl_ns.addConstant("GL_LINES",                                   new QoreBigIntNode(GL_LINES));
   opengl_ns.addConstant("GL_LINE_LOOP",                               new QoreBigIntNode(GL_LINE_LOOP));
   opengl_ns.addConstant("GL_LINE_STRIP",                              new QoreBigIntNode(GL_LINE_STRIP));
   opengl_ns.addConstant("GL_TRIANGLES",                               new QoreBigIntNode(GL_TRIANGLES));
   opengl_ns.addConstant("GL_TRIANGLE_STRIP",                          new QoreBigIntNode(GL_TRIANGLE_STRIP));
   opengl_ns.addConstant("GL_TRIANGLE_FAN",                            new QoreBigIntNode(GL_TRIANGLE_FAN));
   opengl_ns.addConstant("GL_QUADS",                                   new QoreBigIntNode(GL_QUADS));
   opengl_ns.addConstant("GL_QUAD_STRIP",                              new QoreBigIntNode(GL_QUAD_STRIP));
   opengl_ns.addConstant("GL_POLYGON",                                 new QoreBigIntNode(GL_POLYGON));
   opengl_ns.addConstant("GL_ZERO",                                    new QoreBigIntNode(GL_ZERO));
   opengl_ns.addConstant("GL_ONE",                                     new QoreBigIntNode(GL_ONE));
   opengl_ns.addConstant("GL_SRC_COLOR",                               new QoreBigIntNode(GL_SRC_COLOR));
   opengl_ns.addConstant("GL_ONE_MINUS_SRC_COLOR",                     new QoreBigIntNode(GL_ONE_MINUS_SRC_COLOR));
   opengl_ns.addConstant("GL_SRC_ALPHA",                               new QoreBigIntNode(GL_SRC_ALPHA));
   opengl_ns.addConstant("GL_ONE_MINUS_SRC_ALPHA",                     new QoreBigIntNode(GL_ONE_MINUS_SRC_ALPHA));
   opengl_ns.addConstant("GL_DST_ALPHA",                               new QoreBigIntNode(GL_DST_ALPHA));
   opengl_ns.addConstant("GL_ONE_MINUS_DST_ALPHA",                     new QoreBigIntNode(GL_ONE_MINUS_DST_ALPHA));
   opengl_ns.addConstant("GL_DST_COLOR",                               new QoreBigIntNode(GL_DST_COLOR));
   opengl_ns.addConstant("GL_ONE_MINUS_DST_COLOR",                     new QoreBigIntNode(GL_ONE_MINUS_DST_COLOR));
   opengl_ns.addConstant("GL_SRC_ALPHA_SATURATE",                      new QoreBigIntNode(GL_SRC_ALPHA_SATURATE));
   opengl_ns.addConstant("GL_TRUE",                                    new QoreBigIntNode(GL_TRUE));
   opengl_ns.addConstant("GL_FALSE",                                   new QoreBigIntNode(GL_FALSE));
   opengl_ns.addConstant("GL_CLIP_PLANE0",                             new QoreBigIntNode(GL_CLIP_PLANE0));
   opengl_ns.addConstant("GL_CLIP_PLANE1",                             new QoreBigIntNode(GL_CLIP_PLANE1));
   opengl_ns.addConstant("GL_CLIP_PLANE2",                             new QoreBigIntNode(GL_CLIP_PLANE2));
   opengl_ns.addConstant("GL_CLIP_PLANE3",                             new QoreBigIntNode(GL_CLIP_PLANE3));
   opengl_ns.addConstant("GL_CLIP_PLANE4",                             new QoreBigIntNode(GL_CLIP_PLANE4));
   opengl_ns.addConstant("GL_CLIP_PLANE5",                             new QoreBigIntNode(GL_CLIP_PLANE5));
   opengl_ns.addConstant("GL_BYTE",                                    new QoreBigIntNode(GL_BYTE));
   opengl_ns.addConstant("GL_UNSIGNED_BYTE",                           new QoreBigIntNode(GL_UNSIGNED_BYTE));
   opengl_ns.addConstant("GL_SHORT",                                   new QoreBigIntNode(GL_SHORT));
   opengl_ns.addConstant("GL_UNSIGNED_SHORT",                          new QoreBigIntNode(GL_UNSIGNED_SHORT));
   opengl_ns.addConstant("GL_INT",                                     new QoreBigIntNode(GL_INT));
   opengl_ns.addConstant("GL_UNSIGNED_INT",                            new QoreBigIntNode(GL_UNSIGNED_INT));
   opengl_ns.addConstant("GL_FLOAT",                                   new QoreBigIntNode(GL_FLOAT));
   opengl_ns.addConstant("GL_2_BYTES",                                 new QoreBigIntNode(GL_2_BYTES));
   opengl_ns.addConstant("GL_3_BYTES",                                 new QoreBigIntNode(GL_3_BYTES));
   opengl_ns.addConstant("GL_4_BYTES",                                 new QoreBigIntNode(GL_4_BYTES));
   opengl_ns.addConstant("GL_DOUBLE",                                  new QoreBigIntNode(GL_DOUBLE));
   opengl_ns.addConstant("GL_NONE",                                    new QoreBigIntNode(GL_NONE));
   opengl_ns.addConstant("GL_FRONT_LEFT",                              new QoreBigIntNode(GL_FRONT_LEFT));
   opengl_ns.addConstant("GL_FRONT_RIGHT",                             new QoreBigIntNode(GL_FRONT_RIGHT));
   opengl_ns.addConstant("GL_BACK_LEFT",                               new QoreBigIntNode(GL_BACK_LEFT));
   opengl_ns.addConstant("GL_BACK_RIGHT",                              new QoreBigIntNode(GL_BACK_RIGHT));
   opengl_ns.addConstant("GL_FRONT",                                   new QoreBigIntNode(GL_FRONT));
   opengl_ns.addConstant("GL_BACK",                                    new QoreBigIntNode(GL_BACK));
   opengl_ns.addConstant("GL_LEFT",                                    new QoreBigIntNode(GL_LEFT));
   opengl_ns.addConstant("GL_RIGHT",                                   new QoreBigIntNode(GL_RIGHT));
   opengl_ns.addConstant("GL_FRONT_AND_BACK",                          new QoreBigIntNode(GL_FRONT_AND_BACK));
   opengl_ns.addConstant("GL_AUX0",                                    new QoreBigIntNode(GL_AUX0));
   opengl_ns.addConstant("GL_AUX1",                                    new QoreBigIntNode(GL_AUX1));
   opengl_ns.addConstant("GL_AUX2",                                    new QoreBigIntNode(GL_AUX2));
   opengl_ns.addConstant("GL_AUX3",                                    new QoreBigIntNode(GL_AUX3));
   opengl_ns.addConstant("GL_NO_ERROR",                                new QoreBigIntNode(GL_NO_ERROR));
   opengl_ns.addConstant("GL_INVALID_ENUM",                            new QoreBigIntNode(GL_INVALID_ENUM));
   opengl_ns.addConstant("GL_INVALID_VALUE",                           new QoreBigIntNode(GL_INVALID_VALUE));
   opengl_ns.addConstant("GL_INVALID_OPERATION",                       new QoreBigIntNode(GL_INVALID_OPERATION));
   opengl_ns.addConstant("GL_STACK_OVERFLOW",                          new QoreBigIntNode(GL_STACK_OVERFLOW));
   opengl_ns.addConstant("GL_STACK_UNDERFLOW",                         new QoreBigIntNode(GL_STACK_UNDERFLOW));
   opengl_ns.addConstant("GL_OUT_OF_MEMORY",                           new QoreBigIntNode(GL_OUT_OF_MEMORY));
   opengl_ns.addConstant("GL_2D",                                      new QoreBigIntNode(GL_2D));
   opengl_ns.addConstant("GL_3D",                                      new QoreBigIntNode(GL_3D));
   opengl_ns.addConstant("GL_3D_COLOR",                                new QoreBigIntNode(GL_3D_COLOR));
   opengl_ns.addConstant("GL_3D_COLOR_TEXTURE",                        new QoreBigIntNode(GL_3D_COLOR_TEXTURE));
   opengl_ns.addConstant("GL_4D_COLOR_TEXTURE",                        new QoreBigIntNode(GL_4D_COLOR_TEXTURE));
   opengl_ns.addConstant("GL_PASS_THROUGH_TOKEN",                      new QoreBigIntNode(GL_PASS_THROUGH_TOKEN));
   opengl_ns.addConstant("GL_POINT_TOKEN",                             new QoreBigIntNode(GL_POINT_TOKEN));
   opengl_ns.addConstant("GL_LINE_TOKEN",                              new QoreBigIntNode(GL_LINE_TOKEN));
   opengl_ns.addConstant("GL_POLYGON_TOKEN",                           new QoreBigIntNode(GL_POLYGON_TOKEN));
   opengl_ns.addConstant("GL_BITMAP_TOKEN",                            new QoreBigIntNode(GL_BITMAP_TOKEN));
   opengl_ns.addConstant("GL_DRAW_PIXEL_TOKEN",                        new QoreBigIntNode(GL_DRAW_PIXEL_TOKEN));
   opengl_ns.addConstant("GL_COPY_PIXEL_TOKEN",                        new QoreBigIntNode(GL_COPY_PIXEL_TOKEN));
   opengl_ns.addConstant("GL_LINE_RESET_TOKEN",                        new QoreBigIntNode(GL_LINE_RESET_TOKEN));
   opengl_ns.addConstant("GL_EXP",                                     new QoreBigIntNode(GL_EXP));
   opengl_ns.addConstant("GL_EXP2",                                    new QoreBigIntNode(GL_EXP2));
   opengl_ns.addConstant("GL_CW",                                      new QoreBigIntNode(GL_CW));
   opengl_ns.addConstant("GL_CCW",                                     new QoreBigIntNode(GL_CCW));
   opengl_ns.addConstant("GL_COEFF",                                   new QoreBigIntNode(GL_COEFF));
   opengl_ns.addConstant("GL_ORDER",                                   new QoreBigIntNode(GL_ORDER));
   opengl_ns.addConstant("GL_DOMAIN",                                  new QoreBigIntNode(GL_DOMAIN));
   opengl_ns.addConstant("GL_CURRENT_COLOR",                           new QoreBigIntNode(GL_CURRENT_COLOR));
   opengl_ns.addConstant("GL_CURRENT_INDEX",                           new QoreBigIntNode(GL_CURRENT_INDEX));
   opengl_ns.addConstant("GL_CURRENT_NORMAL",                          new QoreBigIntNode(GL_CURRENT_NORMAL));
   opengl_ns.addConstant("GL_CURRENT_TEXTURE_COORDS",                  new QoreBigIntNode(GL_CURRENT_TEXTURE_COORDS));
   opengl_ns.addConstant("GL_CURRENT_RASTER_COLOR",                    new QoreBigIntNode(GL_CURRENT_RASTER_COLOR));
   opengl_ns.addConstant("GL_CURRENT_RASTER_INDEX",                    new QoreBigIntNode(GL_CURRENT_RASTER_INDEX));
   opengl_ns.addConstant("GL_CURRENT_RASTER_TEXTURE_COORDS",           new QoreBigIntNode(GL_CURRENT_RASTER_TEXTURE_COORDS));
   opengl_ns.addConstant("GL_CURRENT_RASTER_POSITION",                 new QoreBigIntNode(GL_CURRENT_RASTER_POSITION));
   opengl_ns.addConstant("GL_CURRENT_RASTER_POSITION_VALID",           new QoreBigIntNode(GL_CURRENT_RASTER_POSITION_VALID));
   opengl_ns.addConstant("GL_CURRENT_RASTER_DISTANCE",                 new QoreBigIntNode(GL_CURRENT_RASTER_DISTANCE));
   opengl_ns.addConstant("GL_POINT_SMOOTH",                            new QoreBigIntNode(GL_POINT_SMOOTH));
   opengl_ns.addConstant("GL_POINT_SIZE",                              new QoreBigIntNode(GL_POINT_SIZE));
   opengl_ns.addConstant("GL_POINT_SIZE_RANGE",                        new QoreBigIntNode(GL_POINT_SIZE_RANGE));
   opengl_ns.addConstant("GL_POINT_SIZE_GRANULARITY",                  new QoreBigIntNode(GL_POINT_SIZE_GRANULARITY));
   opengl_ns.addConstant("GL_LINE_SMOOTH",                             new QoreBigIntNode(GL_LINE_SMOOTH));
   opengl_ns.addConstant("GL_LINE_WIDTH",                              new QoreBigIntNode(GL_LINE_WIDTH));
   opengl_ns.addConstant("GL_LINE_WIDTH_RANGE",                        new QoreBigIntNode(GL_LINE_WIDTH_RANGE));
   opengl_ns.addConstant("GL_LINE_WIDTH_GRANULARITY",                  new QoreBigIntNode(GL_LINE_WIDTH_GRANULARITY));
   opengl_ns.addConstant("GL_LINE_STIPPLE",                            new QoreBigIntNode(GL_LINE_STIPPLE));
   opengl_ns.addConstant("GL_LINE_STIPPLE_PATTERN",                    new QoreBigIntNode(GL_LINE_STIPPLE_PATTERN));
   opengl_ns.addConstant("GL_LINE_STIPPLE_REPEAT",                     new QoreBigIntNode(GL_LINE_STIPPLE_REPEAT));
   opengl_ns.addConstant("GL_LIST_MODE",                               new QoreBigIntNode(GL_LIST_MODE));
   opengl_ns.addConstant("GL_MAX_LIST_NESTING",                        new QoreBigIntNode(GL_MAX_LIST_NESTING));
   opengl_ns.addConstant("GL_LIST_BASE",                               new QoreBigIntNode(GL_LIST_BASE));
   opengl_ns.addConstant("GL_LIST_INDEX",                              new QoreBigIntNode(GL_LIST_INDEX));
   opengl_ns.addConstant("GL_POLYGON_MODE",                            new QoreBigIntNode(GL_POLYGON_MODE));
   opengl_ns.addConstant("GL_POLYGON_SMOOTH",                          new QoreBigIntNode(GL_POLYGON_SMOOTH));
   opengl_ns.addConstant("GL_POLYGON_STIPPLE",                         new QoreBigIntNode(GL_POLYGON_STIPPLE));
   opengl_ns.addConstant("GL_EDGE_FLAG",                               new QoreBigIntNode(GL_EDGE_FLAG));
   opengl_ns.addConstant("GL_CULL_FACE",                               new QoreBigIntNode(GL_CULL_FACE));
   opengl_ns.addConstant("GL_CULL_FACE_MODE",                          new QoreBigIntNode(GL_CULL_FACE_MODE));
   opengl_ns.addConstant("GL_FRONT_FACE",                              new QoreBigIntNode(GL_FRONT_FACE));
   opengl_ns.addConstant("GL_LIGHTING",                                new QoreBigIntNode(GL_LIGHTING));
   opengl_ns.addConstant("GL_LIGHT_MODEL_LOCAL_VIEWER",                new QoreBigIntNode(GL_LIGHT_MODEL_LOCAL_VIEWER));
   opengl_ns.addConstant("GL_LIGHT_MODEL_TWO_SIDE",                    new QoreBigIntNode(GL_LIGHT_MODEL_TWO_SIDE));
   opengl_ns.addConstant("GL_LIGHT_MODEL_AMBIENT",                     new QoreBigIntNode(GL_LIGHT_MODEL_AMBIENT));
   opengl_ns.addConstant("GL_SHADE_MODEL",                             new QoreBigIntNode(GL_SHADE_MODEL));
   opengl_ns.addConstant("GL_COLOR_MATERIAL_FACE",                     new QoreBigIntNode(GL_COLOR_MATERIAL_FACE));
   opengl_ns.addConstant("GL_COLOR_MATERIAL_PARAMETER",                new QoreBigIntNode(GL_COLOR_MATERIAL_PARAMETER));
   opengl_ns.addConstant("GL_COLOR_MATERIAL",                          new QoreBigIntNode(GL_COLOR_MATERIAL));
   opengl_ns.addConstant("GL_FOG",                                     new QoreBigIntNode(GL_FOG));
   opengl_ns.addConstant("GL_FOG_INDEX",                               new QoreBigIntNode(GL_FOG_INDEX));
   opengl_ns.addConstant("GL_FOG_DENSITY",                             new QoreBigIntNode(GL_FOG_DENSITY));
   opengl_ns.addConstant("GL_FOG_START",                               new QoreBigIntNode(GL_FOG_START));
   opengl_ns.addConstant("GL_FOG_END",                                 new QoreBigIntNode(GL_FOG_END));
   opengl_ns.addConstant("GL_FOG_MODE",                                new QoreBigIntNode(GL_FOG_MODE));
   opengl_ns.addConstant("GL_FOG_COLOR",                               new QoreBigIntNode(GL_FOG_COLOR));
   opengl_ns.addConstant("GL_DEPTH_RANGE",                             new QoreBigIntNode(GL_DEPTH_RANGE));
   opengl_ns.addConstant("GL_DEPTH_TEST",                              new QoreBigIntNode(GL_DEPTH_TEST));
   opengl_ns.addConstant("GL_DEPTH_WRITEMASK",                         new QoreBigIntNode(GL_DEPTH_WRITEMASK));
   opengl_ns.addConstant("GL_DEPTH_CLEAR_VALUE",                       new QoreBigIntNode(GL_DEPTH_CLEAR_VALUE));
   opengl_ns.addConstant("GL_DEPTH_FUNC",                              new QoreBigIntNode(GL_DEPTH_FUNC));
   opengl_ns.addConstant("GL_ACCUM_CLEAR_VALUE",                       new QoreBigIntNode(GL_ACCUM_CLEAR_VALUE));
   opengl_ns.addConstant("GL_STENCIL_TEST",                            new QoreBigIntNode(GL_STENCIL_TEST));
   opengl_ns.addConstant("GL_STENCIL_CLEAR_VALUE",                     new QoreBigIntNode(GL_STENCIL_CLEAR_VALUE));
   opengl_ns.addConstant("GL_STENCIL_FUNC",                            new QoreBigIntNode(GL_STENCIL_FUNC));
   opengl_ns.addConstant("GL_STENCIL_VALUE_MASK",                      new QoreBigIntNode(GL_STENCIL_VALUE_MASK));
   opengl_ns.addConstant("GL_STENCIL_FAIL",                            new QoreBigIntNode(GL_STENCIL_FAIL));
   opengl_ns.addConstant("GL_STENCIL_PASS_DEPTH_FAIL",                 new QoreBigIntNode(GL_STENCIL_PASS_DEPTH_FAIL));
   opengl_ns.addConstant("GL_STENCIL_PASS_DEPTH_PASS",                 new QoreBigIntNode(GL_STENCIL_PASS_DEPTH_PASS));
   opengl_ns.addConstant("GL_STENCIL_REF",                             new QoreBigIntNode(GL_STENCIL_REF));
   opengl_ns.addConstant("GL_STENCIL_WRITEMASK",                       new QoreBigIntNode(GL_STENCIL_WRITEMASK));
   opengl_ns.addConstant("GL_MATRIX_MODE",                             new QoreBigIntNode(GL_MATRIX_MODE));
   opengl_ns.addConstant("GL_NORMALIZE",                               new QoreBigIntNode(GL_NORMALIZE));
   opengl_ns.addConstant("GL_VIEWPORT",                                new QoreBigIntNode(GL_VIEWPORT));
   opengl_ns.addConstant("GL_MODELVIEW_STACK_DEPTH",                   new QoreBigIntNode(GL_MODELVIEW_STACK_DEPTH));
   opengl_ns.addConstant("GL_PROJECTION_STACK_DEPTH",                  new QoreBigIntNode(GL_PROJECTION_STACK_DEPTH));
   opengl_ns.addConstant("GL_TEXTURE_STACK_DEPTH",                     new QoreBigIntNode(GL_TEXTURE_STACK_DEPTH));
   opengl_ns.addConstant("GL_MODELVIEW_MATRIX",                        new QoreBigIntNode(GL_MODELVIEW_MATRIX));
   opengl_ns.addConstant("GL_PROJECTION_MATRIX",                       new QoreBigIntNode(GL_PROJECTION_MATRIX));
   opengl_ns.addConstant("GL_TEXTURE_MATRIX",                          new QoreBigIntNode(GL_TEXTURE_MATRIX));
   opengl_ns.addConstant("GL_ATTRIB_STACK_DEPTH",                      new QoreBigIntNode(GL_ATTRIB_STACK_DEPTH));
   opengl_ns.addConstant("GL_CLIENT_ATTRIB_STACK_DEPTH",               new QoreBigIntNode(GL_CLIENT_ATTRIB_STACK_DEPTH));
   opengl_ns.addConstant("GL_ALPHA_TEST",                              new QoreBigIntNode(GL_ALPHA_TEST));
   opengl_ns.addConstant("GL_ALPHA_TEST_FUNC",                         new QoreBigIntNode(GL_ALPHA_TEST_FUNC));
   opengl_ns.addConstant("GL_ALPHA_TEST_REF",                          new QoreBigIntNode(GL_ALPHA_TEST_REF));
   opengl_ns.addConstant("GL_DITHER",                                  new QoreBigIntNode(GL_DITHER));
   opengl_ns.addConstant("GL_BLEND_DST",                               new QoreBigIntNode(GL_BLEND_DST));
   opengl_ns.addConstant("GL_BLEND_SRC",                               new QoreBigIntNode(GL_BLEND_SRC));
   opengl_ns.addConstant("GL_BLEND",                                   new QoreBigIntNode(GL_BLEND));
   opengl_ns.addConstant("GL_LOGIC_OP_MODE",                           new QoreBigIntNode(GL_LOGIC_OP_MODE));
   opengl_ns.addConstant("GL_INDEX_LOGIC_OP",                          new QoreBigIntNode(GL_INDEX_LOGIC_OP));
   opengl_ns.addConstant("GL_COLOR_LOGIC_OP",                          new QoreBigIntNode(GL_COLOR_LOGIC_OP));
   opengl_ns.addConstant("GL_AUX_BUFFERS",                             new QoreBigIntNode(GL_AUX_BUFFERS));
   opengl_ns.addConstant("GL_DRAW_BUFFER",                             new QoreBigIntNode(GL_DRAW_BUFFER));
   opengl_ns.addConstant("GL_READ_BUFFER",                             new QoreBigIntNode(GL_READ_BUFFER));
   opengl_ns.addConstant("GL_SCISSOR_BOX",                             new QoreBigIntNode(GL_SCISSOR_BOX));
   opengl_ns.addConstant("GL_SCISSOR_TEST",                            new QoreBigIntNode(GL_SCISSOR_TEST));
   opengl_ns.addConstant("GL_INDEX_CLEAR_VALUE",                       new QoreBigIntNode(GL_INDEX_CLEAR_VALUE));
   opengl_ns.addConstant("GL_INDEX_WRITEMASK",                         new QoreBigIntNode(GL_INDEX_WRITEMASK));
   opengl_ns.addConstant("GL_COLOR_CLEAR_VALUE",                       new QoreBigIntNode(GL_COLOR_CLEAR_VALUE));
   opengl_ns.addConstant("GL_COLOR_WRITEMASK",                         new QoreBigIntNode(GL_COLOR_WRITEMASK));
   opengl_ns.addConstant("GL_INDEX_MODE",                              new QoreBigIntNode(GL_INDEX_MODE));
   opengl_ns.addConstant("GL_RGBA_MODE",                               new QoreBigIntNode(GL_RGBA_MODE));
   opengl_ns.addConstant("GL_DOUBLEBUFFER",                            new QoreBigIntNode(GL_DOUBLEBUFFER));
   opengl_ns.addConstant("GL_STEREO",                                  new QoreBigIntNode(GL_STEREO));
   opengl_ns.addConstant("GL_RENDER_MODE",                             new QoreBigIntNode(GL_RENDER_MODE));
   opengl_ns.addConstant("GL_PERSPECTIVE_CORRECTION_HINT",             new QoreBigIntNode(GL_PERSPECTIVE_CORRECTION_HINT));
   opengl_ns.addConstant("GL_POINT_SMOOTH_HINT",                       new QoreBigIntNode(GL_POINT_SMOOTH_HINT));
   opengl_ns.addConstant("GL_LINE_SMOOTH_HINT",                        new QoreBigIntNode(GL_LINE_SMOOTH_HINT));
   opengl_ns.addConstant("GL_POLYGON_SMOOTH_HINT",                     new QoreBigIntNode(GL_POLYGON_SMOOTH_HINT));
   opengl_ns.addConstant("GL_FOG_HINT",                                new QoreBigIntNode(GL_FOG_HINT));
   opengl_ns.addConstant("GL_TEXTURE_GEN_S",                           new QoreBigIntNode(GL_TEXTURE_GEN_S));
   opengl_ns.addConstant("GL_TEXTURE_GEN_T",                           new QoreBigIntNode(GL_TEXTURE_GEN_T));
   opengl_ns.addConstant("GL_TEXTURE_GEN_R",                           new QoreBigIntNode(GL_TEXTURE_GEN_R));
   opengl_ns.addConstant("GL_TEXTURE_GEN_Q",                           new QoreBigIntNode(GL_TEXTURE_GEN_Q));
   opengl_ns.addConstant("GL_PIXEL_MAP_I_TO_I",                        new QoreBigIntNode(GL_PIXEL_MAP_I_TO_I));
   opengl_ns.addConstant("GL_PIXEL_MAP_S_TO_S",                        new QoreBigIntNode(GL_PIXEL_MAP_S_TO_S));
   opengl_ns.addConstant("GL_PIXEL_MAP_I_TO_R",                        new QoreBigIntNode(GL_PIXEL_MAP_I_TO_R));
   opengl_ns.addConstant("GL_PIXEL_MAP_I_TO_G",                        new QoreBigIntNode(GL_PIXEL_MAP_I_TO_G));
   opengl_ns.addConstant("GL_PIXEL_MAP_I_TO_B",                        new QoreBigIntNode(GL_PIXEL_MAP_I_TO_B));
   opengl_ns.addConstant("GL_PIXEL_MAP_I_TO_A",                        new QoreBigIntNode(GL_PIXEL_MAP_I_TO_A));
   opengl_ns.addConstant("GL_PIXEL_MAP_R_TO_R",                        new QoreBigIntNode(GL_PIXEL_MAP_R_TO_R));
   opengl_ns.addConstant("GL_PIXEL_MAP_G_TO_G",                        new QoreBigIntNode(GL_PIXEL_MAP_G_TO_G));
   opengl_ns.addConstant("GL_PIXEL_MAP_B_TO_B",                        new QoreBigIntNode(GL_PIXEL_MAP_B_TO_B));
   opengl_ns.addConstant("GL_PIXEL_MAP_A_TO_A",                        new QoreBigIntNode(GL_PIXEL_MAP_A_TO_A));
   opengl_ns.addConstant("GL_PIXEL_MAP_I_TO_I_SIZE",                   new QoreBigIntNode(GL_PIXEL_MAP_I_TO_I_SIZE));
   opengl_ns.addConstant("GL_PIXEL_MAP_S_TO_S_SIZE",                   new QoreBigIntNode(GL_PIXEL_MAP_S_TO_S_SIZE));
   opengl_ns.addConstant("GL_PIXEL_MAP_I_TO_R_SIZE",                   new QoreBigIntNode(GL_PIXEL_MAP_I_TO_R_SIZE));
   opengl_ns.addConstant("GL_PIXEL_MAP_I_TO_G_SIZE",                   new QoreBigIntNode(GL_PIXEL_MAP_I_TO_G_SIZE));
   opengl_ns.addConstant("GL_PIXEL_MAP_I_TO_B_SIZE",                   new QoreBigIntNode(GL_PIXEL_MAP_I_TO_B_SIZE));
   opengl_ns.addConstant("GL_PIXEL_MAP_I_TO_A_SIZE",                   new QoreBigIntNode(GL_PIXEL_MAP_I_TO_A_SIZE));
   opengl_ns.addConstant("GL_PIXEL_MAP_R_TO_R_SIZE",                   new QoreBigIntNode(GL_PIXEL_MAP_R_TO_R_SIZE));
   opengl_ns.addConstant("GL_PIXEL_MAP_G_TO_G_SIZE",                   new QoreBigIntNode(GL_PIXEL_MAP_G_TO_G_SIZE));
   opengl_ns.addConstant("GL_PIXEL_MAP_B_TO_B_SIZE",                   new QoreBigIntNode(GL_PIXEL_MAP_B_TO_B_SIZE));
   opengl_ns.addConstant("GL_PIXEL_MAP_A_TO_A_SIZE",                   new QoreBigIntNode(GL_PIXEL_MAP_A_TO_A_SIZE));
   opengl_ns.addConstant("GL_UNPACK_SWAP_BYTES",                       new QoreBigIntNode(GL_UNPACK_SWAP_BYTES));
   opengl_ns.addConstant("GL_UNPACK_LSB_FIRST",                        new QoreBigIntNode(GL_UNPACK_LSB_FIRST));
   opengl_ns.addConstant("GL_UNPACK_ROW_LENGTH",                       new QoreBigIntNode(GL_UNPACK_ROW_LENGTH));
   opengl_ns.addConstant("GL_UNPACK_SKIP_ROWS",                        new QoreBigIntNode(GL_UNPACK_SKIP_ROWS));
   opengl_ns.addConstant("GL_UNPACK_SKIP_PIXELS",                      new QoreBigIntNode(GL_UNPACK_SKIP_PIXELS));
   opengl_ns.addConstant("GL_UNPACK_ALIGNMENT",                        new QoreBigIntNode(GL_UNPACK_ALIGNMENT));
   opengl_ns.addConstant("GL_PACK_SWAP_BYTES",                         new QoreBigIntNode(GL_PACK_SWAP_BYTES));
   opengl_ns.addConstant("GL_PACK_LSB_FIRST",                          new QoreBigIntNode(GL_PACK_LSB_FIRST));
   opengl_ns.addConstant("GL_PACK_ROW_LENGTH",                         new QoreBigIntNode(GL_PACK_ROW_LENGTH));
   opengl_ns.addConstant("GL_PACK_SKIP_ROWS",                          new QoreBigIntNode(GL_PACK_SKIP_ROWS));
   opengl_ns.addConstant("GL_PACK_SKIP_PIXELS",                        new QoreBigIntNode(GL_PACK_SKIP_PIXELS));
   opengl_ns.addConstant("GL_PACK_ALIGNMENT",                          new QoreBigIntNode(GL_PACK_ALIGNMENT));
   opengl_ns.addConstant("GL_MAP_COLOR",                               new QoreBigIntNode(GL_MAP_COLOR));
   opengl_ns.addConstant("GL_MAP_STENCIL",                             new QoreBigIntNode(GL_MAP_STENCIL));
   opengl_ns.addConstant("GL_INDEX_SHIFT",                             new QoreBigIntNode(GL_INDEX_SHIFT));
   opengl_ns.addConstant("GL_INDEX_OFFSET",                            new QoreBigIntNode(GL_INDEX_OFFSET));
   opengl_ns.addConstant("GL_RED_SCALE",                               new QoreBigIntNode(GL_RED_SCALE));
   opengl_ns.addConstant("GL_RED_BIAS",                                new QoreBigIntNode(GL_RED_BIAS));
   opengl_ns.addConstant("GL_ZOOM_X",                                  new QoreBigIntNode(GL_ZOOM_X));
   opengl_ns.addConstant("GL_ZOOM_Y",                                  new QoreBigIntNode(GL_ZOOM_Y));
   opengl_ns.addConstant("GL_GREEN_SCALE",                             new QoreBigIntNode(GL_GREEN_SCALE));
   opengl_ns.addConstant("GL_GREEN_BIAS",                              new QoreBigIntNode(GL_GREEN_BIAS));
   opengl_ns.addConstant("GL_BLUE_SCALE",                              new QoreBigIntNode(GL_BLUE_SCALE));
   opengl_ns.addConstant("GL_BLUE_BIAS",                               new QoreBigIntNode(GL_BLUE_BIAS));
   opengl_ns.addConstant("GL_ALPHA_SCALE",                             new QoreBigIntNode(GL_ALPHA_SCALE));
   opengl_ns.addConstant("GL_ALPHA_BIAS",                              new QoreBigIntNode(GL_ALPHA_BIAS));
   opengl_ns.addConstant("GL_DEPTH_SCALE",                             new QoreBigIntNode(GL_DEPTH_SCALE));
   opengl_ns.addConstant("GL_DEPTH_BIAS",                              new QoreBigIntNode(GL_DEPTH_BIAS));
   opengl_ns.addConstant("GL_MAX_EVAL_ORDER",                          new QoreBigIntNode(GL_MAX_EVAL_ORDER));
   opengl_ns.addConstant("GL_MAX_LIGHTS",                              new QoreBigIntNode(GL_MAX_LIGHTS));
   opengl_ns.addConstant("GL_MAX_CLIP_PLANES",                         new QoreBigIntNode(GL_MAX_CLIP_PLANES));
   opengl_ns.addConstant("GL_MAX_TEXTURE_SIZE",                        new QoreBigIntNode(GL_MAX_TEXTURE_SIZE));
   opengl_ns.addConstant("GL_MAX_PIXEL_MAP_TABLE",                     new QoreBigIntNode(GL_MAX_PIXEL_MAP_TABLE));
   opengl_ns.addConstant("GL_MAX_ATTRIB_STACK_DEPTH",                  new QoreBigIntNode(GL_MAX_ATTRIB_STACK_DEPTH));
   opengl_ns.addConstant("GL_MAX_MODELVIEW_STACK_DEPTH",               new QoreBigIntNode(GL_MAX_MODELVIEW_STACK_DEPTH));
   opengl_ns.addConstant("GL_MAX_NAME_STACK_DEPTH",                    new QoreBigIntNode(GL_MAX_NAME_STACK_DEPTH));
   opengl_ns.addConstant("GL_MAX_PROJECTION_STACK_DEPTH",              new QoreBigIntNode(GL_MAX_PROJECTION_STACK_DEPTH));
   opengl_ns.addConstant("GL_MAX_TEXTURE_STACK_DEPTH",                 new QoreBigIntNode(GL_MAX_TEXTURE_STACK_DEPTH));
   opengl_ns.addConstant("GL_MAX_VIEWPORT_DIMS",                       new QoreBigIntNode(GL_MAX_VIEWPORT_DIMS));
   opengl_ns.addConstant("GL_MAX_CLIENT_ATTRIB_STACK_DEPTH",           new QoreBigIntNode(GL_MAX_CLIENT_ATTRIB_STACK_DEPTH));
   opengl_ns.addConstant("GL_SUBPIXEL_BITS",                           new QoreBigIntNode(GL_SUBPIXEL_BITS));
   opengl_ns.addConstant("GL_INDEX_BITS",                              new QoreBigIntNode(GL_INDEX_BITS));
   opengl_ns.addConstant("GL_RED_BITS",                                new QoreBigIntNode(GL_RED_BITS));
   opengl_ns.addConstant("GL_GREEN_BITS",                              new QoreBigIntNode(GL_GREEN_BITS));
   opengl_ns.addConstant("GL_BLUE_BITS",                               new QoreBigIntNode(GL_BLUE_BITS));
   opengl_ns.addConstant("GL_ALPHA_BITS",                              new QoreBigIntNode(GL_ALPHA_BITS));
   opengl_ns.addConstant("GL_DEPTH_BITS",                              new QoreBigIntNode(GL_DEPTH_BITS));
   opengl_ns.addConstant("GL_STENCIL_BITS",                            new QoreBigIntNode(GL_STENCIL_BITS));
   opengl_ns.addConstant("GL_ACCUM_RED_BITS",                          new QoreBigIntNode(GL_ACCUM_RED_BITS));
   opengl_ns.addConstant("GL_ACCUM_GREEN_BITS",                        new QoreBigIntNode(GL_ACCUM_GREEN_BITS));
   opengl_ns.addConstant("GL_ACCUM_BLUE_BITS",                         new QoreBigIntNode(GL_ACCUM_BLUE_BITS));
   opengl_ns.addConstant("GL_ACCUM_ALPHA_BITS",                        new QoreBigIntNode(GL_ACCUM_ALPHA_BITS));
   opengl_ns.addConstant("GL_NAME_STACK_DEPTH",                        new QoreBigIntNode(GL_NAME_STACK_DEPTH));
   opengl_ns.addConstant("GL_AUTO_NORMAL",                             new QoreBigIntNode(GL_AUTO_NORMAL));
   opengl_ns.addConstant("GL_MAP1_COLOR_4",                            new QoreBigIntNode(GL_MAP1_COLOR_4));
   opengl_ns.addConstant("GL_MAP1_INDEX",                              new QoreBigIntNode(GL_MAP1_INDEX));
   opengl_ns.addConstant("GL_MAP1_NORMAL",                             new QoreBigIntNode(GL_MAP1_NORMAL));
   opengl_ns.addConstant("GL_MAP1_TEXTURE_COORD_1",                    new QoreBigIntNode(GL_MAP1_TEXTURE_COORD_1));
   opengl_ns.addConstant("GL_MAP1_TEXTURE_COORD_2",                    new QoreBigIntNode(GL_MAP1_TEXTURE_COORD_2));
   opengl_ns.addConstant("GL_MAP1_TEXTURE_COORD_3",                    new QoreBigIntNode(GL_MAP1_TEXTURE_COORD_3));
   opengl_ns.addConstant("GL_MAP1_TEXTURE_COORD_4",                    new QoreBigIntNode(GL_MAP1_TEXTURE_COORD_4));
   opengl_ns.addConstant("GL_MAP1_VERTEX_3",                           new QoreBigIntNode(GL_MAP1_VERTEX_3));
   opengl_ns.addConstant("GL_MAP1_VERTEX_4",                           new QoreBigIntNode(GL_MAP1_VERTEX_4));
   opengl_ns.addConstant("GL_MAP2_COLOR_4",                            new QoreBigIntNode(GL_MAP2_COLOR_4));
   opengl_ns.addConstant("GL_MAP2_INDEX",                              new QoreBigIntNode(GL_MAP2_INDEX));
   opengl_ns.addConstant("GL_MAP2_NORMAL",                             new QoreBigIntNode(GL_MAP2_NORMAL));
   opengl_ns.addConstant("GL_MAP2_TEXTURE_COORD_1",                    new QoreBigIntNode(GL_MAP2_TEXTURE_COORD_1));
   opengl_ns.addConstant("GL_MAP2_TEXTURE_COORD_2",                    new QoreBigIntNode(GL_MAP2_TEXTURE_COORD_2));
   opengl_ns.addConstant("GL_MAP2_TEXTURE_COORD_3",                    new QoreBigIntNode(GL_MAP2_TEXTURE_COORD_3));
   opengl_ns.addConstant("GL_MAP2_TEXTURE_COORD_4",                    new QoreBigIntNode(GL_MAP2_TEXTURE_COORD_4));
   opengl_ns.addConstant("GL_MAP2_VERTEX_3",                           new QoreBigIntNode(GL_MAP2_VERTEX_3));
   opengl_ns.addConstant("GL_MAP2_VERTEX_4",                           new QoreBigIntNode(GL_MAP2_VERTEX_4));
   opengl_ns.addConstant("GL_MAP1_GRID_DOMAIN",                        new QoreBigIntNode(GL_MAP1_GRID_DOMAIN));
   opengl_ns.addConstant("GL_MAP1_GRID_SEGMENTS",                      new QoreBigIntNode(GL_MAP1_GRID_SEGMENTS));
   opengl_ns.addConstant("GL_MAP2_GRID_DOMAIN",                        new QoreBigIntNode(GL_MAP2_GRID_DOMAIN));
   opengl_ns.addConstant("GL_MAP2_GRID_SEGMENTS",                      new QoreBigIntNode(GL_MAP2_GRID_SEGMENTS));
   opengl_ns.addConstant("GL_TEXTURE_1D",                              new QoreBigIntNode(GL_TEXTURE_1D));
   opengl_ns.addConstant("GL_TEXTURE_2D",                              new QoreBigIntNode(GL_TEXTURE_2D));
   opengl_ns.addConstant("GL_FEEDBACK_BUFFER_POINTER",                 new QoreBigIntNode(GL_FEEDBACK_BUFFER_POINTER));
   opengl_ns.addConstant("GL_FEEDBACK_BUFFER_SIZE",                    new QoreBigIntNode(GL_FEEDBACK_BUFFER_SIZE));
   opengl_ns.addConstant("GL_FEEDBACK_BUFFER_TYPE",                    new QoreBigIntNode(GL_FEEDBACK_BUFFER_TYPE));
   opengl_ns.addConstant("GL_SELECTION_BUFFER_POINTER",                new QoreBigIntNode(GL_SELECTION_BUFFER_POINTER));
   opengl_ns.addConstant("GL_SELECTION_BUFFER_SIZE",                   new QoreBigIntNode(GL_SELECTION_BUFFER_SIZE));
   opengl_ns.addConstant("GL_TEXTURE_WIDTH",                           new QoreBigIntNode(GL_TEXTURE_WIDTH));
   opengl_ns.addConstant("GL_TEXTURE_HEIGHT",                          new QoreBigIntNode(GL_TEXTURE_HEIGHT));
   opengl_ns.addConstant("GL_TEXTURE_INTERNAL_FORMAT",                 new QoreBigIntNode(GL_TEXTURE_INTERNAL_FORMAT));
   opengl_ns.addConstant("GL_TEXTURE_BORDER_COLOR",                    new QoreBigIntNode(GL_TEXTURE_BORDER_COLOR));
   opengl_ns.addConstant("GL_TEXTURE_BORDER",                          new QoreBigIntNode(GL_TEXTURE_BORDER));
   opengl_ns.addConstant("GL_DONT_CARE",                               new QoreBigIntNode(GL_DONT_CARE));
   opengl_ns.addConstant("GL_FASTEST",                                 new QoreBigIntNode(GL_FASTEST));
   opengl_ns.addConstant("GL_NICEST",                                  new QoreBigIntNode(GL_NICEST));
   opengl_ns.addConstant("GL_LIGHT0",                                  new QoreBigIntNode(GL_LIGHT0));
   opengl_ns.addConstant("GL_LIGHT1",                                  new QoreBigIntNode(GL_LIGHT1));
   opengl_ns.addConstant("GL_LIGHT2",                                  new QoreBigIntNode(GL_LIGHT2));
   opengl_ns.addConstant("GL_LIGHT3",                                  new QoreBigIntNode(GL_LIGHT3));
   opengl_ns.addConstant("GL_LIGHT4",                                  new QoreBigIntNode(GL_LIGHT4));
   opengl_ns.addConstant("GL_LIGHT5",                                  new QoreBigIntNode(GL_LIGHT5));
   opengl_ns.addConstant("GL_LIGHT6",                                  new QoreBigIntNode(GL_LIGHT6));
   opengl_ns.addConstant("GL_LIGHT7",                                  new QoreBigIntNode(GL_LIGHT7));
   opengl_ns.addConstant("GL_AMBIENT",                                 new QoreBigIntNode(GL_AMBIENT));
   opengl_ns.addConstant("GL_DIFFUSE",                                 new QoreBigIntNode(GL_DIFFUSE));
   opengl_ns.addConstant("GL_SPECULAR",                                new QoreBigIntNode(GL_SPECULAR));
   opengl_ns.addConstant("GL_POSITION",                                new QoreBigIntNode(GL_POSITION));
   opengl_ns.addConstant("GL_SPOT_DIRECTION",                          new QoreBigIntNode(GL_SPOT_DIRECTION));
   opengl_ns.addConstant("GL_SPOT_EXPONENT",                           new QoreBigIntNode(GL_SPOT_EXPONENT));
   opengl_ns.addConstant("GL_SPOT_CUTOFF",                             new QoreBigIntNode(GL_SPOT_CUTOFF));
   opengl_ns.addConstant("GL_CONSTANT_ATTENUATION",                    new QoreBigIntNode(GL_CONSTANT_ATTENUATION));
   opengl_ns.addConstant("GL_LINEAR_ATTENUATION",                      new QoreBigIntNode(GL_LINEAR_ATTENUATION));
   opengl_ns.addConstant("GL_QUADRATIC_ATTENUATION",                   new QoreBigIntNode(GL_QUADRATIC_ATTENUATION));
   opengl_ns.addConstant("GL_COMPILE",                                 new QoreBigIntNode(GL_COMPILE));
   opengl_ns.addConstant("GL_COMPILE_AND_EXECUTE",                     new QoreBigIntNode(GL_COMPILE_AND_EXECUTE));
   opengl_ns.addConstant("GL_CLEAR",                                   new QoreBigIntNode(GL_CLEAR));
   opengl_ns.addConstant("GL_AND",                                     new QoreBigIntNode(GL_AND));
   opengl_ns.addConstant("GL_AND_REVERSE",                             new QoreBigIntNode(GL_AND_REVERSE));
   opengl_ns.addConstant("GL_COPY",                                    new QoreBigIntNode(GL_COPY));
   opengl_ns.addConstant("GL_AND_INVERTED",                            new QoreBigIntNode(GL_AND_INVERTED));
   opengl_ns.addConstant("GL_NOOP",                                    new QoreBigIntNode(GL_NOOP));
   opengl_ns.addConstant("GL_XOR",                                     new QoreBigIntNode(GL_XOR));
   opengl_ns.addConstant("GL_OR",                                      new QoreBigIntNode(GL_OR));
   opengl_ns.addConstant("GL_NOR",                                     new QoreBigIntNode(GL_NOR));
   opengl_ns.addConstant("GL_EQUIV",                                   new QoreBigIntNode(GL_EQUIV));
   opengl_ns.addConstant("GL_INVERT",                                  new QoreBigIntNode(GL_INVERT));
   opengl_ns.addConstant("GL_OR_REVERSE",                              new QoreBigIntNode(GL_OR_REVERSE));
   opengl_ns.addConstant("GL_COPY_INVERTED",                           new QoreBigIntNode(GL_COPY_INVERTED));
   opengl_ns.addConstant("GL_OR_INVERTED",                             new QoreBigIntNode(GL_OR_INVERTED));
   opengl_ns.addConstant("GL_NAND",                                    new QoreBigIntNode(GL_NAND));
   opengl_ns.addConstant("GL_SET",                                     new QoreBigIntNode(GL_SET));
   opengl_ns.addConstant("GL_EMISSION",                                new QoreBigIntNode(GL_EMISSION));
   opengl_ns.addConstant("GL_SHININESS",                               new QoreBigIntNode(GL_SHININESS));
   opengl_ns.addConstant("GL_AMBIENT_AND_DIFFUSE",                     new QoreBigIntNode(GL_AMBIENT_AND_DIFFUSE));
   opengl_ns.addConstant("GL_COLOR_INDEXES",                           new QoreBigIntNode(GL_COLOR_INDEXES));
   opengl_ns.addConstant("GL_MODELVIEW",                               new QoreBigIntNode(GL_MODELVIEW));
   opengl_ns.addConstant("GL_PROJECTION",                              new QoreBigIntNode(GL_PROJECTION));
   opengl_ns.addConstant("GL_TEXTURE",                                 new QoreBigIntNode(GL_TEXTURE));
   opengl_ns.addConstant("GL_COLOR",                                   new QoreBigIntNode(GL_COLOR));
   opengl_ns.addConstant("GL_DEPTH",                                   new QoreBigIntNode(GL_DEPTH));
   opengl_ns.addConstant("GL_STENCIL",                                 new QoreBigIntNode(GL_STENCIL));
   opengl_ns.addConstant("GL_COLOR_INDEX",                             new QoreBigIntNode(GL_COLOR_INDEX));
   opengl_ns.addConstant("GL_STENCIL_INDEX",                           new QoreBigIntNode(GL_STENCIL_INDEX));
   opengl_ns.addConstant("GL_DEPTH_COMPONENT",                         new QoreBigIntNode(GL_DEPTH_COMPONENT));
   opengl_ns.addConstant("GL_RED",                                     new QoreBigIntNode(GL_RED));
   opengl_ns.addConstant("GL_GREEN",                                   new QoreBigIntNode(GL_GREEN));
   opengl_ns.addConstant("GL_BLUE",                                    new QoreBigIntNode(GL_BLUE));
   opengl_ns.addConstant("GL_ALPHA",                                   new QoreBigIntNode(GL_ALPHA));
   opengl_ns.addConstant("GL_RGB",                                     new QoreBigIntNode(GL_RGB));
   opengl_ns.addConstant("GL_RGBA",                                    new QoreBigIntNode(GL_RGBA));
   opengl_ns.addConstant("GL_LUMINANCE",                               new QoreBigIntNode(GL_LUMINANCE));
   opengl_ns.addConstant("GL_LUMINANCE_ALPHA",                         new QoreBigIntNode(GL_LUMINANCE_ALPHA));
   opengl_ns.addConstant("GL_BITMAP",                                  new QoreBigIntNode(GL_BITMAP));
   opengl_ns.addConstant("GL_POINT",                                   new QoreBigIntNode(GL_POINT));
   opengl_ns.addConstant("GL_LINE",                                    new QoreBigIntNode(GL_LINE));
   opengl_ns.addConstant("GL_FILL",                                    new QoreBigIntNode(GL_FILL));
   opengl_ns.addConstant("GL_RENDER",                                  new QoreBigIntNode(GL_RENDER));
   opengl_ns.addConstant("GL_FEEDBACK",                                new QoreBigIntNode(GL_FEEDBACK));
   opengl_ns.addConstant("GL_SELECT",                                  new QoreBigIntNode(GL_SELECT));
   opengl_ns.addConstant("GL_FLAT",                                    new QoreBigIntNode(GL_FLAT));
   opengl_ns.addConstant("GL_SMOOTH",                                  new QoreBigIntNode(GL_SMOOTH));
   opengl_ns.addConstant("GL_KEEP",                                    new QoreBigIntNode(GL_KEEP));
   opengl_ns.addConstant("GL_REPLACE",                                 new QoreBigIntNode(GL_REPLACE));
   opengl_ns.addConstant("GL_INCR",                                    new QoreBigIntNode(GL_INCR));
   opengl_ns.addConstant("GL_DECR",                                    new QoreBigIntNode(GL_DECR));
   opengl_ns.addConstant("GL_VENDOR",                                  new QoreBigIntNode(GL_VENDOR));
   opengl_ns.addConstant("GL_RENDERER",                                new QoreBigIntNode(GL_RENDERER));
   opengl_ns.addConstant("GL_VERSION",                                 new QoreBigIntNode(GL_VERSION));
   opengl_ns.addConstant("GL_EXTENSIONS",                              new QoreBigIntNode(GL_EXTENSIONS));
   opengl_ns.addConstant("GL_S",                                       new QoreBigIntNode(GL_S));
   opengl_ns.addConstant("GL_T",                                       new QoreBigIntNode(GL_T));
   opengl_ns.addConstant("GL_R",                                       new QoreBigIntNode(GL_R));
   opengl_ns.addConstant("GL_Q",                                       new QoreBigIntNode(GL_Q));
   opengl_ns.addConstant("GL_MODULATE",                                new QoreBigIntNode(GL_MODULATE));
   opengl_ns.addConstant("GL_DECAL",                                   new QoreBigIntNode(GL_DECAL));
   opengl_ns.addConstant("GL_TEXTURE_ENV_MODE",                        new QoreBigIntNode(GL_TEXTURE_ENV_MODE));
   opengl_ns.addConstant("GL_TEXTURE_ENV_COLOR",                       new QoreBigIntNode(GL_TEXTURE_ENV_COLOR));
   opengl_ns.addConstant("GL_TEXTURE_ENV",                             new QoreBigIntNode(GL_TEXTURE_ENV));
   opengl_ns.addConstant("GL_EYE_LINEAR",                              new QoreBigIntNode(GL_EYE_LINEAR));
   opengl_ns.addConstant("GL_OBJECT_LINEAR",                           new QoreBigIntNode(GL_OBJECT_LINEAR));
   opengl_ns.addConstant("GL_SPHERE_MAP",                              new QoreBigIntNode(GL_SPHERE_MAP));
   opengl_ns.addConstant("GL_TEXTURE_GEN_MODE",                        new QoreBigIntNode(GL_TEXTURE_GEN_MODE));
   opengl_ns.addConstant("GL_OBJECT_PLANE",                            new QoreBigIntNode(GL_OBJECT_PLANE));
   opengl_ns.addConstant("GL_EYE_PLANE",                               new QoreBigIntNode(GL_EYE_PLANE));
   opengl_ns.addConstant("GL_NEAREST",                                 new QoreBigIntNode(GL_NEAREST));
   opengl_ns.addConstant("GL_LINEAR",                                  new QoreBigIntNode(GL_LINEAR));
   opengl_ns.addConstant("GL_NEAREST_MIPMAP_NEAREST",                  new QoreBigIntNode(GL_NEAREST_MIPMAP_NEAREST));
   opengl_ns.addConstant("GL_LINEAR_MIPMAP_NEAREST",                   new QoreBigIntNode(GL_LINEAR_MIPMAP_NEAREST));
   opengl_ns.addConstant("GL_NEAREST_MIPMAP_LINEAR",                   new QoreBigIntNode(GL_NEAREST_MIPMAP_LINEAR));
   opengl_ns.addConstant("GL_LINEAR_MIPMAP_LINEAR",                    new QoreBigIntNode(GL_LINEAR_MIPMAP_LINEAR));
   opengl_ns.addConstant("GL_TEXTURE_MAG_FILTER",                      new QoreBigIntNode(GL_TEXTURE_MAG_FILTER));
   opengl_ns.addConstant("GL_TEXTURE_MIN_FILTER",                      new QoreBigIntNode(GL_TEXTURE_MIN_FILTER));
   opengl_ns.addConstant("GL_TEXTURE_WRAP_S",                          new QoreBigIntNode(GL_TEXTURE_WRAP_S));
   opengl_ns.addConstant("GL_TEXTURE_WRAP_T",                          new QoreBigIntNode(GL_TEXTURE_WRAP_T));
   opengl_ns.addConstant("GL_CLAMP",                                   new QoreBigIntNode(GL_CLAMP));
   opengl_ns.addConstant("GL_REPEAT",                                  new QoreBigIntNode(GL_REPEAT));
   opengl_ns.addConstant("GL_CLIENT_PIXEL_STORE_BIT",                  new QoreBigIntNode(GL_CLIENT_PIXEL_STORE_BIT));
   opengl_ns.addConstant("GL_CLIENT_VERTEX_ARRAY_BIT",                 new QoreBigIntNode(GL_CLIENT_VERTEX_ARRAY_BIT));
   opengl_ns.addConstant("GL_CLIENT_ALL_ATTRIB_BITS",                  new QoreBigIntNode(GL_CLIENT_ALL_ATTRIB_BITS));
   opengl_ns.addConstant("GL_POLYGON_OFFSET_FACTOR",                   new QoreBigIntNode(GL_POLYGON_OFFSET_FACTOR));
   opengl_ns.addConstant("GL_POLYGON_OFFSET_UNITS",                    new QoreBigIntNode(GL_POLYGON_OFFSET_UNITS));
   opengl_ns.addConstant("GL_POLYGON_OFFSET_POINT",                    new QoreBigIntNode(GL_POLYGON_OFFSET_POINT));
   opengl_ns.addConstant("GL_POLYGON_OFFSET_LINE",                     new QoreBigIntNode(GL_POLYGON_OFFSET_LINE));
   opengl_ns.addConstant("GL_POLYGON_OFFSET_FILL",                     new QoreBigIntNode(GL_POLYGON_OFFSET_FILL));
   opengl_ns.addConstant("GL_ALPHA4",                                  new QoreBigIntNode(GL_ALPHA4));
   opengl_ns.addConstant("GL_ALPHA8",                                  new QoreBigIntNode(GL_ALPHA8));
   opengl_ns.addConstant("GL_ALPHA12",                                 new QoreBigIntNode(GL_ALPHA12));
   opengl_ns.addConstant("GL_ALPHA16",                                 new QoreBigIntNode(GL_ALPHA16));
   opengl_ns.addConstant("GL_LUMINANCE4",                              new QoreBigIntNode(GL_LUMINANCE4));
   opengl_ns.addConstant("GL_LUMINANCE8",                              new QoreBigIntNode(GL_LUMINANCE8));
   opengl_ns.addConstant("GL_LUMINANCE12",                             new QoreBigIntNode(GL_LUMINANCE12));
   opengl_ns.addConstant("GL_LUMINANCE16",                             new QoreBigIntNode(GL_LUMINANCE16));
   opengl_ns.addConstant("GL_LUMINANCE4_ALPHA4",                       new QoreBigIntNode(GL_LUMINANCE4_ALPHA4));
   opengl_ns.addConstant("GL_LUMINANCE6_ALPHA2",                       new QoreBigIntNode(GL_LUMINANCE6_ALPHA2));
   opengl_ns.addConstant("GL_LUMINANCE8_ALPHA8",                       new QoreBigIntNode(GL_LUMINANCE8_ALPHA8));
   opengl_ns.addConstant("GL_LUMINANCE12_ALPHA4",                      new QoreBigIntNode(GL_LUMINANCE12_ALPHA4));
   opengl_ns.addConstant("GL_LUMINANCE12_ALPHA12",                     new QoreBigIntNode(GL_LUMINANCE12_ALPHA12));
   opengl_ns.addConstant("GL_LUMINANCE16_ALPHA16",                     new QoreBigIntNode(GL_LUMINANCE16_ALPHA16));
   opengl_ns.addConstant("GL_INTENSITY",                               new QoreBigIntNode(GL_INTENSITY));
   opengl_ns.addConstant("GL_INTENSITY4",                              new QoreBigIntNode(GL_INTENSITY4));
   opengl_ns.addConstant("GL_INTENSITY8",                              new QoreBigIntNode(GL_INTENSITY8));
   opengl_ns.addConstant("GL_INTENSITY12",                             new QoreBigIntNode(GL_INTENSITY12));
   opengl_ns.addConstant("GL_INTENSITY16",                             new QoreBigIntNode(GL_INTENSITY16));
   opengl_ns.addConstant("GL_R3_G3_B2",                                new QoreBigIntNode(GL_R3_G3_B2));
   opengl_ns.addConstant("GL_RGB4",                                    new QoreBigIntNode(GL_RGB4));
   opengl_ns.addConstant("GL_RGB5",                                    new QoreBigIntNode(GL_RGB5));
   opengl_ns.addConstant("GL_RGB8",                                    new QoreBigIntNode(GL_RGB8));
   opengl_ns.addConstant("GL_RGB10",                                   new QoreBigIntNode(GL_RGB10));
   opengl_ns.addConstant("GL_RGB12",                                   new QoreBigIntNode(GL_RGB12));
   opengl_ns.addConstant("GL_RGB16",                                   new QoreBigIntNode(GL_RGB16));
   opengl_ns.addConstant("GL_RGBA2",                                   new QoreBigIntNode(GL_RGBA2));
   opengl_ns.addConstant("GL_RGBA4",                                   new QoreBigIntNode(GL_RGBA4));
   opengl_ns.addConstant("GL_RGB5_A1",                                 new QoreBigIntNode(GL_RGB5_A1));
   opengl_ns.addConstant("GL_RGBA8",                                   new QoreBigIntNode(GL_RGBA8));
   opengl_ns.addConstant("GL_RGB10_A2",                                new QoreBigIntNode(GL_RGB10_A2));
   opengl_ns.addConstant("GL_RGBA12",                                  new QoreBigIntNode(GL_RGBA12));
   opengl_ns.addConstant("GL_RGBA16",                                  new QoreBigIntNode(GL_RGBA16));
   opengl_ns.addConstant("GL_TEXTURE_RED_SIZE",                        new QoreBigIntNode(GL_TEXTURE_RED_SIZE));
   opengl_ns.addConstant("GL_TEXTURE_GREEN_SIZE",                      new QoreBigIntNode(GL_TEXTURE_GREEN_SIZE));
   opengl_ns.addConstant("GL_TEXTURE_BLUE_SIZE",                       new QoreBigIntNode(GL_TEXTURE_BLUE_SIZE));
   opengl_ns.addConstant("GL_TEXTURE_ALPHA_SIZE",                      new QoreBigIntNode(GL_TEXTURE_ALPHA_SIZE));
   opengl_ns.addConstant("GL_TEXTURE_LUMINANCE_SIZE",                  new QoreBigIntNode(GL_TEXTURE_LUMINANCE_SIZE));
   opengl_ns.addConstant("GL_TEXTURE_INTENSITY_SIZE",                  new QoreBigIntNode(GL_TEXTURE_INTENSITY_SIZE));
   opengl_ns.addConstant("GL_PROXY_TEXTURE_1D",                        new QoreBigIntNode(GL_PROXY_TEXTURE_1D));
   opengl_ns.addConstant("GL_PROXY_TEXTURE_2D",                        new QoreBigIntNode(GL_PROXY_TEXTURE_2D));
   opengl_ns.addConstant("GL_TEXTURE_PRIORITY",                        new QoreBigIntNode(GL_TEXTURE_PRIORITY));
   opengl_ns.addConstant("GL_TEXTURE_RESIDENT",                        new QoreBigIntNode(GL_TEXTURE_RESIDENT));
   opengl_ns.addConstant("GL_TEXTURE_BINDING_1D",                      new QoreBigIntNode(GL_TEXTURE_BINDING_1D));
   opengl_ns.addConstant("GL_TEXTURE_BINDING_2D",                      new QoreBigIntNode(GL_TEXTURE_BINDING_2D));
   opengl_ns.addConstant("GL_TEXTURE_BINDING_3D",                      new QoreBigIntNode(GL_TEXTURE_BINDING_3D));
   opengl_ns.addConstant("GL_VERTEX_ARRAY",                            new QoreBigIntNode(GL_VERTEX_ARRAY));
   opengl_ns.addConstant("GL_NORMAL_ARRAY",                            new QoreBigIntNode(GL_NORMAL_ARRAY));
   opengl_ns.addConstant("GL_COLOR_ARRAY",                             new QoreBigIntNode(GL_COLOR_ARRAY));
   opengl_ns.addConstant("GL_INDEX_ARRAY",                             new QoreBigIntNode(GL_INDEX_ARRAY));
   opengl_ns.addConstant("GL_TEXTURE_COORD_ARRAY",                     new QoreBigIntNode(GL_TEXTURE_COORD_ARRAY));
   opengl_ns.addConstant("GL_EDGE_FLAG_ARRAY",                         new QoreBigIntNode(GL_EDGE_FLAG_ARRAY));
   opengl_ns.addConstant("GL_VERTEX_ARRAY_SIZE",                       new QoreBigIntNode(GL_VERTEX_ARRAY_SIZE));
   opengl_ns.addConstant("GL_VERTEX_ARRAY_TYPE",                       new QoreBigIntNode(GL_VERTEX_ARRAY_TYPE));
   opengl_ns.addConstant("GL_VERTEX_ARRAY_STRIDE",                     new QoreBigIntNode(GL_VERTEX_ARRAY_STRIDE));
   opengl_ns.addConstant("GL_NORMAL_ARRAY_TYPE",                       new QoreBigIntNode(GL_NORMAL_ARRAY_TYPE));
   opengl_ns.addConstant("GL_NORMAL_ARRAY_STRIDE",                     new QoreBigIntNode(GL_NORMAL_ARRAY_STRIDE));
   opengl_ns.addConstant("GL_COLOR_ARRAY_SIZE",                        new QoreBigIntNode(GL_COLOR_ARRAY_SIZE));
   opengl_ns.addConstant("GL_COLOR_ARRAY_TYPE",                        new QoreBigIntNode(GL_COLOR_ARRAY_TYPE));
   opengl_ns.addConstant("GL_COLOR_ARRAY_STRIDE",                      new QoreBigIntNode(GL_COLOR_ARRAY_STRIDE));
   opengl_ns.addConstant("GL_INDEX_ARRAY_TYPE",                        new QoreBigIntNode(GL_INDEX_ARRAY_TYPE));
   opengl_ns.addConstant("GL_INDEX_ARRAY_STRIDE",                      new QoreBigIntNode(GL_INDEX_ARRAY_STRIDE));
   opengl_ns.addConstant("GL_TEXTURE_COORD_ARRAY_SIZE",                new QoreBigIntNode(GL_TEXTURE_COORD_ARRAY_SIZE));
   opengl_ns.addConstant("GL_TEXTURE_COORD_ARRAY_TYPE",                new QoreBigIntNode(GL_TEXTURE_COORD_ARRAY_TYPE));
   opengl_ns.addConstant("GL_TEXTURE_COORD_ARRAY_STRIDE",              new QoreBigIntNode(GL_TEXTURE_COORD_ARRAY_STRIDE));
   opengl_ns.addConstant("GL_EDGE_FLAG_ARRAY_STRIDE",                  new QoreBigIntNode(GL_EDGE_FLAG_ARRAY_STRIDE));
   opengl_ns.addConstant("GL_VERTEX_ARRAY_POINTER",                    new QoreBigIntNode(GL_VERTEX_ARRAY_POINTER));
   opengl_ns.addConstant("GL_NORMAL_ARRAY_POINTER",                    new QoreBigIntNode(GL_NORMAL_ARRAY_POINTER));
   opengl_ns.addConstant("GL_COLOR_ARRAY_POINTER",                     new QoreBigIntNode(GL_COLOR_ARRAY_POINTER));
   opengl_ns.addConstant("GL_INDEX_ARRAY_POINTER",                     new QoreBigIntNode(GL_INDEX_ARRAY_POINTER));
   opengl_ns.addConstant("GL_TEXTURE_COORD_ARRAY_POINTER",             new QoreBigIntNode(GL_TEXTURE_COORD_ARRAY_POINTER));
   opengl_ns.addConstant("GL_EDGE_FLAG_ARRAY_POINTER",                 new QoreBigIntNode(GL_EDGE_FLAG_ARRAY_POINTER));
   opengl_ns.addConstant("GL_V2F",                                     new QoreBigIntNode(GL_V2F));
   opengl_ns.addConstant("GL_V3F",                                     new QoreBigIntNode(GL_V3F));
   opengl_ns.addConstant("GL_C4UB_V2F",                                new QoreBigIntNode(GL_C4UB_V2F));
   opengl_ns.addConstant("GL_C4UB_V3F",                                new QoreBigIntNode(GL_C4UB_V3F));
   opengl_ns.addConstant("GL_C3F_V3F",                                 new QoreBigIntNode(GL_C3F_V3F));
   opengl_ns.addConstant("GL_N3F_V3F",                                 new QoreBigIntNode(GL_N3F_V3F));
   opengl_ns.addConstant("GL_C4F_N3F_V3F",                             new QoreBigIntNode(GL_C4F_N3F_V3F));
   opengl_ns.addConstant("GL_T2F_V3F",                                 new QoreBigIntNode(GL_T2F_V3F));
   opengl_ns.addConstant("GL_T4F_V4F",                                 new QoreBigIntNode(GL_T4F_V4F));
   opengl_ns.addConstant("GL_T2F_C4UB_V3F",                            new QoreBigIntNode(GL_T2F_C4UB_V3F));
   opengl_ns.addConstant("GL_T2F_C3F_V3F",                             new QoreBigIntNode(GL_T2F_C3F_V3F));
   opengl_ns.addConstant("GL_T2F_N3F_V3F",                             new QoreBigIntNode(GL_T2F_N3F_V3F));
   opengl_ns.addConstant("GL_T2F_C4F_N3F_V3F",                         new QoreBigIntNode(GL_T2F_C4F_N3F_V3F));
   opengl_ns.addConstant("GL_T4F_C4F_N3F_V4F",                         new QoreBigIntNode(GL_T4F_C4F_N3F_V4F));
   opengl_ns.addConstant("GL_BGR",                                     new QoreBigIntNode(GL_BGR));
   opengl_ns.addConstant("GL_BGRA",                                    new QoreBigIntNode(GL_BGRA));
   opengl_ns.addConstant("GL_CONSTANT_COLOR",                          new QoreBigIntNode(GL_CONSTANT_COLOR));
   opengl_ns.addConstant("GL_ONE_MINUS_CONSTANT_COLOR",                new QoreBigIntNode(GL_ONE_MINUS_CONSTANT_COLOR));
   opengl_ns.addConstant("GL_CONSTANT_ALPHA",                          new QoreBigIntNode(GL_CONSTANT_ALPHA));
   opengl_ns.addConstant("GL_ONE_MINUS_CONSTANT_ALPHA",                new QoreBigIntNode(GL_ONE_MINUS_CONSTANT_ALPHA));
   opengl_ns.addConstant("GL_BLEND_COLOR",                             new QoreBigIntNode(GL_BLEND_COLOR));
   opengl_ns.addConstant("GL_FUNC_ADD",                                new QoreBigIntNode(GL_FUNC_ADD));
   opengl_ns.addConstant("GL_MIN",                                     new QoreBigIntNode(GL_MIN));
   opengl_ns.addConstant("GL_MAX",                                     new QoreBigIntNode(GL_MAX));
   opengl_ns.addConstant("GL_BLEND_EQUATION",                          new QoreBigIntNode(GL_BLEND_EQUATION));
   opengl_ns.addConstant("GL_BLEND_EQUATION_RGB",                      new QoreBigIntNode(GL_BLEND_EQUATION_RGB));
   opengl_ns.addConstant("GL_BLEND_EQUATION_ALPHA",                    new QoreBigIntNode(GL_BLEND_EQUATION_ALPHA));
   opengl_ns.addConstant("GL_FUNC_SUBTRACT",                           new QoreBigIntNode(GL_FUNC_SUBTRACT));
   opengl_ns.addConstant("GL_FUNC_REVERSE_SUBTRACT",                   new QoreBigIntNode(GL_FUNC_REVERSE_SUBTRACT));
   opengl_ns.addConstant("GL_COLOR_MATRIX",                            new QoreBigIntNode(GL_COLOR_MATRIX));
   opengl_ns.addConstant("GL_COLOR_MATRIX_STACK_DEPTH",                new QoreBigIntNode(GL_COLOR_MATRIX_STACK_DEPTH));
   opengl_ns.addConstant("GL_MAX_COLOR_MATRIX_STACK_DEPTH",            new QoreBigIntNode(GL_MAX_COLOR_MATRIX_STACK_DEPTH));
   opengl_ns.addConstant("GL_POST_COLOR_MATRIX_RED_SCALE",             new QoreBigIntNode(GL_POST_COLOR_MATRIX_RED_SCALE));
   opengl_ns.addConstant("GL_POST_COLOR_MATRIX_GREEN_SCALE",           new QoreBigIntNode(GL_POST_COLOR_MATRIX_GREEN_SCALE));
   opengl_ns.addConstant("GL_POST_COLOR_MATRIX_BLUE_SCALE",            new QoreBigIntNode(GL_POST_COLOR_MATRIX_BLUE_SCALE));
   opengl_ns.addConstant("GL_POST_COLOR_MATRIX_ALPHA_SCALE",           new QoreBigIntNode(GL_POST_COLOR_MATRIX_ALPHA_SCALE));
   opengl_ns.addConstant("GL_POST_COLOR_MATRIX_RED_BIAS",              new QoreBigIntNode(GL_POST_COLOR_MATRIX_RED_BIAS));
   opengl_ns.addConstant("GL_POST_COLOR_MATRIX_GREEN_BIAS",            new QoreBigIntNode(GL_POST_COLOR_MATRIX_GREEN_BIAS));
   opengl_ns.addConstant("GL_POST_COLOR_MATRIX_BLUE_BIAS",             new QoreBigIntNode(GL_POST_COLOR_MATRIX_BLUE_BIAS));
   opengl_ns.addConstant("GL_POST_COLOR_MATRIX_ALPHA_BIAS",            new QoreBigIntNode(GL_POST_COLOR_MATRIX_ALPHA_BIAS));
   opengl_ns.addConstant("GL_COLOR_TABLE",                             new QoreBigIntNode(GL_COLOR_TABLE));
   opengl_ns.addConstant("GL_POST_CONVOLUTION_COLOR_TABLE",            new QoreBigIntNode(GL_POST_CONVOLUTION_COLOR_TABLE));
   opengl_ns.addConstant("GL_POST_COLOR_MATRIX_COLOR_TABLE",           new QoreBigIntNode(GL_POST_COLOR_MATRIX_COLOR_TABLE));
   opengl_ns.addConstant("GL_PROXY_COLOR_TABLE",                       new QoreBigIntNode(GL_PROXY_COLOR_TABLE));
   opengl_ns.addConstant("GL_PROXY_POST_CONVOLUTION_COLOR_TABLE",      new QoreBigIntNode(GL_PROXY_POST_CONVOLUTION_COLOR_TABLE));
   opengl_ns.addConstant("GL_PROXY_POST_COLOR_MATRIX_COLOR_TABLE",     new QoreBigIntNode(GL_PROXY_POST_COLOR_MATRIX_COLOR_TABLE));
   opengl_ns.addConstant("GL_COLOR_TABLE_SCALE",                       new QoreBigIntNode(GL_COLOR_TABLE_SCALE));
   opengl_ns.addConstant("GL_COLOR_TABLE_BIAS",                        new QoreBigIntNode(GL_COLOR_TABLE_BIAS));
   opengl_ns.addConstant("GL_COLOR_TABLE_FORMAT",                      new QoreBigIntNode(GL_COLOR_TABLE_FORMAT));
   opengl_ns.addConstant("GL_COLOR_TABLE_WIDTH",                       new QoreBigIntNode(GL_COLOR_TABLE_WIDTH));
   opengl_ns.addConstant("GL_COLOR_TABLE_RED_SIZE",                    new QoreBigIntNode(GL_COLOR_TABLE_RED_SIZE));
   opengl_ns.addConstant("GL_COLOR_TABLE_GREEN_SIZE",                  new QoreBigIntNode(GL_COLOR_TABLE_GREEN_SIZE));
   opengl_ns.addConstant("GL_COLOR_TABLE_BLUE_SIZE",                   new QoreBigIntNode(GL_COLOR_TABLE_BLUE_SIZE));
   opengl_ns.addConstant("GL_COLOR_TABLE_ALPHA_SIZE",                  new QoreBigIntNode(GL_COLOR_TABLE_ALPHA_SIZE));
   opengl_ns.addConstant("GL_COLOR_TABLE_LUMINANCE_SIZE",              new QoreBigIntNode(GL_COLOR_TABLE_LUMINANCE_SIZE));
   opengl_ns.addConstant("GL_COLOR_TABLE_INTENSITY_SIZE",              new QoreBigIntNode(GL_COLOR_TABLE_INTENSITY_SIZE));
   opengl_ns.addConstant("GL_CONVOLUTION_1D",                          new QoreBigIntNode(GL_CONVOLUTION_1D));
   opengl_ns.addConstant("GL_CONVOLUTION_2D",                          new QoreBigIntNode(GL_CONVOLUTION_2D));
   opengl_ns.addConstant("GL_SEPARABLE_2D",                            new QoreBigIntNode(GL_SEPARABLE_2D));
   opengl_ns.addConstant("GL_CONVOLUTION_BORDER_MODE",                 new QoreBigIntNode(GL_CONVOLUTION_BORDER_MODE));
   opengl_ns.addConstant("GL_CONVOLUTION_FILTER_SCALE",                new QoreBigIntNode(GL_CONVOLUTION_FILTER_SCALE));
   opengl_ns.addConstant("GL_CONVOLUTION_FILTER_BIAS",                 new QoreBigIntNode(GL_CONVOLUTION_FILTER_BIAS));
   opengl_ns.addConstant("GL_REDUCE",                                  new QoreBigIntNode(GL_REDUCE));
   opengl_ns.addConstant("GL_CONVOLUTION_FORMAT",                      new QoreBigIntNode(GL_CONVOLUTION_FORMAT));
   opengl_ns.addConstant("GL_CONVOLUTION_WIDTH",                       new QoreBigIntNode(GL_CONVOLUTION_WIDTH));
   opengl_ns.addConstant("GL_CONVOLUTION_HEIGHT",                      new QoreBigIntNode(GL_CONVOLUTION_HEIGHT));
   opengl_ns.addConstant("GL_MAX_CONVOLUTION_WIDTH",                   new QoreBigIntNode(GL_MAX_CONVOLUTION_WIDTH));
   opengl_ns.addConstant("GL_MAX_CONVOLUTION_HEIGHT",                  new QoreBigIntNode(GL_MAX_CONVOLUTION_HEIGHT));
   opengl_ns.addConstant("GL_POST_CONVOLUTION_RED_SCALE",              new QoreBigIntNode(GL_POST_CONVOLUTION_RED_SCALE));
   opengl_ns.addConstant("GL_POST_CONVOLUTION_GREEN_SCALE",            new QoreBigIntNode(GL_POST_CONVOLUTION_GREEN_SCALE));
   opengl_ns.addConstant("GL_POST_CONVOLUTION_BLUE_SCALE",             new QoreBigIntNode(GL_POST_CONVOLUTION_BLUE_SCALE));
   opengl_ns.addConstant("GL_POST_CONVOLUTION_ALPHA_SCALE",            new QoreBigIntNode(GL_POST_CONVOLUTION_ALPHA_SCALE));
   opengl_ns.addConstant("GL_POST_CONVOLUTION_RED_BIAS",               new QoreBigIntNode(GL_POST_CONVOLUTION_RED_BIAS));
   opengl_ns.addConstant("GL_POST_CONVOLUTION_GREEN_BIAS",             new QoreBigIntNode(GL_POST_CONVOLUTION_GREEN_BIAS));
   opengl_ns.addConstant("GL_POST_CONVOLUTION_BLUE_BIAS",              new QoreBigIntNode(GL_POST_CONVOLUTION_BLUE_BIAS));
   opengl_ns.addConstant("GL_POST_CONVOLUTION_ALPHA_BIAS",             new QoreBigIntNode(GL_POST_CONVOLUTION_ALPHA_BIAS));
   opengl_ns.addConstant("GL_CONSTANT_BORDER",                         new QoreBigIntNode(GL_CONSTANT_BORDER));
   opengl_ns.addConstant("GL_REPLICATE_BORDER",                        new QoreBigIntNode(GL_REPLICATE_BORDER));
   opengl_ns.addConstant("GL_CONVOLUTION_BORDER_COLOR",                new QoreBigIntNode(GL_CONVOLUTION_BORDER_COLOR));
   opengl_ns.addConstant("GL_MAX_ELEMENTS_VERTICES",                   new QoreBigIntNode(GL_MAX_ELEMENTS_VERTICES));
   opengl_ns.addConstant("GL_MAX_ELEMENTS_INDICES",                    new QoreBigIntNode(GL_MAX_ELEMENTS_INDICES));
   opengl_ns.addConstant("GL_HISTOGRAM",                               new QoreBigIntNode(GL_HISTOGRAM));
   opengl_ns.addConstant("GL_PROXY_HISTOGRAM",                         new QoreBigIntNode(GL_PROXY_HISTOGRAM));
   opengl_ns.addConstant("GL_HISTOGRAM_WIDTH",                         new QoreBigIntNode(GL_HISTOGRAM_WIDTH));
   opengl_ns.addConstant("GL_HISTOGRAM_FORMAT",                        new QoreBigIntNode(GL_HISTOGRAM_FORMAT));
   opengl_ns.addConstant("GL_HISTOGRAM_RED_SIZE",                      new QoreBigIntNode(GL_HISTOGRAM_RED_SIZE));
   opengl_ns.addConstant("GL_HISTOGRAM_GREEN_SIZE",                    new QoreBigIntNode(GL_HISTOGRAM_GREEN_SIZE));
   opengl_ns.addConstant("GL_HISTOGRAM_BLUE_SIZE",                     new QoreBigIntNode(GL_HISTOGRAM_BLUE_SIZE));
   opengl_ns.addConstant("GL_HISTOGRAM_ALPHA_SIZE",                    new QoreBigIntNode(GL_HISTOGRAM_ALPHA_SIZE));
   opengl_ns.addConstant("GL_HISTOGRAM_LUMINANCE_SIZE",                new QoreBigIntNode(GL_HISTOGRAM_LUMINANCE_SIZE));
   opengl_ns.addConstant("GL_HISTOGRAM_SINK",                          new QoreBigIntNode(GL_HISTOGRAM_SINK));
   opengl_ns.addConstant("GL_MINMAX",                                  new QoreBigIntNode(GL_MINMAX));
   opengl_ns.addConstant("GL_MINMAX_FORMAT",                           new QoreBigIntNode(GL_MINMAX_FORMAT));
   opengl_ns.addConstant("GL_MINMAX_SINK",                             new QoreBigIntNode(GL_MINMAX_SINK));
   opengl_ns.addConstant("GL_TABLE_TOO_LARGE",                         new QoreBigIntNode(GL_TABLE_TOO_LARGE));
   opengl_ns.addConstant("GL_UNSIGNED_BYTE_3_3_2",                     new QoreBigIntNode(GL_UNSIGNED_BYTE_3_3_2));
   opengl_ns.addConstant("GL_UNSIGNED_SHORT_4_4_4_4",                  new QoreBigIntNode(GL_UNSIGNED_SHORT_4_4_4_4));
   opengl_ns.addConstant("GL_UNSIGNED_SHORT_5_5_5_1",                  new QoreBigIntNode(GL_UNSIGNED_SHORT_5_5_5_1));
   opengl_ns.addConstant("GL_UNSIGNED_INT_8_8_8_8",                    new QoreBigIntNode(GL_UNSIGNED_INT_8_8_8_8));
   opengl_ns.addConstant("GL_UNSIGNED_INT_10_10_10_2",                 new QoreBigIntNode(GL_UNSIGNED_INT_10_10_10_2));
   opengl_ns.addConstant("GL_UNSIGNED_BYTE_2_3_3_REV",                 new QoreBigIntNode(GL_UNSIGNED_BYTE_2_3_3_REV));
   opengl_ns.addConstant("GL_UNSIGNED_SHORT_5_6_5",                    new QoreBigIntNode(GL_UNSIGNED_SHORT_5_6_5));
   opengl_ns.addConstant("GL_UNSIGNED_SHORT_5_6_5_REV",                new QoreBigIntNode(GL_UNSIGNED_SHORT_5_6_5_REV));
   opengl_ns.addConstant("GL_UNSIGNED_SHORT_4_4_4_4_REV",              new QoreBigIntNode(GL_UNSIGNED_SHORT_4_4_4_4_REV));
   opengl_ns.addConstant("GL_UNSIGNED_SHORT_1_5_5_5_REV",              new QoreBigIntNode(GL_UNSIGNED_SHORT_1_5_5_5_REV));
   opengl_ns.addConstant("GL_UNSIGNED_INT_8_8_8_8_REV",                new QoreBigIntNode(GL_UNSIGNED_INT_8_8_8_8_REV));
   opengl_ns.addConstant("GL_UNSIGNED_INT_2_10_10_10_REV",             new QoreBigIntNode(GL_UNSIGNED_INT_2_10_10_10_REV));
   opengl_ns.addConstant("GL_RESCALE_NORMAL",                          new QoreBigIntNode(GL_RESCALE_NORMAL));
   opengl_ns.addConstant("GL_LIGHT_MODEL_COLOR_CONTROL",               new QoreBigIntNode(GL_LIGHT_MODEL_COLOR_CONTROL));
   opengl_ns.addConstant("GL_SINGLE_COLOR",                            new QoreBigIntNode(GL_SINGLE_COLOR));
   opengl_ns.addConstant("GL_SEPARATE_SPECULAR_COLOR",                 new QoreBigIntNode(GL_SEPARATE_SPECULAR_COLOR));
   opengl_ns.addConstant("GL_PACK_SKIP_IMAGES",                        new QoreBigIntNode(GL_PACK_SKIP_IMAGES));
   opengl_ns.addConstant("GL_PACK_IMAGE_HEIGHT",                       new QoreBigIntNode(GL_PACK_IMAGE_HEIGHT));
   opengl_ns.addConstant("GL_UNPACK_SKIP_IMAGES",                      new QoreBigIntNode(GL_UNPACK_SKIP_IMAGES));
   opengl_ns.addConstant("GL_UNPACK_IMAGE_HEIGHT",                     new QoreBigIntNode(GL_UNPACK_IMAGE_HEIGHT));
   opengl_ns.addConstant("GL_TEXTURE_3D",                              new QoreBigIntNode(GL_TEXTURE_3D));
   opengl_ns.addConstant("GL_PROXY_TEXTURE_3D",                        new QoreBigIntNode(GL_PROXY_TEXTURE_3D));
   opengl_ns.addConstant("GL_TEXTURE_DEPTH",                           new QoreBigIntNode(GL_TEXTURE_DEPTH));
   opengl_ns.addConstant("GL_TEXTURE_WRAP_R",                          new QoreBigIntNode(GL_TEXTURE_WRAP_R));
   opengl_ns.addConstant("GL_MAX_3D_TEXTURE_SIZE",                     new QoreBigIntNode(GL_MAX_3D_TEXTURE_SIZE));
   opengl_ns.addConstant("GL_CLAMP_TO_EDGE",                           new QoreBigIntNode(GL_CLAMP_TO_EDGE));
   opengl_ns.addConstant("GL_CLAMP_TO_BORDER",                         new QoreBigIntNode(GL_CLAMP_TO_BORDER));
   opengl_ns.addConstant("GL_TEXTURE_MIN_LOD",                         new QoreBigIntNode(GL_TEXTURE_MIN_LOD));
   opengl_ns.addConstant("GL_TEXTURE_MAX_LOD",                         new QoreBigIntNode(GL_TEXTURE_MAX_LOD));
   opengl_ns.addConstant("GL_TEXTURE_BASE_LEVEL",                      new QoreBigIntNode(GL_TEXTURE_BASE_LEVEL));
   opengl_ns.addConstant("GL_TEXTURE_MAX_LEVEL",                       new QoreBigIntNode(GL_TEXTURE_MAX_LEVEL));
   opengl_ns.addConstant("GL_SMOOTH_POINT_SIZE_RANGE",                 new QoreBigIntNode(GL_SMOOTH_POINT_SIZE_RANGE));
   opengl_ns.addConstant("GL_SMOOTH_POINT_SIZE_GRANULARITY",           new QoreBigIntNode(GL_SMOOTH_POINT_SIZE_GRANULARITY));
   opengl_ns.addConstant("GL_SMOOTH_LINE_WIDTH_RANGE",                 new QoreBigIntNode(GL_SMOOTH_LINE_WIDTH_RANGE));
   opengl_ns.addConstant("GL_SMOOTH_LINE_WIDTH_GRANULARITY",           new QoreBigIntNode(GL_SMOOTH_LINE_WIDTH_GRANULARITY));
   opengl_ns.addConstant("GL_ALIASED_POINT_SIZE_RANGE",                new QoreBigIntNode(GL_ALIASED_POINT_SIZE_RANGE));
   opengl_ns.addConstant("GL_ALIASED_LINE_WIDTH_RANGE",                new QoreBigIntNode(GL_ALIASED_LINE_WIDTH_RANGE));
   opengl_ns.addConstant("GL_TEXTURE0",                                new QoreBigIntNode(GL_TEXTURE0));
   opengl_ns.addConstant("GL_TEXTURE1",                                new QoreBigIntNode(GL_TEXTURE1));
   opengl_ns.addConstant("GL_TEXTURE2",                                new QoreBigIntNode(GL_TEXTURE2));
   opengl_ns.addConstant("GL_TEXTURE3",                                new QoreBigIntNode(GL_TEXTURE3));
   opengl_ns.addConstant("GL_TEXTURE4",                                new QoreBigIntNode(GL_TEXTURE4));
   opengl_ns.addConstant("GL_TEXTURE5",                                new QoreBigIntNode(GL_TEXTURE5));
   opengl_ns.addConstant("GL_TEXTURE6",                                new QoreBigIntNode(GL_TEXTURE6));
   opengl_ns.addConstant("GL_TEXTURE7",                                new QoreBigIntNode(GL_TEXTURE7));
   opengl_ns.addConstant("GL_TEXTURE8",                                new QoreBigIntNode(GL_TEXTURE8));
   opengl_ns.addConstant("GL_TEXTURE9",                                new QoreBigIntNode(GL_TEXTURE9));
   opengl_ns.addConstant("GL_TEXTURE10",                               new QoreBigIntNode(GL_TEXTURE10));
   opengl_ns.addConstant("GL_TEXTURE11",                               new QoreBigIntNode(GL_TEXTURE11));
   opengl_ns.addConstant("GL_TEXTURE12",                               new QoreBigIntNode(GL_TEXTURE12));
   opengl_ns.addConstant("GL_TEXTURE13",                               new QoreBigIntNode(GL_TEXTURE13));
   opengl_ns.addConstant("GL_TEXTURE14",                               new QoreBigIntNode(GL_TEXTURE14));
   opengl_ns.addConstant("GL_TEXTURE15",                               new QoreBigIntNode(GL_TEXTURE15));
   opengl_ns.addConstant("GL_TEXTURE16",                               new QoreBigIntNode(GL_TEXTURE16));
   opengl_ns.addConstant("GL_TEXTURE17",                               new QoreBigIntNode(GL_TEXTURE17));
   opengl_ns.addConstant("GL_TEXTURE18",                               new QoreBigIntNode(GL_TEXTURE18));
   opengl_ns.addConstant("GL_TEXTURE19",                               new QoreBigIntNode(GL_TEXTURE19));
   opengl_ns.addConstant("GL_TEXTURE20",                               new QoreBigIntNode(GL_TEXTURE20));
   opengl_ns.addConstant("GL_TEXTURE21",                               new QoreBigIntNode(GL_TEXTURE21));
   opengl_ns.addConstant("GL_TEXTURE22",                               new QoreBigIntNode(GL_TEXTURE22));
   opengl_ns.addConstant("GL_TEXTURE23",                               new QoreBigIntNode(GL_TEXTURE23));
   opengl_ns.addConstant("GL_TEXTURE24",                               new QoreBigIntNode(GL_TEXTURE24));
   opengl_ns.addConstant("GL_TEXTURE25",                               new QoreBigIntNode(GL_TEXTURE25));
   opengl_ns.addConstant("GL_TEXTURE26",                               new QoreBigIntNode(GL_TEXTURE26));
   opengl_ns.addConstant("GL_TEXTURE27",                               new QoreBigIntNode(GL_TEXTURE27));
   opengl_ns.addConstant("GL_TEXTURE28",                               new QoreBigIntNode(GL_TEXTURE28));
   opengl_ns.addConstant("GL_TEXTURE29",                               new QoreBigIntNode(GL_TEXTURE29));
   opengl_ns.addConstant("GL_TEXTURE30",                               new QoreBigIntNode(GL_TEXTURE30));
   opengl_ns.addConstant("GL_TEXTURE31",                               new QoreBigIntNode(GL_TEXTURE31));
   opengl_ns.addConstant("GL_ACTIVE_TEXTURE",                          new QoreBigIntNode(GL_ACTIVE_TEXTURE));
   opengl_ns.addConstant("GL_CLIENT_ACTIVE_TEXTURE",                   new QoreBigIntNode(GL_CLIENT_ACTIVE_TEXTURE));
   opengl_ns.addConstant("GL_MAX_TEXTURE_UNITS",                       new QoreBigIntNode(GL_MAX_TEXTURE_UNITS));
   opengl_ns.addConstant("GL_COMBINE",                                 new QoreBigIntNode(GL_COMBINE));
   opengl_ns.addConstant("GL_COMBINE_RGB",                             new QoreBigIntNode(GL_COMBINE_RGB));
   opengl_ns.addConstant("GL_COMBINE_ALPHA",                           new QoreBigIntNode(GL_COMBINE_ALPHA));
   opengl_ns.addConstant("GL_RGB_SCALE",                               new QoreBigIntNode(GL_RGB_SCALE));
   opengl_ns.addConstant("GL_ADD_SIGNED",                              new QoreBigIntNode(GL_ADD_SIGNED));
   opengl_ns.addConstant("GL_INTERPOLATE",                             new QoreBigIntNode(GL_INTERPOLATE));
   opengl_ns.addConstant("GL_CONSTANT",                                new QoreBigIntNode(GL_CONSTANT));
   opengl_ns.addConstant("GL_PRIMARY_COLOR",                           new QoreBigIntNode(GL_PRIMARY_COLOR));
   opengl_ns.addConstant("GL_PREVIOUS",                                new QoreBigIntNode(GL_PREVIOUS));
   opengl_ns.addConstant("GL_SUBTRACT",                                new QoreBigIntNode(GL_SUBTRACT));
   opengl_ns.addConstant("GL_SRC0_RGB",                                new QoreBigIntNode(GL_SRC0_RGB));
   opengl_ns.addConstant("GL_SRC1_RGB",                                new QoreBigIntNode(GL_SRC1_RGB));
   opengl_ns.addConstant("GL_SRC2_RGB",                                new QoreBigIntNode(GL_SRC2_RGB));
#ifdef GL_SRC3_RGB
   opengl_ns.addConstant("GL_SRC3_RGB",                                new QoreBigIntNode(GL_SRC3_RGB));
#endif
#ifdef GL_SRC3_RGB
   opengl_ns.addConstant("GL_SRC4_RGB",                                new QoreBigIntNode(GL_SRC4_RGB));
#endif
#ifdef GL_SRC3_RGB
   opengl_ns.addConstant("GL_SRC5_RGB",                                new QoreBigIntNode(GL_SRC5_RGB));
#endif
#ifdef GL_SRC3_RGB
   opengl_ns.addConstant("GL_SRC6_RGB",                                new QoreBigIntNode(GL_SRC6_RGB));
#endif
#ifdef GL_SRC3_RGB
   opengl_ns.addConstant("GL_SRC7_RGB",                                new QoreBigIntNode(GL_SRC7_RGB));
#endif
   opengl_ns.addConstant("GL_SRC0_ALPHA",                              new QoreBigIntNode(GL_SRC0_ALPHA));
   opengl_ns.addConstant("GL_SRC1_ALPHA",                              new QoreBigIntNode(GL_SRC1_ALPHA));
   opengl_ns.addConstant("GL_SRC2_ALPHA",                              new QoreBigIntNode(GL_SRC2_ALPHA));
#ifdef GL_SRC3_ALPHA
   opengl_ns.addConstant("GL_SRC3_ALPHA",                              new QoreBigIntNode(GL_SRC3_ALPHA));
#endif
#ifdef GL_SRC4_ALPHA
   opengl_ns.addConstant("GL_SRC4_ALPHA",                              new QoreBigIntNode(GL_SRC4_ALPHA));
#endif
#ifdef GL_SRC5_ALPHA
   opengl_ns.addConstant("GL_SRC5_ALPHA",                              new QoreBigIntNode(GL_SRC5_ALPHA));
#endif
#ifdef GL_SRC6_ALPHA
   opengl_ns.addConstant("GL_SRC6_ALPHA",                              new QoreBigIntNode(GL_SRC6_ALPHA));
#endif
#ifdef GL_SRC7_ALPHA
   opengl_ns.addConstant("GL_SRC7_ALPHA",                              new QoreBigIntNode(GL_SRC7_ALPHA));
#endif
   opengl_ns.addConstant("GL_SOURCE0_RGB",                             new QoreBigIntNode(GL_SOURCE0_RGB));
   opengl_ns.addConstant("GL_SOURCE1_RGB",                             new QoreBigIntNode(GL_SOURCE1_RGB));
   opengl_ns.addConstant("GL_SOURCE2_RGB",                             new QoreBigIntNode(GL_SOURCE2_RGB));
#ifdef GL_SOURCE3_RGB
   opengl_ns.addConstant("GL_SOURCE3_RGB",                             new QoreBigIntNode(GL_SOURCE3_RGB));
#endif
#ifdef GL_SOURCE4_RGB
   opengl_ns.addConstant("GL_SOURCE4_RGB",                             new QoreBigIntNode(GL_SOURCE4_RGB));
#endif
#ifdef GL_SOURCE5_RGB
   opengl_ns.addConstant("GL_SOURCE5_RGB",                             new QoreBigIntNode(GL_SOURCE5_RGB));
#endif
#ifdef GL_SOURCE6_RGB
   opengl_ns.addConstant("GL_SOURCE6_RGB",                             new QoreBigIntNode(GL_SOURCE6_RGB));
#endif
#ifdef GL_SOURCE7_RGB
   opengl_ns.addConstant("GL_SOURCE7_RGB",                             new QoreBigIntNode(GL_SOURCE7_RGB));
#endif
   opengl_ns.addConstant("GL_SOURCE0_ALPHA",                           new QoreBigIntNode(GL_SOURCE0_ALPHA));
   opengl_ns.addConstant("GL_SOURCE1_ALPHA",                           new QoreBigIntNode(GL_SOURCE1_ALPHA));
   opengl_ns.addConstant("GL_SOURCE2_ALPHA",                           new QoreBigIntNode(GL_SOURCE2_ALPHA));
#ifdef GL_SOURCE3_ALPHA
   opengl_ns.addConstant("GL_SOURCE3_ALPHA",                           new QoreBigIntNode(GL_SOURCE3_ALPHA));
#endif
#ifdef GL_SOURCE4_ALPHA
   opengl_ns.addConstant("GL_SOURCE4_ALPHA",                           new QoreBigIntNode(GL_SOURCE4_ALPHA));
#endif
#ifdef GL_SOURCE5_ALPHA
   opengl_ns.addConstant("GL_SOURCE5_ALPHA",                           new QoreBigIntNode(GL_SOURCE5_ALPHA));
#endif
#ifdef GL_SOURCE6_ALPHA
   opengl_ns.addConstant("GL_SOURCE6_ALPHA",                           new QoreBigIntNode(GL_SOURCE6_ALPHA));
#endif
#ifdef GL_SOURCE7_ALPHA
   opengl_ns.addConstant("GL_SOURCE7_ALPHA",                           new QoreBigIntNode(GL_SOURCE7_ALPHA));
#endif
   opengl_ns.addConstant("GL_OPERAND0_RGB",                            new QoreBigIntNode(GL_OPERAND0_RGB));
   opengl_ns.addConstant("GL_OPERAND1_RGB",                            new QoreBigIntNode(GL_OPERAND1_RGB));
   opengl_ns.addConstant("GL_OPERAND2_RGB",                            new QoreBigIntNode(GL_OPERAND2_RGB));
#ifdef GL_OPERAND3_RGB
   opengl_ns.addConstant("GL_OPERAND3_RGB",                            new QoreBigIntNode(GL_OPERAND3_RGB));
#endif
#ifdef GL_OPERAND3_RGB
   opengl_ns.addConstant("GL_OPERAND4_RGB",                            new QoreBigIntNode(GL_OPERAND4_RGB));
#endif
#ifdef GL_OPERAND3_RGB
   opengl_ns.addConstant("GL_OPERAND5_RGB",                            new QoreBigIntNode(GL_OPERAND5_RGB));
#endif
#ifdef GL_OPERAND3_RGB
   opengl_ns.addConstant("GL_OPERAND6_RGB",                            new QoreBigIntNode(GL_OPERAND6_RGB));
#endif
#ifdef GL_OPERAND3_RGB
   opengl_ns.addConstant("GL_OPERAND7_RGB",                            new QoreBigIntNode(GL_OPERAND7_RGB));
#endif
   opengl_ns.addConstant("GL_OPERAND0_ALPHA",                          new QoreBigIntNode(GL_OPERAND0_ALPHA));
   opengl_ns.addConstant("GL_OPERAND1_ALPHA",                          new QoreBigIntNode(GL_OPERAND1_ALPHA));
   opengl_ns.addConstant("GL_OPERAND2_ALPHA",                          new QoreBigIntNode(GL_OPERAND2_ALPHA));
#ifdef GL_OPERAND3_ALPHA
   opengl_ns.addConstant("GL_OPERAND3_ALPHA",                          new QoreBigIntNode(GL_OPERAND3_ALPHA));
#endif
#ifdef GL_OPERAND4_ALPHA
   opengl_ns.addConstant("GL_OPERAND4_ALPHA",                          new QoreBigIntNode(GL_OPERAND4_ALPHA));
#endif
#ifdef GL_OPERAND5_ALPHA
   opengl_ns.addConstant("GL_OPERAND5_ALPHA",                          new QoreBigIntNode(GL_OPERAND5_ALPHA));
#endif
#ifdef GL_OPERAND6_ALPHA
   opengl_ns.addConstant("GL_OPERAND6_ALPHA",                          new QoreBigIntNode(GL_OPERAND6_ALPHA));
#endif
#ifdef GL_OPERAND7_ALPHA
   opengl_ns.addConstant("GL_OPERAND7_ALPHA",                          new QoreBigIntNode(GL_OPERAND7_ALPHA));
#endif
   opengl_ns.addConstant("GL_DOT3_RGB",                                new QoreBigIntNode(GL_DOT3_RGB));
   opengl_ns.addConstant("GL_DOT3_RGBA",                               new QoreBigIntNode(GL_DOT3_RGBA));
   opengl_ns.addConstant("GL_TRANSPOSE_MODELVIEW_MATRIX",              new QoreBigIntNode(GL_TRANSPOSE_MODELVIEW_MATRIX));
   opengl_ns.addConstant("GL_TRANSPOSE_PROJECTION_MATRIX",             new QoreBigIntNode(GL_TRANSPOSE_PROJECTION_MATRIX));
   opengl_ns.addConstant("GL_TRANSPOSE_TEXTURE_MATRIX",                new QoreBigIntNode(GL_TRANSPOSE_TEXTURE_MATRIX));
   opengl_ns.addConstant("GL_TRANSPOSE_COLOR_MATRIX",                  new QoreBigIntNode(GL_TRANSPOSE_COLOR_MATRIX));
   opengl_ns.addConstant("GL_NORMAL_MAP",                              new QoreBigIntNode(GL_NORMAL_MAP));
   opengl_ns.addConstant("GL_REFLECTION_MAP",                          new QoreBigIntNode(GL_REFLECTION_MAP));
   opengl_ns.addConstant("GL_TEXTURE_CUBE_MAP",                        new QoreBigIntNode(GL_TEXTURE_CUBE_MAP));
   opengl_ns.addConstant("GL_TEXTURE_BINDING_CUBE_MAP",                new QoreBigIntNode(GL_TEXTURE_BINDING_CUBE_MAP));
   opengl_ns.addConstant("GL_TEXTURE_CUBE_MAP_POSITIVE_X",             new QoreBigIntNode(GL_TEXTURE_CUBE_MAP_POSITIVE_X));
   opengl_ns.addConstant("GL_TEXTURE_CUBE_MAP_NEGATIVE_X",             new QoreBigIntNode(GL_TEXTURE_CUBE_MAP_NEGATIVE_X));
   opengl_ns.addConstant("GL_TEXTURE_CUBE_MAP_POSITIVE_Y",             new QoreBigIntNode(GL_TEXTURE_CUBE_MAP_POSITIVE_Y));
   opengl_ns.addConstant("GL_TEXTURE_CUBE_MAP_NEGATIVE_Y",             new QoreBigIntNode(GL_TEXTURE_CUBE_MAP_NEGATIVE_Y));
   opengl_ns.addConstant("GL_TEXTURE_CUBE_MAP_POSITIVE_Z",             new QoreBigIntNode(GL_TEXTURE_CUBE_MAP_POSITIVE_Z));
   opengl_ns.addConstant("GL_TEXTURE_CUBE_MAP_NEGATIVE_Z",             new QoreBigIntNode(GL_TEXTURE_CUBE_MAP_NEGATIVE_Z));
   opengl_ns.addConstant("GL_PROXY_TEXTURE_CUBE_MAP",                  new QoreBigIntNode(GL_PROXY_TEXTURE_CUBE_MAP));
   opengl_ns.addConstant("GL_MAX_CUBE_MAP_TEXTURE_SIZE",               new QoreBigIntNode(GL_MAX_CUBE_MAP_TEXTURE_SIZE));
   opengl_ns.addConstant("GL_COMPRESSED_ALPHA",                        new QoreBigIntNode(GL_COMPRESSED_ALPHA));
   opengl_ns.addConstant("GL_COMPRESSED_LUMINANCE",                    new QoreBigIntNode(GL_COMPRESSED_LUMINANCE));
   opengl_ns.addConstant("GL_COMPRESSED_LUMINANCE_ALPHA",              new QoreBigIntNode(GL_COMPRESSED_LUMINANCE_ALPHA));
   opengl_ns.addConstant("GL_COMPRESSED_INTENSITY",                    new QoreBigIntNode(GL_COMPRESSED_INTENSITY));
   opengl_ns.addConstant("GL_COMPRESSED_RGB",                          new QoreBigIntNode(GL_COMPRESSED_RGB));
   opengl_ns.addConstant("GL_COMPRESSED_RGBA",                         new QoreBigIntNode(GL_COMPRESSED_RGBA));
   opengl_ns.addConstant("GL_TEXTURE_COMPRESSION_HINT",                new QoreBigIntNode(GL_TEXTURE_COMPRESSION_HINT));
   opengl_ns.addConstant("GL_TEXTURE_COMPRESSED_IMAGE_SIZE",           new QoreBigIntNode(GL_TEXTURE_COMPRESSED_IMAGE_SIZE));
   opengl_ns.addConstant("GL_TEXTURE_COMPRESSED",                      new QoreBigIntNode(GL_TEXTURE_COMPRESSED));
   opengl_ns.addConstant("GL_NUM_COMPRESSED_TEXTURE_FORMATS",          new QoreBigIntNode(GL_NUM_COMPRESSED_TEXTURE_FORMATS));
   opengl_ns.addConstant("GL_COMPRESSED_TEXTURE_FORMATS",              new QoreBigIntNode(GL_COMPRESSED_TEXTURE_FORMATS));
   opengl_ns.addConstant("GL_MULTISAMPLE",                             new QoreBigIntNode(GL_MULTISAMPLE));
   opengl_ns.addConstant("GL_SAMPLE_ALPHA_TO_COVERAGE",                new QoreBigIntNode(GL_SAMPLE_ALPHA_TO_COVERAGE));
   opengl_ns.addConstant("GL_SAMPLE_ALPHA_TO_ONE",                     new QoreBigIntNode(GL_SAMPLE_ALPHA_TO_ONE));
   opengl_ns.addConstant("GL_SAMPLE_COVERAGE",                         new QoreBigIntNode(GL_SAMPLE_COVERAGE));
   opengl_ns.addConstant("GL_SAMPLE_BUFFERS",                          new QoreBigIntNode(GL_SAMPLE_BUFFERS));
   opengl_ns.addConstant("GL_SAMPLES",                                 new QoreBigIntNode(GL_SAMPLES));
   opengl_ns.addConstant("GL_SAMPLE_COVERAGE_VALUE",                   new QoreBigIntNode(GL_SAMPLE_COVERAGE_VALUE));
   opengl_ns.addConstant("GL_SAMPLE_COVERAGE_INVERT",                  new QoreBigIntNode(GL_SAMPLE_COVERAGE_INVERT));
   opengl_ns.addConstant("GL_MULTISAMPLE_BIT",                         new QoreBigIntNode(GL_MULTISAMPLE_BIT));
   opengl_ns.addConstant("GL_DEPTH_COMPONENT16",                       new QoreBigIntNode(GL_DEPTH_COMPONENT16));
   opengl_ns.addConstant("GL_DEPTH_COMPONENT24",                       new QoreBigIntNode(GL_DEPTH_COMPONENT24));
   opengl_ns.addConstant("GL_DEPTH_COMPONENT32",                       new QoreBigIntNode(GL_DEPTH_COMPONENT32));
   opengl_ns.addConstant("GL_TEXTURE_DEPTH_SIZE",                      new QoreBigIntNode(GL_TEXTURE_DEPTH_SIZE));
   opengl_ns.addConstant("GL_DEPTH_TEXTURE_MODE",                      new QoreBigIntNode(GL_DEPTH_TEXTURE_MODE));
   opengl_ns.addConstant("GL_TEXTURE_COMPARE_MODE",                    new QoreBigIntNode(GL_TEXTURE_COMPARE_MODE));
   opengl_ns.addConstant("GL_TEXTURE_COMPARE_FUNC",                    new QoreBigIntNode(GL_TEXTURE_COMPARE_FUNC));
   opengl_ns.addConstant("GL_COMPARE_R_TO_TEXTURE",                    new QoreBigIntNode(GL_COMPARE_R_TO_TEXTURE));
   opengl_ns.addConstant("GL_QUERY_COUNTER_BITS",                      new QoreBigIntNode(GL_QUERY_COUNTER_BITS));
   opengl_ns.addConstant("GL_CURRENT_QUERY",                           new QoreBigIntNode(GL_CURRENT_QUERY));
   opengl_ns.addConstant("GL_QUERY_RESULT",                            new QoreBigIntNode(GL_QUERY_RESULT));
   opengl_ns.addConstant("GL_QUERY_RESULT_AVAILABLE",                  new QoreBigIntNode(GL_QUERY_RESULT_AVAILABLE));
   opengl_ns.addConstant("GL_SAMPLES_PASSED",                          new QoreBigIntNode(GL_SAMPLES_PASSED));
   opengl_ns.addConstant("GL_FOG_COORD_SRC",                           new QoreBigIntNode(GL_FOG_COORD_SRC));
   opengl_ns.addConstant("GL_FOG_COORD",                               new QoreBigIntNode(GL_FOG_COORD));
   opengl_ns.addConstant("GL_FRAGMENT_DEPTH",                          new QoreBigIntNode(GL_FRAGMENT_DEPTH));
   opengl_ns.addConstant("GL_FOG_COORD_ARRAY_TYPE",                    new QoreBigIntNode(GL_FOG_COORD_ARRAY_TYPE));
   opengl_ns.addConstant("GL_FOG_COORD_ARRAY_STRIDE",                  new QoreBigIntNode(GL_FOG_COORD_ARRAY_STRIDE));
   opengl_ns.addConstant("GL_FOG_COORD_ARRAY_POINTER",                 new QoreBigIntNode(GL_FOG_COORD_ARRAY_POINTER));
   opengl_ns.addConstant("GL_FOG_COORD_ARRAY",                         new QoreBigIntNode(GL_FOG_COORD_ARRAY));
   opengl_ns.addConstant("GL_FOG_COORDINATE_SOURCE",                   new QoreBigIntNode(GL_FOG_COORDINATE_SOURCE));
   opengl_ns.addConstant("GL_FOG_COORDINATE",                          new QoreBigIntNode(GL_FOG_COORDINATE));
   opengl_ns.addConstant("GL_FOG_COORDINATE_ARRAY_TYPE",               new QoreBigIntNode(GL_FOG_COORDINATE_ARRAY_TYPE));
   opengl_ns.addConstant("GL_FOG_COORDINATE_ARRAY_STRIDE",             new QoreBigIntNode(GL_FOG_COORDINATE_ARRAY_STRIDE));
   opengl_ns.addConstant("GL_FOG_COORDINATE_ARRAY_POINTER",            new QoreBigIntNode(GL_FOG_COORDINATE_ARRAY_POINTER));
   opengl_ns.addConstant("GL_FOG_COORDINATE_ARRAY",                    new QoreBigIntNode(GL_FOG_COORDINATE_ARRAY));
   opengl_ns.addConstant("GL_COLOR_SUM",                               new QoreBigIntNode(GL_COLOR_SUM));
   opengl_ns.addConstant("GL_CURRENT_SECONDARY_COLOR",                 new QoreBigIntNode(GL_CURRENT_SECONDARY_COLOR));
   opengl_ns.addConstant("GL_SECONDARY_COLOR_ARRAY_SIZE",              new QoreBigIntNode(GL_SECONDARY_COLOR_ARRAY_SIZE));
   opengl_ns.addConstant("GL_SECONDARY_COLOR_ARRAY_TYPE",              new QoreBigIntNode(GL_SECONDARY_COLOR_ARRAY_TYPE));
   opengl_ns.addConstant("GL_SECONDARY_COLOR_ARRAY_STRIDE",            new QoreBigIntNode(GL_SECONDARY_COLOR_ARRAY_STRIDE));
   opengl_ns.addConstant("GL_SECONDARY_COLOR_ARRAY_POINTER",           new QoreBigIntNode(GL_SECONDARY_COLOR_ARRAY_POINTER));
   opengl_ns.addConstant("GL_SECONDARY_COLOR_ARRAY",                   new QoreBigIntNode(GL_SECONDARY_COLOR_ARRAY));
   opengl_ns.addConstant("GL_POINT_SIZE_MIN",                          new QoreBigIntNode(GL_POINT_SIZE_MIN));
   opengl_ns.addConstant("GL_POINT_SIZE_MAX",                          new QoreBigIntNode(GL_POINT_SIZE_MAX));
   opengl_ns.addConstant("GL_POINT_FADE_THRESHOLD_SIZE",               new QoreBigIntNode(GL_POINT_FADE_THRESHOLD_SIZE));
   opengl_ns.addConstant("GL_POINT_DISTANCE_ATTENUATION",              new QoreBigIntNode(GL_POINT_DISTANCE_ATTENUATION));
   opengl_ns.addConstant("GL_BLEND_DST_RGB",                           new QoreBigIntNode(GL_BLEND_DST_RGB));
   opengl_ns.addConstant("GL_BLEND_SRC_RGB",                           new QoreBigIntNode(GL_BLEND_SRC_RGB));
   opengl_ns.addConstant("GL_BLEND_DST_ALPHA",                         new QoreBigIntNode(GL_BLEND_DST_ALPHA));
   opengl_ns.addConstant("GL_BLEND_SRC_ALPHA",                         new QoreBigIntNode(GL_BLEND_SRC_ALPHA));
   opengl_ns.addConstant("GL_GENERATE_MIPMAP",                         new QoreBigIntNode(GL_GENERATE_MIPMAP));
   opengl_ns.addConstant("GL_GENERATE_MIPMAP_HINT",                    new QoreBigIntNode(GL_GENERATE_MIPMAP_HINT));
   opengl_ns.addConstant("GL_INCR_WRAP",                               new QoreBigIntNode(GL_INCR_WRAP));
   opengl_ns.addConstant("GL_DECR_WRAP",                               new QoreBigIntNode(GL_DECR_WRAP));
   opengl_ns.addConstant("GL_MIRRORED_REPEAT",                         new QoreBigIntNode(GL_MIRRORED_REPEAT));
   opengl_ns.addConstant("GL_MAX_TEXTURE_LOD_BIAS",                    new QoreBigIntNode(GL_MAX_TEXTURE_LOD_BIAS));
   opengl_ns.addConstant("GL_TEXTURE_FILTER_CONTROL",                  new QoreBigIntNode(GL_TEXTURE_FILTER_CONTROL));
   opengl_ns.addConstant("GL_TEXTURE_LOD_BIAS",                        new QoreBigIntNode(GL_TEXTURE_LOD_BIAS));
   opengl_ns.addConstant("GL_ARRAY_BUFFER",                            new QoreBigIntNode(GL_ARRAY_BUFFER));
   opengl_ns.addConstant("GL_ELEMENT_ARRAY_BUFFER",                    new QoreBigIntNode(GL_ELEMENT_ARRAY_BUFFER));
   opengl_ns.addConstant("GL_ARRAY_BUFFER_BINDING",                    new QoreBigIntNode(GL_ARRAY_BUFFER_BINDING));
   opengl_ns.addConstant("GL_ELEMENT_ARRAY_BUFFER_BINDING",            new QoreBigIntNode(GL_ELEMENT_ARRAY_BUFFER_BINDING));
   opengl_ns.addConstant("GL_VERTEX_ARRAY_BUFFER_BINDING",             new QoreBigIntNode(GL_VERTEX_ARRAY_BUFFER_BINDING));
   opengl_ns.addConstant("GL_NORMAL_ARRAY_BUFFER_BINDING",             new QoreBigIntNode(GL_NORMAL_ARRAY_BUFFER_BINDING));
   opengl_ns.addConstant("GL_COLOR_ARRAY_BUFFER_BINDING",              new QoreBigIntNode(GL_COLOR_ARRAY_BUFFER_BINDING));
   opengl_ns.addConstant("GL_INDEX_ARRAY_BUFFER_BINDING",              new QoreBigIntNode(GL_INDEX_ARRAY_BUFFER_BINDING));
   opengl_ns.addConstant("GL_TEXTURE_COORD_ARRAY_BUFFER_BINDING",      new QoreBigIntNode(GL_TEXTURE_COORD_ARRAY_BUFFER_BINDING));
   opengl_ns.addConstant("GL_EDGE_FLAG_ARRAY_BUFFER_BINDING",          new QoreBigIntNode(GL_EDGE_FLAG_ARRAY_BUFFER_BINDING));
   opengl_ns.addConstant("GL_SECONDARY_COLOR_ARRAY_BUFFER_BINDING",    new QoreBigIntNode(GL_SECONDARY_COLOR_ARRAY_BUFFER_BINDING));
   opengl_ns.addConstant("GL_FOG_COORD_ARRAY_BUFFER_BINDING",          new QoreBigIntNode(GL_FOG_COORD_ARRAY_BUFFER_BINDING));
   opengl_ns.addConstant("GL_WEIGHT_ARRAY_BUFFER_BINDING",             new QoreBigIntNode(GL_WEIGHT_ARRAY_BUFFER_BINDING));
   opengl_ns.addConstant("GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING",      new QoreBigIntNode(GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING));
   opengl_ns.addConstant("GL_STREAM_DRAW",                             new QoreBigIntNode(GL_STREAM_DRAW));
   opengl_ns.addConstant("GL_STREAM_READ",                             new QoreBigIntNode(GL_STREAM_READ));
   opengl_ns.addConstant("GL_STREAM_COPY",                             new QoreBigIntNode(GL_STREAM_COPY));
   opengl_ns.addConstant("GL_STATIC_DRAW",                             new QoreBigIntNode(GL_STATIC_DRAW));
   opengl_ns.addConstant("GL_STATIC_READ",                             new QoreBigIntNode(GL_STATIC_READ));
   opengl_ns.addConstant("GL_STATIC_COPY",                             new QoreBigIntNode(GL_STATIC_COPY));
   opengl_ns.addConstant("GL_DYNAMIC_DRAW",                            new QoreBigIntNode(GL_DYNAMIC_DRAW));
   opengl_ns.addConstant("GL_DYNAMIC_READ",                            new QoreBigIntNode(GL_DYNAMIC_READ));
   opengl_ns.addConstant("GL_DYNAMIC_COPY",                            new QoreBigIntNode(GL_DYNAMIC_COPY));
   opengl_ns.addConstant("GL_READ_ONLY",                               new QoreBigIntNode(GL_READ_ONLY));
   opengl_ns.addConstant("GL_WRITE_ONLY",                              new QoreBigIntNode(GL_WRITE_ONLY));
   opengl_ns.addConstant("GL_READ_WRITE",                              new QoreBigIntNode(GL_READ_WRITE));
   opengl_ns.addConstant("GL_BUFFER_SIZE",                             new QoreBigIntNode(GL_BUFFER_SIZE));
   opengl_ns.addConstant("GL_BUFFER_USAGE",                            new QoreBigIntNode(GL_BUFFER_USAGE));
   opengl_ns.addConstant("GL_BUFFER_ACCESS",                           new QoreBigIntNode(GL_BUFFER_ACCESS));
   opengl_ns.addConstant("GL_BUFFER_MAPPED",                           new QoreBigIntNode(GL_BUFFER_MAPPED));
   opengl_ns.addConstant("GL_BUFFER_MAP_POINTER",                      new QoreBigIntNode(GL_BUFFER_MAP_POINTER));
   opengl_ns.addConstant("GL_FOG_COORDINATE_ARRAY_BUFFER_BINDING",     new QoreBigIntNode(GL_FOG_COORDINATE_ARRAY_BUFFER_BINDING));
   opengl_ns.addConstant("GL_CURRENT_PROGRAM",                         new QoreBigIntNode(GL_CURRENT_PROGRAM));
   opengl_ns.addConstant("GL_SHADER_TYPE",                             new QoreBigIntNode(GL_SHADER_TYPE));
   opengl_ns.addConstant("GL_DELETE_STATUS",                           new QoreBigIntNode(GL_DELETE_STATUS));
   opengl_ns.addConstant("GL_COMPILE_STATUS",                          new QoreBigIntNode(GL_COMPILE_STATUS));
   opengl_ns.addConstant("GL_LINK_STATUS",                             new QoreBigIntNode(GL_LINK_STATUS));
   opengl_ns.addConstant("GL_VALIDATE_STATUS",                         new QoreBigIntNode(GL_VALIDATE_STATUS));
   opengl_ns.addConstant("GL_INFO_LOG_LENGTH",                         new QoreBigIntNode(GL_INFO_LOG_LENGTH));
   opengl_ns.addConstant("GL_ATTACHED_SHADERS",                        new QoreBigIntNode(GL_ATTACHED_SHADERS));
   opengl_ns.addConstant("GL_ACTIVE_UNIFORMS",                         new QoreBigIntNode(GL_ACTIVE_UNIFORMS));
   opengl_ns.addConstant("GL_ACTIVE_UNIFORM_MAX_LENGTH",               new QoreBigIntNode(GL_ACTIVE_UNIFORM_MAX_LENGTH));
   opengl_ns.addConstant("GL_SHADER_SOURCE_LENGTH",                    new QoreBigIntNode(GL_SHADER_SOURCE_LENGTH));
   opengl_ns.addConstant("GL_FLOAT_VEC2",                              new QoreBigIntNode(GL_FLOAT_VEC2));
   opengl_ns.addConstant("GL_FLOAT_VEC3",                              new QoreBigIntNode(GL_FLOAT_VEC3));
   opengl_ns.addConstant("GL_FLOAT_VEC4",                              new QoreBigIntNode(GL_FLOAT_VEC4));
   opengl_ns.addConstant("GL_INT_VEC2",                                new QoreBigIntNode(GL_INT_VEC2));
   opengl_ns.addConstant("GL_INT_VEC3",                                new QoreBigIntNode(GL_INT_VEC3));
   opengl_ns.addConstant("GL_INT_VEC4",                                new QoreBigIntNode(GL_INT_VEC4));
   opengl_ns.addConstant("GL_BOOL",                                    new QoreBigIntNode(GL_BOOL));
   opengl_ns.addConstant("GL_BOOL_VEC2",                               new QoreBigIntNode(GL_BOOL_VEC2));
   opengl_ns.addConstant("GL_BOOL_VEC3",                               new QoreBigIntNode(GL_BOOL_VEC3));
   opengl_ns.addConstant("GL_BOOL_VEC4",                               new QoreBigIntNode(GL_BOOL_VEC4));
   opengl_ns.addConstant("GL_FLOAT_MAT2",                              new QoreBigIntNode(GL_FLOAT_MAT2));
   opengl_ns.addConstant("GL_FLOAT_MAT3",                              new QoreBigIntNode(GL_FLOAT_MAT3));
   opengl_ns.addConstant("GL_FLOAT_MAT4",                              new QoreBigIntNode(GL_FLOAT_MAT4));
   opengl_ns.addConstant("GL_SAMPLER_1D",                              new QoreBigIntNode(GL_SAMPLER_1D));
   opengl_ns.addConstant("GL_SAMPLER_2D",                              new QoreBigIntNode(GL_SAMPLER_2D));
   opengl_ns.addConstant("GL_SAMPLER_3D",                              new QoreBigIntNode(GL_SAMPLER_3D));
   opengl_ns.addConstant("GL_SAMPLER_CUBE",                            new QoreBigIntNode(GL_SAMPLER_CUBE));
   opengl_ns.addConstant("GL_SAMPLER_1D_SHADOW",                       new QoreBigIntNode(GL_SAMPLER_1D_SHADOW));
   opengl_ns.addConstant("GL_SAMPLER_2D_SHADOW",                       new QoreBigIntNode(GL_SAMPLER_2D_SHADOW));
   opengl_ns.addConstant("GL_SHADING_LANGUAGE_VERSION",                new QoreBigIntNode(GL_SHADING_LANGUAGE_VERSION));
   opengl_ns.addConstant("GL_VERTEX_SHADER",                           new QoreBigIntNode(GL_VERTEX_SHADER));
   opengl_ns.addConstant("GL_MAX_VERTEX_UNIFORM_COMPONENTS",           new QoreBigIntNode(GL_MAX_VERTEX_UNIFORM_COMPONENTS));
   opengl_ns.addConstant("GL_MAX_VARYING_FLOATS",                      new QoreBigIntNode(GL_MAX_VARYING_FLOATS));
   opengl_ns.addConstant("GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS",          new QoreBigIntNode(GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS));
   opengl_ns.addConstant("GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS",        new QoreBigIntNode(GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS));
   opengl_ns.addConstant("GL_ACTIVE_ATTRIBUTES",                       new QoreBigIntNode(GL_ACTIVE_ATTRIBUTES));
   opengl_ns.addConstant("GL_ACTIVE_ATTRIBUTE_MAX_LENGTH",             new QoreBigIntNode(GL_ACTIVE_ATTRIBUTE_MAX_LENGTH));
   opengl_ns.addConstant("GL_FRAGMENT_SHADER",                         new QoreBigIntNode(GL_FRAGMENT_SHADER));
   opengl_ns.addConstant("GL_MAX_FRAGMENT_UNIFORM_COMPONENTS",         new QoreBigIntNode(GL_MAX_FRAGMENT_UNIFORM_COMPONENTS));
   opengl_ns.addConstant("GL_FRAGMENT_SHADER_DERIVATIVE_HINT",         new QoreBigIntNode(GL_FRAGMENT_SHADER_DERIVATIVE_HINT));
   opengl_ns.addConstant("GL_MAX_VERTEX_ATTRIBS",                      new QoreBigIntNode(GL_MAX_VERTEX_ATTRIBS));
   opengl_ns.addConstant("GL_VERTEX_ATTRIB_ARRAY_ENABLED",             new QoreBigIntNode(GL_VERTEX_ATTRIB_ARRAY_ENABLED));
   opengl_ns.addConstant("GL_VERTEX_ATTRIB_ARRAY_SIZE",                new QoreBigIntNode(GL_VERTEX_ATTRIB_ARRAY_SIZE));
   opengl_ns.addConstant("GL_VERTEX_ATTRIB_ARRAY_STRIDE",              new QoreBigIntNode(GL_VERTEX_ATTRIB_ARRAY_STRIDE));
   opengl_ns.addConstant("GL_VERTEX_ATTRIB_ARRAY_TYPE",                new QoreBigIntNode(GL_VERTEX_ATTRIB_ARRAY_TYPE));
   opengl_ns.addConstant("GL_VERTEX_ATTRIB_ARRAY_NORMALIZED",          new QoreBigIntNode(GL_VERTEX_ATTRIB_ARRAY_NORMALIZED));
   opengl_ns.addConstant("GL_CURRENT_VERTEX_ATTRIB",                   new QoreBigIntNode(GL_CURRENT_VERTEX_ATTRIB));
   opengl_ns.addConstant("GL_VERTEX_ATTRIB_ARRAY_POINTER",             new QoreBigIntNode(GL_VERTEX_ATTRIB_ARRAY_POINTER));
   opengl_ns.addConstant("GL_VERTEX_PROGRAM_POINT_SIZE",               new QoreBigIntNode(GL_VERTEX_PROGRAM_POINT_SIZE));
   opengl_ns.addConstant("GL_VERTEX_PROGRAM_TWO_SIDE",                 new QoreBigIntNode(GL_VERTEX_PROGRAM_TWO_SIDE));
   opengl_ns.addConstant("GL_MAX_TEXTURE_COORDS",                      new QoreBigIntNode(GL_MAX_TEXTURE_COORDS));
   opengl_ns.addConstant("GL_MAX_TEXTURE_IMAGE_UNITS",                 new QoreBigIntNode(GL_MAX_TEXTURE_IMAGE_UNITS));
   opengl_ns.addConstant("GL_MAX_DRAW_BUFFERS",                        new QoreBigIntNode(GL_MAX_DRAW_BUFFERS));
   opengl_ns.addConstant("GL_DRAW_BUFFER0",                            new QoreBigIntNode(GL_DRAW_BUFFER0));
   opengl_ns.addConstant("GL_DRAW_BUFFER1",                            new QoreBigIntNode(GL_DRAW_BUFFER1));
   opengl_ns.addConstant("GL_DRAW_BUFFER2",                            new QoreBigIntNode(GL_DRAW_BUFFER2));
   opengl_ns.addConstant("GL_DRAW_BUFFER3",                            new QoreBigIntNode(GL_DRAW_BUFFER3));
   opengl_ns.addConstant("GL_DRAW_BUFFER4",                            new QoreBigIntNode(GL_DRAW_BUFFER4));
   opengl_ns.addConstant("GL_DRAW_BUFFER5",                            new QoreBigIntNode(GL_DRAW_BUFFER5));
   opengl_ns.addConstant("GL_DRAW_BUFFER6",                            new QoreBigIntNode(GL_DRAW_BUFFER6));
   opengl_ns.addConstant("GL_DRAW_BUFFER7",                            new QoreBigIntNode(GL_DRAW_BUFFER7));
   opengl_ns.addConstant("GL_DRAW_BUFFER8",                            new QoreBigIntNode(GL_DRAW_BUFFER8));
   opengl_ns.addConstant("GL_DRAW_BUFFER9",                            new QoreBigIntNode(GL_DRAW_BUFFER9));
   opengl_ns.addConstant("GL_DRAW_BUFFER10",                           new QoreBigIntNode(GL_DRAW_BUFFER10));
   opengl_ns.addConstant("GL_DRAW_BUFFER11",                           new QoreBigIntNode(GL_DRAW_BUFFER11));
   opengl_ns.addConstant("GL_DRAW_BUFFER12",                           new QoreBigIntNode(GL_DRAW_BUFFER12));
   opengl_ns.addConstant("GL_DRAW_BUFFER13",                           new QoreBigIntNode(GL_DRAW_BUFFER13));
   opengl_ns.addConstant("GL_DRAW_BUFFER14",                           new QoreBigIntNode(GL_DRAW_BUFFER14));
   opengl_ns.addConstant("GL_DRAW_BUFFER15",                           new QoreBigIntNode(GL_DRAW_BUFFER15));
   opengl_ns.addConstant("GL_POINT_SPRITE",                            new QoreBigIntNode(GL_POINT_SPRITE));
   opengl_ns.addConstant("GL_COORD_REPLACE",                           new QoreBigIntNode(GL_COORD_REPLACE));
   opengl_ns.addConstant("GL_POINT_SPRITE_COORD_ORIGIN",               new QoreBigIntNode(GL_POINT_SPRITE_COORD_ORIGIN));
   opengl_ns.addConstant("GL_LOWER_LEFT",                              new QoreBigIntNode(GL_LOWER_LEFT));
   opengl_ns.addConstant("GL_UPPER_LEFT",                              new QoreBigIntNode(GL_UPPER_LEFT));
   opengl_ns.addConstant("GL_STENCIL_BACK_FUNC",                       new QoreBigIntNode(GL_STENCIL_BACK_FUNC));
   opengl_ns.addConstant("GL_STENCIL_BACK_VALUE_MASK",                 new QoreBigIntNode(GL_STENCIL_BACK_VALUE_MASK));
   opengl_ns.addConstant("GL_STENCIL_BACK_REF",                        new QoreBigIntNode(GL_STENCIL_BACK_REF));
   opengl_ns.addConstant("GL_STENCIL_BACK_FAIL",                       new QoreBigIntNode(GL_STENCIL_BACK_FAIL));
   opengl_ns.addConstant("GL_STENCIL_BACK_PASS_DEPTH_FAIL",            new QoreBigIntNode(GL_STENCIL_BACK_PASS_DEPTH_FAIL));
   opengl_ns.addConstant("GL_STENCIL_BACK_PASS_DEPTH_PASS",            new QoreBigIntNode(GL_STENCIL_BACK_PASS_DEPTH_PASS));
   opengl_ns.addConstant("GL_STENCIL_BACK_WRITEMASK",                  new QoreBigIntNode(GL_STENCIL_BACK_WRITEMASK));
#ifdef GL_CURRENT_RASTER_SECONDARY_COLOR
   opengl_ns.addConstant("GL_CURRENT_RASTER_SECONDARY_COLOR", new QoreBigIntNode(GL_CURRENT_RASTER_SECONDARY_COLOR));
#endif
#ifdef GL_PIXEL_PACK_BUFFER
   opengl_ns.addConstant("GL_PIXEL_PACK_BUFFER",              new QoreBigIntNode(GL_PIXEL_PACK_BUFFER));
#endif
#ifdef GL_PIXEL_UNPACK_BUFFER
   opengl_ns.addConstant("GL_PIXEL_UNPACK_BUFFER",            new QoreBigIntNode(GL_PIXEL_UNPACK_BUFFER));
#endif
#ifdef GL_PIXEL_PACK_BUFFER_BINDING
   opengl_ns.addConstant("GL_PIXEL_PACK_BUFFER_BINDING",      new QoreBigIntNode(GL_PIXEL_PACK_BUFFER_BINDING));
#endif
#ifdef GL_PIXEL_UNPACK_BUFFER_BINDING
   opengl_ns.addConstant("GL_PIXEL_UNPACK_BUFFER_BINDING",    new QoreBigIntNode(GL_PIXEL_UNPACK_BUFFER_BINDING));
#endif
#ifdef GL_FLOAT_MAT2x3
   opengl_ns.addConstant("GL_FLOAT_MAT2x3",                   new QoreBigIntNode(GL_FLOAT_MAT2x3));
#endif
#ifdef GL_FLOAT_MAT2x4
   opengl_ns.addConstant("GL_FLOAT_MAT2x4",                   new QoreBigIntNode(GL_FLOAT_MAT2x4));
#endif
#ifdef GL_FLOAT_MAT3x2
   opengl_ns.addConstant("GL_FLOAT_MAT3x2",                   new QoreBigIntNode(GL_FLOAT_MAT3x2));
#endif
#ifdef GL_FLOAT_MAT3x4
   opengl_ns.addConstant("GL_FLOAT_MAT3x4",                   new QoreBigIntNode(GL_FLOAT_MAT3x4));
#endif
#ifdef GL_FLOAT_MAT4x2
   opengl_ns.addConstant("GL_FLOAT_MAT4x2",                   new QoreBigIntNode(GL_FLOAT_MAT4x2));
#endif
#ifdef GL_FLOAT_MAT4x3
   opengl_ns.addConstant("GL_FLOAT_MAT4x3",                   new QoreBigIntNode(GL_FLOAT_MAT4x3));
#endif
#ifdef GL_SRGB
   opengl_ns.addConstant("GL_SRGB",                           new QoreBigIntNode(GL_SRGB));
#endif
#ifdef GL_SRGB8
   opengl_ns.addConstant("GL_SRGB8",                          new QoreBigIntNode(GL_SRGB8));
#endif
#ifdef GL_SRGB_ALPHA
   opengl_ns.addConstant("GL_SRGB_ALPHA",                     new QoreBigIntNode(GL_SRGB_ALPHA));
#endif
#ifdef GL_SRGB8_ALPHA8
   opengl_ns.addConstant("GL_SRGB8_ALPHA8",                   new QoreBigIntNode(GL_SRGB8_ALPHA8));
#endif
#ifdef GL_SLUMINANCE_ALPHA
   opengl_ns.addConstant("GL_SLUMINANCE_ALPHA",               new QoreBigIntNode(GL_SLUMINANCE_ALPHA));
#endif
#ifdef GL_SLUMINANCE8_ALPHA8
   opengl_ns.addConstant("GL_SLUMINANCE8_ALPHA8",             new QoreBigIntNode(GL_SLUMINANCE8_ALPHA8));
#endif
#ifdef GL_SLUMINANCE
   opengl_ns.addConstant("GL_SLUMINANCE",                     new QoreBigIntNode(GL_SLUMINANCE));
#endif
#ifdef GL_SLUMINANCE8
   opengl_ns.addConstant("GL_SLUMINANCE8",                    new QoreBigIntNode(GL_SLUMINANCE8));
#endif
#ifdef GL_COMPRESSED_SRGB
   opengl_ns.addConstant("GL_COMPRESSED_SRGB",               new QoreBigIntNode(GL_COMPRESSED_SRGB));
#endif
#ifdef GL_COMPRESSED_SRGB_ALPHA
   opengl_ns.addConstant("GL_COMPRESSED_SRGB_ALPHA",         new QoreBigIntNode(GL_COMPRESSED_SRGB_ALPHA));
#endif
#ifdef GL_COMPRESSED_SLUMINANCE
   opengl_ns.addConstant("GL_COMPRESSED_SLUMINANCE",         new QoreBigIntNode(GL_COMPRESSED_SLUMINANCE));
#endif
#ifdef GL_COMPRESSED_SLUMINANCE_ALPHA
   opengl_ns.addConstant("GL_COMPRESSED_SLUMINANCE_ALPHA",   new QoreBigIntNode(GL_COMPRESSED_SLUMINANCE_ALPHA));
#endif
}
