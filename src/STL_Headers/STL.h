/*
Standard Template Library for C — free shared library, that contains an attempt of recreation of libc++ STL
Copyright © Pavlovsky Anton, 2019-2022

This file is part of STL.

STL is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

STL is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with STL. If not, see <https://www.gnu.org/licenses/>.
*/

#ifndef SRC_STL_H
#define SRC_STL_H

/* Include autoconf config.h */
#include "STL_Config.h"

/* Headers that provide access to STL containers and container adaptors */
/* Sequence containers implement data structures which can be accessed sequentially */
#include "STL/STL_List.h" /* doubly-linked list */
#include "STL/STL_Forward_list.h" /* singly-linked list */

/* Container adaptors provide a different interface for sequential containers */
#include "STL/STL_Stack.h" /* adapts a container to provide stack (LIFO data structure) */
#include "STL/STL_Queue.h" /* adapts a container to provide queue (FIFO data structure) */

/* Random-access containers */
#include "STL/STL_Vector.h" /* wrap for dynamic array */
#include "STL/STL_String.h" /* wrap for C-styled strings */

/* Headers that provide access to STL algorithms */
#include "STL/STL_Algorithm.h"

#endif
