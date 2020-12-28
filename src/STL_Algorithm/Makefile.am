AUTOMAKE_OPTIONS = subdir-objects
ACLOCAL_AMFLAGS = $(ACLOCAL_AMFLAGS)

otherincludedir = $(includedir)/STL
otherinclude_HEADERS = ../STL_Headers/STL/STL_Algorithm.h
lib_LTLIBRARIES = libSTL_Algorithm.la

# libSTL_Algorithm.la
libSTL_Algorithm_la_LDFLAGS = -version-info 0:0:0
libSTL_Algorithm_la_SOURCES = STL_Algorithm_sorting.c STL_Algorithm_advanced_sorting.c STL_Algorithm_compare.c STL_Algorithm_other.c $(otherinclude_HEADERS)
libSTL_Algorithm_la_CFLAGS = $(AM_CFLAGS)
