/*===========================================================================*
 *                                                                           *
 *  tap.c - Test Anything Protocol helper functions                          *
 *                                                                           *
 *  Copyright (c) 2019 Frederic Jardon                                       *
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

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tap.h"

static int tap_testno = 0;
static int tap_testsfailed = 0;

/* print the text up to the first EOL (not including EOL).
 * returns a pointer past the EOL.
 * If no EOL was found, print the whole text and returns NULL
 */
static char const* print_to_eol(FILE* stream, char const* text) {
    char const
        *p_eol;

    if(!text)
        return NULL;
    p_eol = strchr(text, '\n');
    if(!p_eol) {
        fputs(text, stream);
        return NULL;
    }
    fprintf(stream, "%*s", (int)(p_eol - text), text);
    return p_eol+1;
}

static void print_lines(FILE* stream, char const* text,
        char const* prefix1, char const* prefixN) {
    char const
        *p_eol = text;
    char const
        *p_prefix = prefix1;

    while(p_eol) {
        fputs(p_prefix, stream);
        p_prefix = prefixN;
        p_eol    = print_to_eol(stream, p_eol);
        fputc('\n', stream);
    }
}

/*  ---------------------------------------------------------------------[<]-
    Function: tap_comment()

    Synopsis: Prints a comment in the TAP stream. The comment
    use the same formatting than a call to fprintf() with a
    format string and a variable number of following arguments.
    ---------------------------------------------------------------------[>]-*/
void tap_comment(char const* fmt, ...) {
    va_list
        args;
    char
        *buffer;
    int
        buflen;

    va_start(args, fmt);
    buflen = 1+vsnprintf(NULL, 0, fmt, args);
    va_end(args);

    buffer = (char*) malloc(buflen);

    va_start(args, fmt);
    vsnprintf(buffer, buflen, fmt, args);
    va_end(args);
    print_lines(stdout, buffer, "# ", "# ");

    free(buffer);
}

/*  ---------------------------------------------------------------------[<]-
    Function: tap_ok()

    Synopsis: asserts the result of a test is TRUE. Prints a
    description of the test if passed a non-NULL description.
    ---------------------------------------------------------------------[>]-*/
void tap_ok(int ok, char const* description) {
    tap_testsfailed += !ok;
    fprintf(stdout, "%sok %d", ok ? "" : "not ", ++ tap_testno);
    print_lines(stdout, description, " - ", "# | ");
    fflush(stdout);
}

/*  ---------------------------------------------------------------------[<]-
    Function: tap_not_ok()

    Synopsis: asserts the result of a test is FALSE. Prints a
    description of the test if passed a non-NULL description.
    ---------------------------------------------------------------------[>]-*/
void tap_not_ok(int ok, char const* description) {
    tap_ok(!ok, description);
}

/*  ---------------------------------------------------------------------[<]-
    Function: tap_done_testing()

    Synopsis: Ends a test session by printing the plan. In case
    test failed, the function calls exit with a non-zero exit
    code.
    ---------------------------------------------------------------------[>]-*/
void tap_done_testing() {
    fprintf(stdout, "1..%d\n", tap_testno);
    fflush(stdout);
    if(tap_testsfailed) exit(1);
}

