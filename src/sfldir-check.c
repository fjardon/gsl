/*===========================================================================*
 *                                                                           *
 *  sfldir-check.c - Unit tests for sfldir API                               *
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


void check_get_curdir() {
    char const
        *dead_beef = "dead-beef";
    char
        *dir, *p, *pw, *end;
    int
        dead_beef_len;

    tap_comment("test group: %s", __FUNCTION__);
    tap_comment("----------");

    dead_beef_len = strlen(dead_beef);

    /* taint some memory to observe uninitialized return */
    p = mem_alloc(PATH_MAX*10);
    pw  = p;
    end = p + 9*PATH_MAX;
    *pw = 0;
    while(pw < end) {
        strcat(pw, dead_beef);
        pw += dead_beef_len;
    }
    mem_free(p);

    dir = get_curdir();
    tap_comment("obtained: '%s'", dir);
    tap_ok(strncmp(dir, dead_beef, dead_beef_len), "get_curdir() doesn't return unitialized memory");
    mem_free(dir);
}

int main(int argc, char* argv[]) {
    check_get_curdir();
    tap_done_testing();
    return 0;
}


