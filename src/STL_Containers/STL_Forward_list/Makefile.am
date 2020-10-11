AUTOMAKE_OPTIONS = subdir-objects
ACLOCAL_AMFLAGS = $(ACLOCAL_AMFLAGS)

otherincludedir = $(includedir)/STL
otherinclude_HEADERS = ../../STL_Headers/STL/STL_Forward_list.h

internaldir = $(includedir)/STL/__internal
internal_HEADERS = ../../STL_Headers/STL/__internal/__STL_Forward_list_type.h

lib_LTLIBRARIES = libSTL_List.la

# libSTL_List.la
libSTL_List_la_LDFLAGS = -version-info 0:0:0
libSTL_List_la_SOURCES = STL_Forward_list.c $(otherinclude_HEADERS) $(internal_HEADERS)
libSTL_List_la_CFLAGS = $(AM_CFLAGS)