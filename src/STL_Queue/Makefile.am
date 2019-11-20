AUTOMAKE_OPTIONS = subdir-objects
ACLOCAL_AMFLAGS = $(ACLOCAL_AMFLAGS)

otherincludedir = $(includedir)/STL
otherinclude_HEADERS = ../STL_Headers/STL/STL_Queue.h
lib_LTLIBRARIES = libSTL_Queue.la

# libSTL_Queue.la
libSTL_Queue_la_LDFLAGS = -version-info 0:0:0
libSTL_Queue_la_SOURCES = STL_Queue.c $(otherinclude_HEADERS)
libSTL_Queue_la_LIBADD = ../STL_List/libSTL_List.la
libSTL_Queue_la_CFLAGS = $(AM_CFLAGS)