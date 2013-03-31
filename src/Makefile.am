# We define the global AM_CPPFLAGS as everything we compile includes from these
# directories.
AM_CPPFLAGS = \
	-I$(top_srcdir) -I$(top_srcdir)/include \
	-I$(top_builddir)/include

#
# Main library
#
lib_LTLIBRARIES = libcl_cxx.la

libcl_cxx_la_SOURCES = \
	ecl/arguments.cc \
	ecl/numbers.cc \
	ecl/pointers.cc \
	ecl/strings.cc \
	ecl/symbols.cc \
	ecl/eval.cc

