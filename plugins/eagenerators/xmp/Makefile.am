if HAVE_XMP

plugindir = $(libdir)/ferris/plugins/eagenerators

INCLUDES = -I$(top_srcdir)/plugins/eagenerators         \
	@XMP_CFLAGS@	                                \
	@SOPRANO_CFLAGS@	                        \
	-I$(srcdir)/../soprano                          \
	@CFLAGS@

plugin_LTLIBRARIES = libferrisxmp.la 
libferrisxmp_la_SOURCES = libferrisxmp.cpp
libferrisxmp_la_LDFLAGS = @GLIB_LIBS@ @XMP_LIBS@        \
	@SOPRANO_LIBS@                                  \
	@SHAREDSOPRANOEA_LA@                            \
	@LIBFERRIS_EAPLUGIN_LT_LINE@

endif
