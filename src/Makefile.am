AUTOMAKE_OPTIONS = subdir-objects
ACLOCAL_AMFLAGS = $(ACLOCAL_AMFLAGS)
SUBDIRS = STL_List STL_Stack STL_Queue STL_Algorithm STL_Vector

AM_CFLAGS = -I$(top_srcdir)/src

include_HEADERS = STL_Headers/STL.h STL_Headers/STL_Config.h
lib_LTLIBRARIES = libSTL.la

# libSTL.la
libSTL_la_LDFLAGS = -version-info 0:0:0
libSTL_la_LIBADD = STL_List/libSTL_List.la STL_Stack/libSTL_Stack.la STL_Queue/libSTL_Queue.la STL_Algorithm/libSTL_Algorithm.la STL_Vector/libSTL_Vector.la
libSTL_la_SOURCES = $(include_HEADERS)
libSTL_la_CFLAGS = $(AM_CFLAGS)