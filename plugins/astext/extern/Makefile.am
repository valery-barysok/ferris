
plugindir = @FERRIS_AS_TEXT_PLUGIN_DIR@

INCLUDES = @CFLAGS@

plugin_LTLIBRARIES = libastextextern.la 
libastextextern_la_SOURCES = libastextextern.cpp
libastextextern_la_LDFLAGS = @GLIB_LIBS@   \
	@LIBFERRIS_ASTEXTPLUGIN_LT_LINE@


bin_SCRIPTS = $(srcdir)/*.sh
EXTRA_DIST = $(srcdir)/*.sh


