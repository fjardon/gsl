/*===========================================================================*
 *                                                                           *
 *  sflbits-check.c - Unit tests for sflbits API                             *
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

static long const dead_beef = 0xdeadbeefdeadbeefl;

void
check_bits_fput() {
    BITS
        *bits;
    FILE
        *f;
    long
        f_pos;
    int
        i;

    tap_comment("test group: %s", __func__);
    tap_comment("----------");

    /* create a file containing a bit string */
    bits = bits_create();
    for(i = 0; i<8*sizeof(long); ++i)
        if(dead_beef & (1 << i))
            bits_set(bits, i);
    f = fopen("check-bits.out", "wb");
    bits_fput(f, bits);
    f_pos = ftell(f);
    fclose(f);
    bits_destroy(bits);

    tap_ok(f_pos > 0, "bits_fput effectively write to the file");
}

void
check_bits_fget() {
    BITS
        *bits;
    FILE
        *f;
    long
        f_pos;
    int
        i, bit, expected_bit, ok;

    tap_comment("test group: %s", __func__);
    tap_comment("----------");

    /* previous test write a test file containing the bits */

    /* read a file containing a bit string */
    f = fopen("check-bits.out", "rb");
    bits = bits_fget(f);
    f_pos = ftell(f);
    fclose(f);
    tap_ok(f_pos > 0, "bits_fget effectively read the file");
    tap_ok(!!bits, "bits_fget can understand a file");

    ok = TRUE;
    for(i=0; i<8*sizeof(long); ++i) {
        bit = bits_test(bits, i);
        expected_bit = !!(dead_beef & (1 << i));
        ok = ok && (bit == expected_bit);
    }
	tap_ok(ok, "bits_fget correctly read the bits");
    bits_destroy(bits);
}

void
cleanup() {
    remove ("check-bits.out");
}

int main(int argc, char* argv[]) {
    check_bits_fput();
    check_bits_fget();
    cleanup();
    tap_done_testing();
    return 0;
}



