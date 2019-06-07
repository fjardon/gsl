#*===========================================================================*
#*                                                                           *
#*  Makefile.am - Automake configuration for the project                     *
#*                                                                           *
#*  Copyright (c) 2019 Frederic Jardon  <frederic.jardon@gmail.com>          *
#*                                                                           *
#*  ------------------ GPL Licensed Source Code ------------------           *
#*  Frederic Jardon makes this software available under the GNU              *
#*  General Public License (GPL) license for open source projects.           *
#*  For details of the GPL license please see www.gnu.org or read            *
#*  the file license.gpl provided in this package.                           *
#*                                                                           *
#*  This program is free software; you can redistribute it and/or            *
#*  modify it under the terms of the GNU General Public License as           *
#*  published by the Free Software Foundation; either version 3 of           *
#*  the License, or (at your option) any later version.                      *
#*                                                                           *
#*  This program is distributed in the hope that it will be useful,          *
#*  but WITHOUT ANY WARRANTY; without even the implied warranty of           *
#*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the            *
#*  GNU General Public License for more details.                             *
#*                                                                           *
#*  You should have received a copy of the GNU General Public                *
#*  License along with this program in the file 'license.gpl'; if            *
#*  not, see <http://www.gnu.org/licenses/>.                                 *
#*  --------------------------------------------------------------           *
#*===========================================================================*
ACLOCAL_AMFLAGS = -I m4
include $(top_srcdir)/aminclude_static.am

AM_CPPFLAGS     = -D_XOPEN_SOURCE_EXTENDED \
                  -I$(top_builddir)/lib -I$(top_srcdir)/lib \
                  -I$(top_builddir)/src/libsfl -I$(top_srcdir)/src/libsfl \
                  -I$(top_builddir)/src/libsmt -I$(top_srcdir)/src/libsmt \
                  -I$(top_builddir)/src/libgsl -I$(top_srcdir)/src/libgsl \
                  -I$(top_builddir)/src/libtap -I$(top_srcdir)/src/libtap

SUBDIRS = lib

EXTRA_DIST = m4/gnulib-cache.m4

TEST_LOG_DRIVER = env AM_TAP_AWK='$(AWK)' $(SHELL) \
                  $(top_srcdir)/build-aux/tap-driver.sh

TESTS = src/gsl/gsl-check \
		src/libsfl/sflbits-check \
		src/libsfl/sfldir-check \
		src/libsfl/sflfile-check \
		# end-of-tests

noinst_LTLIBRARIES = \
                     src/gsl/libgsl.la \
                     src/libsfl/libsfl.la \
                     src/libsmt/libsmt.la \
                     src/libtap/libtap.la \
					 # end-of-convenience-library

bin_PROGRAMS = src/gsl/gsl

check_PROGRAMS = $(TESTS)

# libsfl: a private library
src_libsfl_libsfl_la_SOURCES  = src/libsfl/sflbits.c src/libsfl/sflcomp.c src/libsfl/sflcons.c \
                                src/libsfl/sflconv.c src/libsfl/sflcryp.c src/libsfl/sflcvbs.c \
                                src/libsfl/sflcvdp.c src/libsfl/sflcvds.c src/libsfl/sflcvns.c \
                                src/libsfl/sflcvsb.c src/libsfl/sflcvsd.c src/libsfl/sflcvsn.c \
                                src/libsfl/sflcvst.c src/libsfl/sflcvtp.c src/libsfl/sflcvts.c \
                                src/libsfl/sfldate.c src/libsfl/sfldes.c src/libsfl/sfldescr.c \
                                src/libsfl/sfldir.c src/libsfl/sfldir-check.c src/libsfl/sflenv.c \
                                src/libsfl/sflexdr.c src/libsfl/sflfile.c src/libsfl/sflfile-check.c \
                                src/libsfl/sflfind.c src/libsfl/sflfort.c src/libsfl/sflheap.c \
                                src/libsfl/sflhttp.c src/libsfl/sflini.c src/libsfl/sfllang.c \
                                src/libsfl/sfllbuf.c src/libsfl/sfllist.c src/libsfl/sflmail.c \
                                src/libsfl/sflmath.c src/libsfl/sflmem.c src/libsfl/sflmesg.c \
                                src/libsfl/sflmime.c src/libsfl/sflnode.c src/libsfl/sflprint.c \
                                src/libsfl/sflproc.c src/libsfl/sflscrit.c src/libsfl/sflsearch.c \
                                src/libsfl/sflsha.c src/libsfl/sflslot.c src/libsfl/sflsock.c \
                                src/libsfl/sflsort.c src/libsfl/sflstr.c src/libsfl/sflsymb.c \
                                src/libsfl/sflsyst.c src/libsfl/sfltok.c src/libsfl/sfltree.c \
                                src/libsfl/sfltron.c src/libsfl/sfluid.c src/libsfl/sflxml.c \
                                src/libsfl/sflxmll.c src/libsfl/sflxmls.c \
                                # end-of-sources
