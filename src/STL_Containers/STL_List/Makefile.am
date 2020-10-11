AUTOMAKE_OPTIONS = subdir-objects
ACLOCAL_AMFLAGS = $(ACLOCAL_AMFLAGS)

otherincludedir = $(includedir)/STL
otherinclude_HEADERS = ../../STL_Headers/STL/STL_List.h

internaldir = $(includedir)/STL/__internal
internal_HEADERS = ../../STL_Headers/STL/__internal/__STL_List_type.h

lib_LTLIBRARIES = libSTL_List.la

# libSTL_List.la
libSTL_List_la_LDFLAGS = -version-info 0:0:0
libSTL_List_la_SOURCES = STL_List.c $(otherinclude_HEADERS) $(internaldir_HEADERS)
libSTL_List_la_CFLAGS = $(AM_CFLAGS)