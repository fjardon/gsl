/*===========================================================================*
 *                                                                           *
 *  sflfile-check.c - Unit tests for sflfile API                             *
 *                                                                           *
 *  Copyright (c) 2019 Frederic Jardon <frederic.jardon@gmail.com>           *
 *                                                                           *
 *  ------------------ GPL Licensed Source Code ------------------           *
 *  Frederic Jardon makes this software available under the GNU              *
 *  General Public License (GPL) license for open source projects.           *
 *  For details of the GPL license please see www.gnu.org or read            *
 *  the file license.gpl provided in this package.                           *
 *                                                                           *
 *  This program is free software; you can redistribute it and/or            *
 *  modify it under the terms of the GNU General Public License as           *
 *  published by the Free Software Foundation; either version 3 of           *
 *  the License, or (at your option) any later version.                      *
 *                                                                           *
 *  This program is distributed in the hope that it will be useful,          *
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of           *
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the            *
 *  GNU General Public License for more details.                             *
 *                                                                           *
 *  You should have received a copy of the GNU General Public                *
 *  License along with this program in the file 'license.gpl'; if            *
 *  not, see <http://www.gnu.org/licenses/>.                                 *
 *  --------------------------------------------------------------           *
 *===========================================================================*/
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <stdio.h>
#include <stdlib.h>

#include "sfl.h"
#include "tap.h"

void check_FOPEN_WRITE_TEXT() {
    FILE
        *f;
    char
        line[100];
    int
        errc;

    // TODO: check the file is truncated ...

    tap_comment("test group: %s", __FUNCTION__);
    tap_comment("----------");

    f = fopen("tmp.out", FOPEN_WRITE_TEXT);
    errc = NULL != f;
    tap_ok(errc, "FOPEN_WRITE with fopen works");

    errc = fputs("first-line\n", f);
    tap_ok(EOF != errc, "FOPEN_WRITE with fputs works");

    fclose(f);

    f = fopen("tmp.out", "rb");
    errc = NULL != f;
    tap_ok(errc, "FOPEN_WRITE with fopen creates a file");

    errc = NULL != fgets(line, 99, f);
    tap_ok(errc, "FOPEN_WRITE doesn't produce empty files");

    errc = NULL == strchr(line, '\r');
    tap_ok(errc, "FOPEN_WRITE doesn't use '\\r\\n' as end of line");

    fclose(f);
}

int main(int argc, char* argv[]) {
    check_FOPEN_WRITE_TEXT();
    tap_done_testing();
    return 0;
}

