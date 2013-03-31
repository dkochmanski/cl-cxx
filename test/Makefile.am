# We define the global AM_CPPFLAGS as everything we compile includes from these
# directories.
AM_CPPFLAGS = -I$(top_srcdir) -I$(top_srcdir)/include -I$(top_srcdir)/src \
	-I$(top_builddir)/include -I"@GTEST_DIR@/include" -I"@GTEST_DIR@" 

# All Google Test headers.  Usually you shouldn't change this
# definition.
GTEST_LDFLAGS = libgtest_main.a $(LDFLAGS) -lpthread

#
# No rules here yet
#
TESTS =
check_PROGRAMS =
noinst_LIBRARIES =

AM_TESTS_FD_REDIRECT = --gtest_death_test_style=threadsafe

#####################################################################
# TENSOR LIBRARY TESTS
#

if HAVE_GTEST
#TESTS += test_refcount
#check_PROGRAMS += test_refcount
#test_refcount_SOURCES = test_refcount.cc
#test_refcount_LDADD = libtestmain.a ../src/libtensor.la $(GTEST_LDFLAGS) #-lstdc++
endif

######################################################################
#
# Build the Google Test library. The way this library has changed: we now have to
# compile it for every project. However, since we have downloaded the library, we
# cannot rely on automake and we have to generate the sources.
#

if HAVE_GTEST
noinst_LIBRARIES += libgtest.a libgtest_main.a
libgtest_a_SOURCES = gtest-all.cc
libgtest_main_a_SOURCES = gtest-all.cc gtest_main.cc
endif

gtest-all.cc gtest_main.cc :
	cp @GTEST_DIR@/src/$@ .

CLEANFILES = *.xml report_nfailures
