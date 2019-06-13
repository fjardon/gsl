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

AM_CPPFLAGS     = \
    -D_XOPEN_SOURCE_EXTENDED \
    -I$(top_builddir)/lib        -I$(top_srcdir)/lib \
    -I$(top_builddir)/src/libsfl -I$(top_srcdir)/src/libsfl \
    -I$(top_builddir)/src/libsmt -I$(top_srcdir)/src/libsmt \
    -I$(top_builddir)/src/gsl    -I$(top_srcdir)/src/gsl \
    -I$(top_builddir)/src/libtap -I$(top_srcdir)/src/libtap

SUBDIRS = lib

EXTRA_DIST = src/srcdir.txt

TEST_LOG_DRIVER = env AM_TAP_AWK='$(AWK)' $(SHELL) \
                  $(top_srcdir)/build-aux/tap-driver.sh

BUILT_SOURCES = \
    src/libsfl/sfl.h src/libsmt/smt3.h src/gsl/gsl.h \
    # end-of-built-sources

TESTS = \
    src/gsl/gsl-check \
    src/libsfl/sflbits-check \
    src/libsfl/sfldir-check \
    src/libsfl/sflfile-check \
    src/libsfl/sflfort-check \
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
SFL_H_HDRS = \
    $(top_srcdir)/src/libsfl/sflhead.h    $(top_srcdir)/src/libsfl/prelude.h  \
    $(top_srcdir)/src/libsfl/sflbits.h    $(top_srcdir)/src/libsfl/sflcomp.h  \
    $(top_srcdir)/src/libsfl/sflcons.h    $(top_srcdir)/src/libsfl/sflconv.h  \
    $(top_srcdir)/src/libsfl/sflcryp.h    $(top_srcdir)/src/libsfl/sfldate.h  \
    $(top_srcdir)/src/libsfl/sfldescr.h   $(top_srcdir)/src/libsfl/sflexdr.h  \
    $(top_srcdir)/src/libsfl/sflfile.h    $(top_srcdir)/src/libsfl/sflfind.h  \
    $(top_srcdir)/src/libsfl/sflfort.h    $(top_srcdir)/src/libsfl/sflheap.h  \
    $(top_srcdir)/src/libsfl/sfllang.h    $(top_srcdir)/src/libsfl/sfllbuf.h  \
    $(top_srcdir)/src/libsfl/sfllist.h    $(top_srcdir)/src/libsfl/sflnode.h  \
    $(top_srcdir)/src/libsfl/sflmath.h    $(top_srcdir)/src/libsfl/sflmem.h   \
    $(top_srcdir)/src/libsfl/sflmesg.h    $(top_srcdir)/src/libsfl/sflmime.h  \
    $(top_srcdir)/src/libsfl/sflnode.h    $(top_srcdir)/src/libsfl/sfldir.h   \
    $(top_srcdir)/src/libsfl/sflslot.h    $(top_srcdir)/src/libsfl/sflsock.h  \
    $(top_srcdir)/src/libsfl/sflmail.h    $(top_srcdir)/src/libsfl/sflsort.h  \
    $(top_srcdir)/src/libsfl/sflsha.h     $(top_srcdir)/src/libsfl/sflstr.h   \
    $(top_srcdir)/src/libsfl/sflsymb.h    $(top_srcdir)/src/libsfl/sflproc.h  \
    $(top_srcdir)/src/libsfl/sflprint.h   $(top_srcdir)/src/libsfl/sflsyst.h  \
    $(top_srcdir)/src/libsfl/sflsearch.h  $(top_srcdir)/src/libsfl/sflhttp.h  \
    $(top_srcdir)/src/libsfl/sflini.h     $(top_srcdir)/src/libsfl/sflenv.h   \
    $(top_srcdir)/src/libsfl/sfltok.h     $(top_srcdir)/src/libsfl/sfltree.h  \
    $(top_srcdir)/src/libsfl/sfltron.h    $(top_srcdir)/src/libsfl/sfluid.h   \
    $(top_srcdir)/src/libsfl/sflxml.h     $(top_srcdir)/src/libsfl/sflxmll.h  \
    $(top_srcdir)/src/libsfl/sflxmls.h

