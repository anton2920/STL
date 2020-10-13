AUTOMAKE_OPTIONS = subdir-objects
ACLOCAL_AMFLAGS = $(ACLOCAL_AMFLAGS)
SUBDIRS = STL_Algorithm STL_Containers

AM_CFLAGS = -I$(top_srcdir)/src $(AM_CFLAGS)

include_HEADERS = STL_Headers/STL.h

internalincludedir = $(includedir)/STL/__internal
internalinclude_HEADERS = STL_Headers/STL/__internal/__STL_Config.h