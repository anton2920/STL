AUTOMAKE_OPTIONS = subdir-objects
ACLOCAL_AMFLAGS = $(ACLOCAL_FLAGS)

STL_List_CFLAGS = $(CFLAGS) -Wall -Wextra -std=c90

otherincludedir = $(includedir)/STL
otherinclude_HEADERS = ../STL_Headers/STL/STL_List.h
lib_LTLIBRARIES = libSTL_List.la

# libSTL_List.la
libSTL_List_la_LDFLAGS = -version-info 0:0:0
libSTL_List_la_SOURCES = STL_List.c
libSTL_List_la_CFLAGS = $(STL_CFLAGS)