src_libsfl_libsfl_la_CPPFLAGS = $(AM_CPPFLAGS) $(CODE_COVERAGE_CPPFLAGS)
src_libsfl_libsfl_la_CFLAGS   = $(CODE_COVERAGE_CFLAGS) $(PCRE_CFLAGS)
src_libsfl_libsfl_la_LIBADD   = $(CODE_COVERAGE_LIBS) $(PCRE_LIBS)

# sfl.h: regeneration rule
SFL_HDRS = src/libsfl/sflhead.h src/libsfl/prelude.h src/libsfl/sflbits.h src/libsfl/sflcomp.h src/libsfl/sflcons.h \
           src/libsfl/sflconv.h src/libsfl/sflcryp.h src/libsfl/sfldate.h src/libsfl/sfldescr.h src/libsfl/sflexdr.h \
           src/libsfl/sflfile.h src/libsfl/sflfind.h src/libsfl/sflfort.h src/libsfl/sflheap.h src/libsfl/sfllang.h \
           src/libsfl/sfllbuf.h src/libsfl/sfllist.h src/libsfl/sflnode.h src/libsfl/sflmath.h src/libsfl/sflmem.h \
           src/libsfl/sflmesg.h src/libsfl/sflmime.h src/libsfl/sflnode.h src/libsfl/sfldir.h src/libsfl/sflslot.h \
           src/libsfl/sflsock.h src/libsfl/sflmail.h src/libsfl/sflsort.h src/libsfl/sflsha.h src/libsfl/sflstr.h \
           src/libsfl/sflsymb.h src/libsfl/sflproc.h src/libsfl/sflprint.h src/libsfl/sflsyst.h src/libsfl/sflsearch.h \
           src/libsfl/sflhttp.h src/libsfl/sflini.h src/libsfl/sflenv.h src/libsfl/sfltok.h src/libsfl/sfltree.h \
           src/libsfl/sfltron.h src/libsfl/sfluid.h src/libsfl/sflxml.h src/libsfl/sflxmll.h src/libsfl/sflxmls.h
src/libsfl/sfl.h : $(SFL_HDRS)
	cat $(SFL_HDRS) > $@

# libsmt: a private library
src_libsmt_libsmt_la_SOURCES  = src/libsmt/smtecho.c src/libsmt/smtlib.c src/libsmt/smtlog.c \
                                src/libsmt/smtmsg.c src/libsmt/smtoper.c src/libsmt/smtpipe.c \
                                src/libsmt/smtpop.c src/libsmt/smtrdns.c src/libsmt/smtrdnsl.c \
                                src/libsmt/smtserv.c src/libsmt/smtsimu.c src/libsmt/smtslot.c \
                                src/libsmt/smtsmtp.c src/libsmt/smtsock.c src/libsmt/smttime.c \
                                src/libsmt/smttran.c src/libsmt/smttst1.c src/libsmt/smttst2.c \
                                src/libsmt/smttst3.c src/libsmt/smtxlog.c \
                                # end-of-sources
src_libsmt_libsmt_la_CPPFLAGS = $(AM_CPPFLAGS) $(CODE_COVERAGE_CPPFLAGS)
src_libsmt_libsmt_la_CFLAGS   = $(CODE_COVERAGE_CFLAGS) $(PCRE_CFLAGS)
src_libsmt_libsmt_la_LIBADD   = src/libsfl/libsfl.la \
								$(CODE_COVERAGE_LIBS) $(PCRE_LIBS)

