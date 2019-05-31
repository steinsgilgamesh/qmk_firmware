/* Copyright 2019 marksard.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#pragma once

#include "quantum.h"

/* This a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 */
#define LAYOUT( \
  L09, L08, L07, L06, L05, L04, L03, L02, L01, L00, \
  L19, L18, L17, L16, L15, L14, L13, L12, L11, L10, \
  L29, L28, L27, L26, L25, L24, L23, L22, L21, L20  \
  ) \
  { \
    { L05, L06, L07, L08, L09 }, \
    { L15, L16, L17, L18, L19 }, \
    { L25, L26, L27, L28, L29 }, \
    { L24, L23, L22, L21, L20 }, \
    { L14, L13, L12, L11, L10 }, \
    { L04, L03, L02, L01, L00 }  \
  }
