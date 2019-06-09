/*===========================================================================*
 *                                                                           *
 *  sflfort-check.c - Unit tests for sflfort API                             *
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

void
check_fortune_build() {
    FILE
        *f;
    long
        f_sz;
    int
        i, errc;

    tap_comment("test group: %s", __func__);
    tap_comment("----------");

    /* create a file containing a list of fortune string */
    f = fopen("check-fortune.in", "w");
    i = 0;
    fprintf(f, "quote %d", ++i);
    while(i < 10) {
        fputs("\n%%\n", f);
        fprintf(f, "quote %d", ++i);
    }
    fclose(f);

    /* create an indexed fortune file */
    errc = fortune_build("check-fortune.in", "check-fortune.out", FALSE);
    tap_ok(0 == errc, "fortune_build successfully created the indexed file");

    f = fopen("check-fortune.out", "r");
    fseek(f, 0L, SEEK_END);
    f_sz = ftell(f);
    fseek(f, 0L, SEEK_SET);
    fclose(f);
    tap_ok(f_sz > 37, "fortune_build write an indexed file containing more than the header");
}

void
check_fortune_read() {
    char
        *fortune;

    fortune = fortune_read("check-fortune.out");
    tap_ok(!!fortune, "fortune_read can read the file");
    tap_comment("get fortune: >%s<", fortune);
    tap_ok(strlen(fortune), "fortune_read returned a non-empty fortune string");
    mem_free(fortune);
}

int main(int argc, char* argv[]) {
    check_fortune_build();
    check_fortune_read();
    tap_done_testing();
    return 0;
}




