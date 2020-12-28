AUTOMAKE_OPTIONS = subdir-objects
ACLOCAL_AMFLAGS = $(ACLOCAL_AMFLAGS)

otherincludedir = $(includedir)/STL
otherinclude_HEADERS = ../../STL_Headers/STL/STL_String.h

internaldir = $(includedir)/STL/__internal
internal_HEADERS = ../../STL_Headers/STL/__internal/__STL_Basic_string.h

lib_LTLIBRARIES = libSTL_String.la

# libSTL_String.la
libSTL_String_la_LDFLAGS = -version-info 0:0:0
libSTL_String_la_SOURCES = STL_String.c $(otherinclude_HEADERS) $(internal_HEADERS)
libSTL_String_la_CFLAGS = $(AM_CFLAGS)
