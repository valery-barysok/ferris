
if BUILD_DBUS_MOUNTING

plugindir = $(libdir)/ferris/plugins/context

INCLUDES = -I$(top_srcdir)/plugins/context @QTDBUS_CFLAGS@ @GLIB_CFLAGS@ @CFLAGS@

plugin_LTLIBRARIES               = libferrisdbus.la libferrisdbus_factory.la
libferrisdbus_factory_la_SOURCES = libferrisdbus_factory.cpp
libferrisdbus_factory_la_LIBADD  = @LIBFERRIS_PLUGIN_FACTORY_LIBADD@
libferrisdbus_factory_la_LDFLAGS = @LIBFERRIS_PLUGIN_LT_LINE@
libferrisdbus_la_SOURCES         = libferrisdbus.cpp 


libferrisdbus_la_LDFLAGS =                            \
	@GLIB_LIBS@              	              \
	@QTDBUS_LIBS@                                 \
	@LIBFERRIS_PLUGIN_LT_LINE@                        


endif
