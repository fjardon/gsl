#!/usr/bin/env sh
#*===========================================================================*
#*                                                                           *
#*  autogen.sh - Autoconf bootstrap script for the project                   *
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

# This script will install the autotools infrastructure in this project
# This is solely needed after a fresh checkout of the project.
# Usually tarball distribution includes the autotool files and need not run
# this script.
#
# Running the script with the --gnulib flag will run just enough script to
# import the gnulib modules
#
# Running the script without arguments will bootstrap the gnulib and autotools
# infrastructure

set -e

# gnulib-tool --import calls should appear first

# References:
# - https://www.gnu.org/software/gnulib/manual/html_node/Initial-import.html
# - https://www.gnu.org/software/gnulib/manual/html_node/Modified-imports.html
#
# Example `gnulib-tool` invokation
#
# gnulib-tool --import posix_spawn
# gnulib-tool --import pipe


# Sanity check: we should run inside the source directory
SRCDIR=`dirname "$0"`
cd "${SRCDIR}"

# Sanity check: we should be executable
[ -x "$0" ] || chmod a+x "$0"

# Sanity check: when running autotools there should be a lib/Makefile.am file
# in case it is not present (after a fresh git checkout) create an empty one.
#
# Normally gnulib-import tool will create one if we depend on at least a single
# gnulib module. But in case we do not use gnulib, the file will not be created.
[ -e ./lib/Makefile.am ] || touch ./lib/Makefile.am

# Sanity check: the scripts in build-aux/ should be executable. This is not
# always the case after a fresh git checkout.
[ -x ./vim-project            ] || chmod a+x ./vim-project
[ -x ./build-aux/build        ] || chmod a+x ./build-aux/build
[ -x ./build-aux/travis-setup ] || chmod a+x ./build-aux/travis-setup

# Handle the nominal case when doing a full autotool setup
if [ "$1" != "--gnulib" ]
then
    aclocal
    autoreconf -i
    automake --add-missing
    autoconf
else
    # Handle the specific case of updating only gnulib
    autoreconf
    automake
fi

