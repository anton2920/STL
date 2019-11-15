AUTOMAKE_OPTIONS = subdir-objects
ACLOCAL_AMFLAGS = $(ACLOCAL_FLAGS)
SUBDIRS = STL_List STL_Stack STL_Queue STL_Algorithm

STL_CFLAGS = $(CFLAGS) -Wall -Wextra -std=c90

include_HEADERS = STL_Headers/STL.h STL_Headers/STL_Config.h
lib_LTLIBRARIES = libSTL.la

# libSTL.la
libSTL_la_LDFLAGS = -version-info 0:0:0
libSTL_la_SOURCES = STL_List/libSTL_Stack.la STL_List/libSTL_Queue.la STL_Algorithms/libSTL_Algorithm.la
libSTL_la_CFLAGS = $(STL_CFLAGS)