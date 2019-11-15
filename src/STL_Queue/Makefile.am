AUTOMAKE_OPTIONS = subdir-objects
ACLOCAL_AMFLAGS = $(ACLOCAL_FLAGS)

STL_Queue_CFLAGS = $(CFLAGS) -Wall -Wextra -std=c90

otherincludedir = $(includedir)/STL
otherinclude_HEADERS = ../STL_Headers/STL/STL_Queue.h
lib_LTLIBRARIES = libSTL_Queue.la

# libSTL_Queue.la
libSTL_Queue_la_LDFLAGS = -version-info 0:0:0
libSTL_Queue_la_SOURCES = STL_Queue.c
libSTL_Queue_la_CFLAGS = $(STL_CFLAGS)