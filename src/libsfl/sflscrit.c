/*===========================================================================*
 *                                                                           *
 *  sflscrit.c   Parse search criteria for sflsearch                         *
 *                                                                           *
 *  Copyright (c) 1991-2010 iMatix Corporation                               *
 *                                                                           *
 *  ------------------ GPL Licensed Source Code ------------------           *
 *  iMatix makes this software available under the GNU General               *
 *  Public License (GPL) license for open source projects.  For              *
 *  details of the GPL license please see www.gnu.org or read the            *
 *  file license.gpl provided in this package.                               *
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
 *                                                                           *
 *  You can also license this software under iMatix's General Terms          *
 *  of Business (GTB) for commercial projects.  If you have not              *
 *  explicitly licensed this software under the iMatix GTB you may           *
 *  only use it under the terms of the GNU General Public License.           *
 *                                                                           *
 *  For more information, send an email to info@imatix.com.                  *
 *===========================================================================*/

#include "prelude.h"                    /*  Universal header file            */
#include "sfllist.h"                    /*  Linked-list functions            */
#include "sflmem.h"                     /*  Memory handling functions        */
#include "sflstr.h"                     /*  String-handling functions        */
#include "sflcons.h"                    /*  Console i/o functions            */
#include "sflbits.h"                    /*  Large bitstring functions        */
#include "sflprint.h"                   /*  Virtual printing functions       */
#include "sflsearch.h"                  /*  Search constants                 */

#include "sflscrit.d"                   /*  Include dialog data              */

/*  Local function prototypes                                                */

static char   toalpha                  (char ansichar);
static SCRIT *scrit_add                (char type, char *value);
static void   set_previous_token_scope (char scope);

#define SCRIT_LIMIT     10              /*  Max. scrits per token            */


/*- Global variables used in this source file only --------------------------*/

static LIST
    *feedback;                          /*  Feedback for calling program     */

static SCRIT
    *cur_scrit [SCRIT_LIMIT];           /*  Previous SCRITs for ranges       */
static char
    *string,                            /*  String to parse                  */
    decimal,                            /*  Caller's decimal point           */
    cur_char,                           /*  Current character from string    */
    comma,                              /*  Comma character                  */
    method,                             /*  Criteria method                  */
    scope,                              /*  Criteria scope                   */
    *scanptr,                           /*  Scan through string              */
    *token;                             /*  Current token being collected    */
static int
    scrit_count,                        /*  Size of cur_scrit table          */
    tok_size;                           /*  Size of token                    */


/********************************   M A I N   ********************************/

/*  ---------------------------------------------------------------------[<]-
    Function: search_build_scrit

    Synopsis: Accepts a data string and splits it into criteria that can be
    indexed.  Returns a SCRIT list containing the resulting search
    criteria.  The caller must free each criterion value and item in the
    search criterion list.  If the string contained no valid search criteria
    returns a list with no attached items.

    National character set treatment: assumes that the character set is
    ISO-8859-1 and folds 8-bit accented characters into isalpha equivalents.

    When the search option is true, takes special characters in the string
    as various search options: +abc means the criteria is mandatory; -abc
    means it is excluded.  nnnn> means greater-equal nnnn, and >nnnn means
    less than or equal to nnnn.  nnnn>mmmm defines a range between two
    criteria.  These options are set in the method and scope for each
    scrit item.  When the search option is false these special characters
    are ignored and the method and scope properties are set to spaces.
    ---------------------------------------------------------------------[>]-*/

LIST *search_build_scrit (char *p_string, char p_decimal)
{
    string  = p_string;                 /*  Local copy of parameters         */
    decimal = p_decimal;

#   include "sflscrit.i"                /*  Include dialog interpreter       */
}


/*************************   INITIALISE THE PROGRAM   ************************/

MODULE initialise_the_program (void)
{
    /*  Reset returned list                                                  */
    feedback = mem_alloc (sizeof (LIST));
    list_reset (feedback);

    /*  Token is at most the same length as the string                       */
    token   = mem_alloc (strlen (string) + 1);
    scanptr = string;

    /*  By default, numbers are handled as US/UK decimals                    */
    if (decimal == ',')
        comma = '.';
    else {
        decimal = '.';
        comma   = ',';
    }
    the_next_event = ok_event;
}


/***************************   GET NEXT CHARACTER   **************************/

