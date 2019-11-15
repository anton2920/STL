AUTOMAKE_OPTIONS = subdir-objects
ACLOCAL_AMFLAGS = $(ACLOCAL_AMFLAGS)

otherincludedir = $(includedir)/STL
otherinclude_HEADERS = ../STL_Headers/STL/STL_Stack.h
lib_LTLIBRARIES = libSTL_Stack.la

# libSTL_Stack.la
libSTL_Stack_la_LDFLAGS = -version-info 0:0:0
libSTL_Stack_la_SOURCES = STL_Stack.c
libSTL_Stack_la_CFLAGS = $(AM_CFLAGS)