src/libsfl/sfl.h : $(SFL_H_HDRS)
	cat $(SFL_H_HDRS) > $@

src_libsfl_libsfl_la_SOURCES  = \
    src/libsfl/sflbits.c    src/libsfl/sflcomp.c  src/libsfl/sflcons.c   \
    src/libsfl/sflconv.c    src/libsfl/sflcryp.c  src/libsfl/sflcvbs.c   \
    src/libsfl/sflcvdp.c    src/libsfl/sflcvds.c  src/libsfl/sflcvns.c   \
    src/libsfl/sflcvsb.c    src/libsfl/sflcvsd.c  src/libsfl/sflcvsn.c   \
    src/libsfl/sflcvst.c    src/libsfl/sflcvtp.c  src/libsfl/sflcvts.c   \
    src/libsfl/sfldate.c    src/libsfl/sfldes.c   src/libsfl/sfldescr.c  \
    src/libsfl/sfldir.c     src/libsfl/sflenv.c   src/libsfl/sflexdr.c   \
    src/libsfl/sflfile.c    src/libsfl/sflfind.c  src/libsfl/sflfort.c   \
    src/libsfl/sflheap.c    src/libsfl/sflhttp.c  src/libsfl/sflini.c    \
    src/libsfl/sfllang.c    src/libsfl/sfllbuf.c  src/libsfl/sfllist.c   \
    src/libsfl/sflmail.c    src/libsfl/sflmath.c  src/libsfl/sflmem.c    \
    src/libsfl/sflmesg.c    src/libsfl/sflmime.c  src/libsfl/sflnode.c   \
    src/libsfl/sflprint.c   src/libsfl/sflproc.c  src/libsfl/sflscrit.c  \
    src/libsfl/sflsearch.c  src/libsfl/sflsha.c   src/libsfl/sflslot.c   \
    src/libsfl/sflsock.c    src/libsfl/sflsort.c  src/libsfl/sflstr.c    \
    src/libsfl/sflsymb.c    src/libsfl/sflsyst.c  src/libsfl/sfltok.c    \
    src/libsfl/sfltree.c    src/libsfl/sfltron.c  src/libsfl/sfluid.c    \
    src/libsfl/sflxml.c     src/libsfl/sflxmll.c  src/libsfl/sflxmls.c   \
    src/libsfl/sfl.h \
    $(SFL_H_HDRS) \
    # end-of-sources
src_libsfl_libsfl_la_CPPFLAGS = $(AM_CPPFLAGS) $(CODE_COVERAGE_CPPFLAGS)
src_libsfl_libsfl_la_CFLAGS   = $(CODE_COVERAGE_CFLAGS) $(PCRE_CFLAGS)
src_libsfl_libsfl_la_LIBADD   = $(CODE_COVERAGE_LIBS) $(PCRE_LIBS)

# libsmt: a private library
SMT3_H_HDRS = \
    $(top_srcdir)/src/libsmt/smthead.h  $(top_srcdir)/src/libsmt/smtlib.h    \
    $(top_srcdir)/src/libsmt/smtdefn.h  $(top_srcdir)/src/libsmt/smttime.h   \
    $(top_srcdir)/src/libsmt/smtserv.h  $(top_srcdir)/src/libsmt/smtmsg.h    \
    $(top_srcdir)/src/libsmt/smtsslm.h  $(top_srcdir)/src/libsmt/smtrdnsl.h  \
    $(top_srcdir)/src/libsmt/smtxlog.h

src/libsmt/smt3.h : $(SMT3_H_HDRS) src/libsfl/sfl.h
	cat $(SMT3_H_HDRS) > $@

SMT_HDRS = \
    src/libsmt/smtdefn.h   src/libsmt/smthead.h  src/libsmt/smtlib.h   \
    src/libsmt/smtmem.h    src/libsmt/smtmsg.h   src/libsmt/smtpriv.h  \
    src/libsmt/smtrdnsl.h  src/libsmt/smtserv.h  src/libsmt/smtsimu.h  \
    src/libsmt/smtsslm.h   src/libsmt/smttime.h  src/libsmt/smtxlog.h  \
    src/libsmt/sysman.h

