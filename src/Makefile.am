
if COND_SINGLE_COMPILATION_UNIT
OPENGL_SOURCES = single-compilation-unit.cc
else
OPENGL_SOURCES = opengl.cc opengl-constants.cc opengl-ext.cc opengl-glu.cc opengl-ext-constants.cc
endif

lib_LTLIBRARIES = opengl.la
opengl_la_SOURCES = $(OPENGL_SOURCES)
opengl_la_LDFLAGS = -module -avoid-version ${OPENGL_LIBS}

INCLUDES = -I$(top_srcdir)/include $(OPENGL_INCLUDES)

AM_CPPFLAGS = $(QORE_CPPFLAGS)
AM_CXXFLAGS = ${PTHREAD_CFLAGS}

if COND_PROFILE
AM_CXXFLAGS += -g -pg
else
if COND_DEBUG
AM_CXXFLAGS += -g
endif
endif

install-exec-hook:
	mv $(DESTDIR)$(libdir)/opengl.$(MODULE_SUFFIX) $(DESTDIR)$(libdir)/opengl-api-$(MODULE_API).qmod
	rm -f $(DESTDIR)$(libdir)/opengl.la $(DESTDIR)$(libdir)/opengl.a
