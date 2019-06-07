/*===========================================================================*
 *                                                                           *
 *  tap.h - Test Anything Protocol helper functions                          *
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
#ifndef INCLUDE_TAP_H
#define INCLUDE_TAP_H

#ifdef __cplusplus
extern "C" {
#endif

void tap_comment(char const *fmt, ...);
void tap_ok(int ok, char const* description);
void tap_not_ok(int not_ok, char const* description);
void tap_done_testing();

#ifdef __cplusplus
}
#endif

#endif /* INCLUDE_TAP_H */