src_libsmt_libsmt_la_SOURCES  = \
    src/libsmt/smtecho.c  src/libsmt/smtlib.c   src/libsmt/smtlog.c    \
    src/libsmt/smtmsg.c   src/libsmt/smtoper.c  src/libsmt/smtpipe.c   \
    src/libsmt/smtpop.c   src/libsmt/smtrdns.c  src/libsmt/smtrdnsl.c  \
    src/libsmt/smtserv.c  src/libsmt/smtsimu.c  src/libsmt/smtslot.c   \
    src/libsmt/smtsmtp.c  src/libsmt/smtsock.c  src/libsmt/smttime.c   \
    src/libsmt/smttran.c  src/libsmt/smttst1.c  src/libsmt/smttst2.c   \
    src/libsmt/smttst3.c  src/libsmt/smtxlog.c  \
    src/libsfl/sfl.h \
    src/libsmt/smt3.h \
    $(SMT_HDRS) \
    # end-of-sources
src_libsmt_libsmt_la_CPPFLAGS = $(AM_CPPFLAGS) $(CODE_COVERAGE_CPPFLAGS)
src_libsmt_libsmt_la_CFLAGS   = $(CODE_COVERAGE_CFLAGS) $(PCRE_CFLAGS)
src_libsmt_libsmt_la_LIBADD   = src/libsfl/libsfl.la \
                                $(CODE_COVERAGE_LIBS) $(PCRE_LIBS)

# libgsl: a private library
GSL_H_HDRS = \
    $(top_srcdir)/src/gsl/gghead.h   $(top_srcdir)/src/gsl/ggcomm.h   \
    $(top_srcdir)/src/gsl/ggpars.h   $(top_srcdir)/src/gsl/ggparsm.h  \
    $(top_srcdir)/src/gsl/ggscrp.h   $(top_srcdir)/src/gsl/ggscop.h   \
    $(top_srcdir)/src/gsl/ggobjt.h   $(top_srcdir)/src/gsl/ggsymb.h   \
    $(top_srcdir)/src/gsl/gggsl.h    $(top_srcdir)/src/gsl/ggcode.h   \
    $(top_srcdir)/src/gsl/ggcodem.h  $(top_srcdir)/src/gsl/ggfile.h   \
    $(top_srcdir)/src/gsl/ggstrn.h   $(top_srcdir)/src/gsl/ggenvt.h   \
    $(top_srcdir)/src/gsl/ggconv.h   $(top_srcdir)/src/gsl/ggmath.h   \
    $(top_srcdir)/src/gsl/ggsock.h   $(top_srcdir)/src/gsl/ggthrd.h   \
    $(top_srcdir)/src/gsl/ggxml.h    $(top_srcdir)/src/gsl/ggtime.h   \
    $(top_srcdir)/src/gsl/ggpcre.h   $(top_srcdir)/src/gsl/ggdiag.h   \
    $(top_srcdir)/src/gsl/ggproc.h

src/gsl/gsl.h : $(GSL_H_HDRS) src/libsmt/smt3.h src/libsfl/sfl.h
	cat $(GSL_H_HDRS) > $@

GSL_HDRS = \
    src/gsl/ggcode.h   src/gsl/ggcodem.h  src/gsl/ggcomm.h  src/gsl/ggconv.h  \
    src/gsl/ggdiag.h   src/gsl/ggenvt.h   src/gsl/ggfile.h  src/gsl/gggsl.h   \
    src/gsl/gghead.h   src/gsl/ggmath.h   src/gsl/ggobjt.h  src/gsl/ggpars.h  \
    src/gsl/ggparsm.h  src/gsl/ggpcre.h   src/gsl/ggpriv.h  src/gsl/ggproc.h  \
    src/gsl/ggscop.h   src/gsl/ggscrp.h   src/gsl/ggsock.h  src/gsl/ggstrn.h  \
    src/gsl/ggsymb.h   src/gsl/ggthrd.h   src/gsl/ggtime.h  src/gsl/ggxml.h   \
    src/gsl/gsl.h      src/gsl/version.h