MODULE get_next_character (void)
{
    cur_char = toupper (toalpha (*scanptr));
    scanptr++;

    if (isalpha (cur_char))
        the_next_event = alpha_event;
    else
    if (isdigit (cur_char))
        the_next_event = digit_event;
    else
    if (cur_char == '+')
        the_next_event = plus_event;
    else
    if (cur_char == '-')
        the_next_event = minus_event;
    else
    if (cur_char == '>')
        the_next_event = range_event;
    else
    if (cur_char == decimal)
        the_next_event = decimal_event;
    else
    if (cur_char == comma)
        the_next_event = comma_event;
    else
    if (cur_char == '\0')
        the_next_event = finished_event;
    else
        the_next_event = delimiter_event;
}

/*  toalpha -- local
    Converts the supplied ANSI character to an (approximate) alpha character
 */
static char
toalpha (char ansichar)
{
    static struct {
        int from;
        int to;
    }
    conversion [] = {
        { 192, 'A' },     /*  capital A grave                �  */
        { 193, 'A' },     /*  capital A acute                �  */
        { 194, 'A' },     /*  capital A circumflex           �  */
        { 195, 'A' },     /*  capital A tilde                �  */
        { 196, 'A' },     /*  capital A dieresis or umlaut   �  */
        { 197, 'A' },     /*  capital A ring                 �  */
        { 198, 'A' },     /*  capital AE ligature            �  */
        { 199, 'C' },     /*  capital C cedilla              �  */
        { 200, 'E' },     /*  capital E grave                �  */
        { 201, 'E' },     /*  capital E acute                �  */
        { 202, 'E' },     /*  capital E circumflex           �  */
        { 203, 'E' },     /*  capital E dieresis or umlaut   �  */
        { 204, 'I' },     /*  capital I grave                �  */
        { 205, 'I' },     /*  capital I acute                �  */
        { 206, 'I' },     /*  capital I circumflex           �  */
        { 207, 'I' },     /*  capital I dieresis or umlaut   �  */
        { 208, 'O' },     /*  capital ETH                    �  */
        { 209, 'N' },     /*  capital N tilde                �  */
        { 210, 'O' },     /*  capital O grave                �  */
        { 211, 'O' },     /*  capital O acute                �  */
        { 212, 'O' },     /*  capital O circumflex           �  */
        { 213, 'O' },     /*  capital O tilde                �  */
        { 214, 'O' },     /*  capital O dieresis or umlaut   �  */
        { 216, 'O' },     /*  capital O slash                �  */
        { 217, 'U' },     /*  capital U grave                �  */
        { 218, 'U' },     /*  capital U acute                �  */
        { 219, 'U' },     /*  capital U circumflex           �  */
        { 220, 'U' },     /*  capital U dieresis or umlaut   �  */
        { 221, 'Y' },     /*  capital Y acute                �  */
        { 222, 'P' },     /*  capital THORN                  �  */
        { 223, 's' },     /*  small sharp s, sz ligature     �  */
        { 224, 'a' },     /*  small a grave                  �  */
        { 225, 'a' },     /*  small a acute                  �  */
        { 226, 'a' },     /*  small a circumflex             �  */
        { 227, 'a' },     /*  small a tilde                  �  */
        { 228, 'a' },     /*  small a dieresis or umlaut     �  */
        { 229, 'a' },     /*  small a ring                   �  */
        { 230, 'a' },     /*  small ae ligature              �  */
        { 231, 'c' },     /*  small c cedilla                �  */
        { 232, 'e' },     /*  small e grave                  �  */
        { 233, 'e' },     /*  small e acute                  �  */
        { 234, 'e' },     /*  small e circumflex             �  */
        { 235, 'e' },     /*  small e dieresis or umlaut     �  */
        { 236, 'i' },     /*  small i grave                  �  */
        { 237, 'i' },     /*  small i acute                  �  */
        { 238, 'i' },     /*  small i circumflex             �  */
        { 239, 'i' },     /*  small i dieresis or umlaut     �  */
        { 240, 'o' },     /*  small eth                      �  */
        { 241, 'n' },     /*  small n tilde                  �  */
        { 242, 'o' },     /*  small o grave                  �  */
        { 243, 'o' },     /*  small o acute                  �  */
        { 244, 'o' },     /*  small o circumflex             �  */
        { 245, 'o' },     /*  small o tilde                  �  */
        { 246, 'o' },     /*  small o dieresis or umlaut     �  */
        { 248, 'o' },     /*  small o slash                  �  */
        { 249, 'u' },     /*  small u grave                  �  */
        { 250, 'u' },     /*  small u acute                  �  */
        { 251, 'u' },     /*  small u circumflex             �  */
        { 252, 'u' },     /*  small u dieresis or umlaut     �  */
        { 253, 'y' },     /*  small y acute                  �  */
        { 254, 'p' },     /*  small thorn                    �  */
        { 255, 'y' }      /*  small y dieresis or umlaut     �  */
    };
    static int
        table [256];
    static Bool
        initialized = FALSE;
    int
        index;

    if (!initialized) {
        /*  Default translation is from character to itself                  */
        for (index = 0; index < 256; index++)
            table [index] = index;
        /*  Now punch in our conversions                                     */
        for (index = 0; index < tblsize (conversion); index++)
            table [conversion [index].from] = (unsigned int) conversion [index].to;
        initialized = TRUE;
    }
    return ((char) table [(byte) ansichar]);
}


