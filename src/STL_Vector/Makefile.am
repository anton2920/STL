AUTOMAKE_OPTIONS = subdir-objects
ACLOCAL_AMFLAGS = $(ACLOCAL_AMFLAGS)

otherincludedir = $(includedir)/STL
otherinclude_HEADERS = ../STL_Headers/STL/STL_Vector.h
lib_LTLIBRARIES = libSTL_Vector.la

# libSTL_Vector.la
libSTL_Vector_la_LDFLAGS = -version-info 0:0:0
libSTL_Vector_la_SOURCES = STL_Vector.c
libSTL_Vector_la_CFLAGS = $(AM_CFLAGS)