src_gsl_libgsl_la_SOURCES  = \
    src/gsl/ggcode.c  src/gsl/ggcodem.c  src/gsl/ggcomm.c     \
    src/gsl/ggconv.c  src/gsl/ggdiag.c   src/gsl/ggenvt.c     \
    src/gsl/ggfile.c  src/gsl/gggsl.c    src/gsl/ggmath.c     \
    src/gsl/ggobjt.c  src/gsl/ggpars.c   src/gsl/ggparsm.c    \
    src/gsl/ggpcre.c  src/gsl/ggproc.c   src/gsl/ggscop.c     \
    src/gsl/ggscrp.c  src/gsl/ggsock.c   src/gsl/ggstrn.c     \
    src/gsl/ggsymb.c  src/gsl/ggthrd.c   src/gsl/ggtime.c     \
    src/gsl/ggxml.c   src/gsl/gsl.c      src/gsl/gsl-check.c  \
    src/libsfl/sfl.h  \
    src/libsmt/smt3.h  \
    src/gsl/gsl.h \
    $(GSL_HDRS) \
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
src_gsl_gsl_check_SOURCES  = src/gsl/gsl-check.c $(top_builddir)/src/gsl/gsl.h
src_gsl_gsl_check_CPPFLAGS = $(AM_CPPFLAGS) $(CODE_COVERAGE_CPPFLAGS)
src_gsl_gsl_check_CFLAGS   = $(CODE_COVERAGE_CFLAGS) $(PCRE_CFLAGS)
src_gsl_gsl_check_LDADD    = src/gsl/libgsl.la src/libtap/libtap.la \
                             $(CODE_COVERAGE_LIBS) $(PCRE_LIBS)

# sflbits-check: a private test program
src_libsfl_sflbits_check_SOURCES  = src/libsfl/sflbits-check.c src/libsfl/sflbits.h
src_libsfl_sflbits_check_CPPFLAGS = $(AM_CPPFLAGS) $(CODE_COVERAGE_CPPFLAGS)
src_libsfl_sflbits_check_CFLAGS   = $(CODE_COVERAGE_CFLAGS) $(PCRE_CFLAGS)
src_libsfl_sflbits_check_LDADD    = src/libsfl/libsfl.la src/libtap/libtap.la $(CODE_COVERAGE_LIBS) $(PCRE_LIBS)

# sfldir-check: a private test program
src_libsfl_sfldir_check_SOURCES  = src/libsfl/sfldir-check.c src/libsfl/sfldir.h
src_libsfl_sfldir_check_CPPFLAGS = $(AM_CPPFLAGS) $(CODE_COVERAGE_CPPFLAGS)
src_libsfl_sfldir_check_CFLAGS   = $(CODE_COVERAGE_CFLAGS) $(PCRE_CFLAGS)
src_libsfl_sfldir_check_LDADD    = src/libsfl/libsfl.la src/libtap/libtap.la $(CODE_COVERAGE_LIBS) $(PCRE_LIBS)

# sflfile-check: a private test program
src_libsfl_sflfile_check_SOURCES  = src/libsfl/sflfile-check.c src/libsfl/sflfile.h
src_libsfl_sflfile_check_CPPFLAGS = $(AM_CPPFLAGS) $(CODE_COVERAGE_CPPFLAGS)
src_libsfl_sflfile_check_CFLAGS   = $(CODE_COVERAGE_CFLAGS) $(PCRE_CFLAGS)
src_libsfl_sflfile_check_LDADD    = src/libsfl/libsfl.la src/libtap/libtap.la $(CODE_COVERAGE_LIBS) $(PCRE_LIBS)

# sflfort-check: a private test program
src_libsfl_sflfort_check_SOURCES  = src/libsfl/sflfort-check.c src/libsfl/sflfort.h
src_libsfl_sflfort_check_CPPFLAGS = $(AM_CPPFLAGS) $(CODE_COVERAGE_CPPFLAGS)
src_libsfl_sflfort_check_CFLAGS   = $(CODE_COVERAGE_CFLAGS) $(PCRE_CFLAGS)
src_libsfl_sflfort_check_LDADD    = src/libsfl/libsfl.la src/libtap/libtap.la $(CODE_COVERAGE_LIBS) $(PCRE_LIBS)


