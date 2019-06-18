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

AM_CPPFLAGS = -D_XOPEN_SOURCE_EXTENDED \
			  -I$(top_builddir)/lib -I$(top_srcdir)/lib

TEST_LOG_DRIVER = env AM_TAP_AWK='$(AWK)' $(SHELL) \
                  $(top_srcdir)/build-aux/tap-driver.sh

SUBDIRS            = lib
BUILT_SOURCES      =
CLEANFILES         = generated
EXTRA_DIST         = src/srcdir.txt
GENERATION_STAMPS  =
TESTS              =

noinst_LTLIBRARIES =
bin_PROGRAMS       =
check_PROGRAMS     =

# extra target for code generation
generated : $(GENERATION_STAMPS)
	touch $@

# include all products from this project
include src/libtap/product.am
include src/libsfl/product.am
include src/libsmt/product.am
include src/gsl/product.am

CLEANFILES        += $(GENERATION_STAMPS)

