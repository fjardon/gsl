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
                  -I$(top_builddir)/lib -I$(top_srcdir)/lib

SUBDIRS = lib

EXTRA_DIST = m4/gnulib-cache.m4

TEST_LOG_DRIVER = env AM_TAP_AWK='$(AWK)' $(SHELL) \
                  $(top_srcdir)/build-aux/tap-driver.sh

TESTS = src/gsl-check \
		src/sfldir-check \
		src/sflfile-check \
		# end-of-tests

noinst_LTLIBRARIES = src/libgsl.la src/libtap.la

bin_PROGRAMS = src/gsl

check_PROGRAMS = $(TESTS)

# libgsl: a private library
src_libgsl_la_SOURCES  = src/ggobjt.c src/ggcomm.c src/ggscop.c src/ggcode.c src/ggcodem.c src/ggpars.c src/ggparsm.c src/ggconv.c src/ggdiag.c src/ggenvt.c src/ggfile.c src/gggsl.c src/ggmath.c src/ggpcre.c src/ggproc.c src/ggscrp.c src/ggsock.c src/ggstrn.c src/ggsymb.c src/ggthrd.c src/ggtime.c src/ggxml.c src/sflbits.c src/sflcvds.c src/sflcvts.c src/sflfile.c src/sfllbuf.c src/sflnode.c src/sflsock.c src/sfltron.c src/smtlog.c src/smtmsg.c src/smtsimu.c src/smttst2.c src/sflcomp.c src/sflcvns.c src/sfldate.c src/sflfind.c src/sfllist.c src/sflprint.c src/sflsort.c src/sfluid.c src/smtoper.c src/smtslot.c src/smttst3.c src/sflcons.c src/sflcvsb.c src/sfldes.c src/sflfort.c src/sflmail.c src/sflproc.c src/sflstr.c src/sflxml.c src/smtpipe.c src/smtsmtp.c src/smtxlog.c src/sflconv.c src/sflcvsd.c src/sfldescr.c src/sflheap.c src/sflmath.c src/sflscrit.c src/sflsymb.c src/sflxmll.c src/smtpop.c src/smtsock.c src/sflcryp.c src/sflcvsn.c src/sfldir.c src/sflhttp.c src/sflmem.c src/sflsearch.c src/sflsyst.c src/sflxmls.c src/smtrdns.c src/smttime.c src/sflcvbs.c src/sflcvst.c src/sflenv.c src/sflini.c src/sflmesg.c src/sflsha.c src/sfltok.c src/smtecho.c src/smtrdnsl.c src/smttran.c src/sflcvdp.c src/sflcvtp.c src/sflexdr.c src/sfllang.c src/sflmime.c src/sflslot.c src/sfltree.c src/smtlib.c src/smtserv.c src/smttst1.c
src_libgsl_la_CPPFLAGS = $(CODE_COVERAGE_CPPFLAGS)
src_libgsl_la_CFLAGS   = $(CODE_COVERAGE_CFLAGS) $(PCRE_CFLAGS)
src_libgsl_la_LIBADD   = $(CODE_COVERAGE_LIBS) $(PCRE_LIBS)

# libtap: a private library
src_libtap_la_SOURCES  = src/tap.h src/tap.c
src_libtap_la_CPPFLAGS =
src_libtap_la_CFLAGS   =
src_libtap_la_LIBADD   =

# gsl: a public program
src_gsl_SOURCES = src/gsl.c
src_gsl_CFLAGS  = $(PCRE_CFLAGS)
src_gsl_LDADD   = src/libgsl.la $(PCRE_LIBS)

# gsl-check: a private test program
src_gsl_check_SOURCES  = src/gsl-check.c
src_gsl_check_CPPFLAGS = $(CODE_COVERAGE_CPPFLAGS)
src_gsl_check_CFLAGS   = $(CODE_COVERAGE_CFLAGS) $(PCRE_CFLAGS)
src_gsl_check_LDADD    = src/libgsl.la src/libtap.la $(CODE_COVERAGE_LIBS) $(PCRE_LIBS)

# sfldir-check: a private test program
src_sfldir_check_SOURCES  = src/sfldir-check.c
src_sfldir_check_CPPFLAGS = $(CODE_COVERAGE_CPPFLAGS)
src_sfldir_check_CFLAGS   = $(CODE_COVERAGE_CFLAGS) $(PCRE_CFLAGS)
src_sfldir_check_LDADD    = src/libgsl.la src/libtap.la $(CODE_COVERAGE_LIBS) $(PCRE_LIBS)

# sflfile-check: a private test program
src_sflfile_check_SOURCES  = src/sflfile-check.c
src_sflfile_check_CPPFLAGS = $(CODE_COVERAGE_CPPFLAGS)
src_sflfile_check_CFLAGS   = $(CODE_COVERAGE_CFLAGS) $(PCRE_CFLAGS)
src_sflfile_check_LDADD    = src/libgsl.la src/libtap.la $(CODE_COVERAGE_LIBS) $(PCRE_LIBS)

# sfl.h: regeneration rule
SFL_HDRS = src/sflhead.h \
           src/prelude.h \
           src/sflbits.h \
           src/sflcomp.h \
           src/sflcons.h \
           src/sflconv.h \
           src/sflcryp.h \
           src/sfldate.h \
           src/sfldescr.h \
           src/sflexdr.h \
           src/sflfile.h \
           src/sflfind.h \
           src/sflfort.h \
           src/sflheap.h \
           src/sfllang.h \
           src/sfllbuf.h \
           src/sfllist.h \
           src/sflnode.h \
           src/sflmath.h \
           src/sflmem.h \
           src/sflmesg.h \
           src/sflmime.h \
           src/sflnode.h \
           src/sfldir.h \
           src/sflslot.h \
           src/sflsock.h \
           src/sflmail.h \
           src/sflsort.h \
           src/sflsha.h \
           src/sflstr.h \
           src/sflsymb.h \
           src/sflproc.h \
           src/sflprint.h \
           src/sflsyst.h \
           src/sflsearch.h \
           src/sflhttp.h \
           src/sflini.h \
           src/sflenv.h \
           src/sfltok.h \
           src/sfltree.h \
           src/sfltron.h \
           src/sfluid.h \
           src/sflxml.h \
           src/sflxmll.h \
           src/sflxmls.h

src/sfl.h : $(SFL_HDRS)
	cat $(SFL_HDRS) > $@


