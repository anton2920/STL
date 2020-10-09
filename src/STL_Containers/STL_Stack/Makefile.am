AUTOMAKE_OPTIONS = subdir-objects
ACLOCAL_AMFLAGS = $(ACLOCAL_AMFLAGS)

otherincludedir = $(includedir)/STL
otherinclude_HEADERS = ../../STL_Headers/STL/STL_Stack.h
lib_LTLIBRARIES = libSTL_Stack.la

# libSTL_Stack.la
libSTL_Stack_la_LDFLAGS = -version-info 0:0:0
libSTL_Stack_la_SOURCES = STL_Stack.c $(otherinclude_HEADERS) ../STL_Headers/STL/__STL_List_type.h
libSTL_Stack_la_LIBADD = ../STL_List/libSTL_List.la
libSTL_Stack_la_CFLAGS = $(AM_CFLAGS)