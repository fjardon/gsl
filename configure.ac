#*===========================================================================*
#*                                                                           *
#*  configure.ac - Autoconf configuration for the project                    *
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
#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([gsl], [4.1.6], [frederic.jardon@gmail.com])
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_SRCDIR([src/srcdir.txt])
AM_INIT_AUTOMAKE([-Wall gnu subdir-objects])
AM_SILENT_RULES([yes])
AM_MAINTAINER_MODE([enable])

# Detect system
AC_CANONICAL_HOST
case $host_os in
    *cygwin* ) CYGWIN=yes;;
           * ) CYGWIN=no;;
esac

# Checks for programs.
AC_PROG_INSTALL
AC_PROG_AWK
AC_PROG_CC
AM_PROG_CC_C_O
AM_PROG_AR
LT_INIT([win32-dll])
PKG_PROG_PKG_CONFIG
PKG_CHECK_MODULES([PCRE], [libpcre >= 6.6])

AX_CODE_COVERAGE

# Checks for libraries.

# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

# Defines custom macros

# Defines custom macros

# Outputs substituted files
AC_CONFIG_FILES([Makefile lib/Makefile])
AC_REQUIRE_AUX_FILE([tap-driver.sh])
AC_OUTPUT