/****************************   START NEW TOKEN   ****************************/

MODULE start_new_token (void)
{
    tok_size = 0;
    scrit_count = 0;
}


/****************************   APPEND TO TOKEN   ****************************/

MODULE append_to_token (void)
{
    token [tok_size++] = cur_char;
}


/***************************   STORE ALPHA TOKEN   ***************************/

MODULE store_alpha_token (void)
{
    /*  We store a prefix+phonetic textual token                             */
    if (tok_size == 1)
        token [tok_size++] = '-';
        
    token [tok_size] = '\0';
    cur_scrit [scrit_count++] = scrit_add ('t',
        strprintf ("%c%c%s", token [0], token [1], soundex (token) + 1));
}

/*  scrit_add -- local
    Adds the specified scrit to the list.
    Returns the address of the created SCRIT.
    We do not try to eliminate duplicates, this can be done elsewhere.
 */
static SCRIT *
scrit_add (char type, char *value)
{
    SCRIT
        scrit = { NULL, '?', ' ', ' ' };

    scrit.value  = mem_strdup (value);
    scrit.type   = type;
    scrit.method = method;
    scrit.scope  = scope;
    list_queue (feedback, scrit);
    return ((SCRIT *) ((char *) feedback->prev + sizeof (LIST)));
}


/**************************   STORE NUMERIC TOKEN   **************************/

MODULE store_numeric_token (void)
{
    /*  We add one text criteria with the full string value                  */
    token [tok_size] = '\0';
    cur_scrit [scrit_count++] = scrit_add ('n', token);
}


/*****************************   USE METHOD OR   *****************************/

MODULE use_method_or (void)
{
    method = SEARCH_METHOD_OR;
}


/*****************************   USE METHOD AND   ****************************/

MODULE use_method_and (void)
{
    method = SEARCH_METHOD_AND;
}


/*****************************   USE METHOD NOT   ****************************/

MODULE use_method_not (void)
{
    method = SEARCH_METHOD_NOT;
}


/****************************   USE SCOPE EQUAL   ****************************/

MODULE use_scope_equal (void)
{
    scope = SEARCH_SCOPE_EQ;
}


/************************   USE SCOPE GREATER EQUAL   ************************/

MODULE use_scope_greater_equal (void)
{
    scope = SEARCH_SCOPE_GE;
}


/**************************   USE SCOPE LESS EQUAL   *************************/

MODULE use_scope_less_equal (void)
{
    set_previous_token_scope (SEARCH_SCOPE_LE);
}

static void
set_previous_token_scope (char scope)
{
    int
        index;

    for (index = 0; index < scrit_count; index++)
        cur_scrit [index]->scope = scope;
}


/***************************   USE SCOPE FROM TO   ***************************/

MODULE use_scope_from_to (void)
{
    set_previous_token_scope (SEARCH_SCOPE_FROM);
    scope = SEARCH_SCOPE_TO;
}


/***************************   GET EXTERNAL EVENT   **************************/

MODULE get_external_event (void)
{
}


/*************************   TERMINATE THE PROGRAM    ************************/

MODULE terminate_the_program (void)
{
    mem_free (token);
    the_next_event = terminate_event;
}