# libgsl: a private library
src_gsl_libgsl_la_SOURCES  = src/gsl/ggcode.c src/gsl/ggcodem.c src/gsl/ggcomm.c src/gsl/ggconv.c \
                             src/gsl/ggdiag.c src/gsl/ggenvt.c src/gsl/ggfile.c src/gsl/gggsl.c \
                             src/gsl/ggmath.c src/gsl/ggobjt.c src/gsl/ggpars.c src/gsl/ggparsm.c \
                             src/gsl/ggpcre.c src/gsl/ggproc.c src/gsl/ggscop.c src/gsl/ggscrp.c \
                             src/gsl/ggsock.c src/gsl/ggstrn.c src/gsl/ggsymb.c src/gsl/ggthrd.c \
                             src/gsl/ggtime.c src/gsl/ggxml.c src/gsl/gsl.c src/gsl/gsl-check.c \
                             # end-of-sources
src_gsl_libgsl_la_CPPFLAGS = $(AM_CPPFLAGS) $(CODE_COVERAGE_CPPFLAGS)
src_gsl_libgsl_la_CFLAGS   = $(CODE_COVERAGE_CFLAGS) $(PCRE_CFLAGS)
src_gsl_libgsl_la_LIBADD   = src/libsfl/libsfl.la src/libsmt/libsmt.la \
							 $(CODE_COVERAGE_LIBS) $(PCRE_LIBS)

# libtap: a private library
src_libtap_libtap_la_SOURCES  = src/libtap/tap.h src/libtap/tap.c
src_libtap_libtap_la_CPPFLAGS =
src_libtap_libtap_la_CFLAGS   =
src_libtap_libtap_la_LIBADD   =

# gsl: a public program
src_gsl_gsl_SOURCES = src/gsl/gsl.c
src_gsl_gsl_CFLAGS  = $(PCRE_CFLAGS)
src_gsl_gsl_LDADD   = src/gsl/libgsl.la src/libsmt/libsmt.la src/libsfl/libsfl.la \
					  $(PCRE_LIBS)

# gsl-check: a private test program
src_gsl_gsl_check_SOURCES  = src/gsl/gsl-check.c
src_gsl_gsl_check_CPPFLAGS = $(AM_CPPFLAGS) $(CODE_COVERAGE_CPPFLAGS)
src_gsl_gsl_check_CFLAGS   = $(CODE_COVERAGE_CFLAGS) $(PCRE_CFLAGS)
src_gsl_gsl_check_LDADD    = src/gsl/libgsl.la src/libtap/libtap.la \
                             $(CODE_COVERAGE_LIBS) $(PCRE_LIBS)

# sflbits-check: a private test program
src_libsfl_sflbits_check_SOURCES  = src/libsfl/sflbits-check.c
src_libsfl_sflbits_check_CPPFLAGS = $(AM_CPPFLAGS) $(CODE_COVERAGE_CPPFLAGS)
src_libsfl_sflbits_check_CFLAGS   = $(CODE_COVERAGE_CFLAGS) $(PCRE_CFLAGS)
src_libsfl_sflbits_check_LDADD    = src/libsfl/libsfl.la src/libtap/libtap.la $(CODE_COVERAGE_LIBS) $(PCRE_LIBS)

# sfldir-check: a private test program
src_libsfl_sfldir_check_SOURCES  = src/libsfl/sfldir-check.c
src_libsfl_sfldir_check_CPPFLAGS = $(AM_CPPFLAGS) $(CODE_COVERAGE_CPPFLAGS)
src_libsfl_sfldir_check_CFLAGS   = $(CODE_COVERAGE_CFLAGS) $(PCRE_CFLAGS)
src_libsfl_sfldir_check_LDADD    = src/libsfl/libsfl.la src/libtap/libtap.la $(CODE_COVERAGE_LIBS) $(PCRE_LIBS)

# sflfile-check: a private test program
src_libsfl_sflfile_check_SOURCES  = src/libsfl/sflfile-check.c
src_libsfl_sflfile_check_CPPFLAGS = $(AM_CPPFLAGS) $(CODE_COVERAGE_CPPFLAGS)
src_libsfl_sflfile_check_CFLAGS   = $(CODE_COVERAGE_CFLAGS) $(PCRE_CFLAGS)
src_libsfl_sflfile_check_LDADD    = src/libsfl/libsfl.la src/libtap/libtap.la $(CODE_COVERAGE_LIBS) $(PCRE_LIBS)


