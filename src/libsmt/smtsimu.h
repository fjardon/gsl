/*===========================================================================*
 *                                                                           *
 *  smtsimu.h - Network simulation agent                                     *
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
 *  --------------------------------------------------------------           *
 *===========================================================================*/
/*  ----------------------------------------------------------------<Prolog>-
    Synopsis:   Redefines socket functions to pass via smtsimu.  Include
                smtsimu.h after smtlib.h when you want to simulate network
                delays. You do not need to change your program in any other
                way.
 ------------------------------------------------------------------</Prolog>-*/

#ifndef _SMTSIMU_INCLUDED               /*  Allow multiple inclusions        */
#define _SMTSIMU_INCLUDED

/*---------------------------------------------------------------------------
 *  Define functions to pass through the fake function.  Only some functions
 *  are redirected in this way.
 */

#define smtsock_init        smtsimu_smtsock_init
#define smtsock_trace       smtsimu_smtsock_trace
#define sock_init           smtsimu_sock_init
#define write_UDP           smtsimu_write_UDP

int  smtsimu_init           (void);
int  smtsimu_smtsock_init   (void);
void smtsimu_smtsock_trace  (Bool trace_value);
int  smtsimu_sock_init      (void);
int  smtsimu_write_UDP      (SOCKET handle, void *buffer,
                             size_t length, struct sockaddr_in *sin);

#endif                                  /*  Include smtsimu.h                */
