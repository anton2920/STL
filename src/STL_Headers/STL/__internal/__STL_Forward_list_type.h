/*
Standard Template Library for C — free shared library, that contains an attempt of recreation of libc++ STL
Copyright © Pavlovsky Anton, 2019-2020

This file is part of STL.

STL is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

STL is distributed in the hope that i    struct __STL_Forward_list_node *prev;t will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with STL. If not, see <https://www.gnu.org/licenses/>.
*/

#ifndef SRC___STL_FORWARD_LIST_TYPE_H
#define SRC___STL_FORWARD_LIST_TYPE_H

/* Definition of STL_Forward_list type */
typedef struct __STL_Forward_list_node {
    void *value;
    size_t size;
    struct __STL_Forward_list_node *next;
} STL_Forward_list_node;

typedef struct __STL_Forward_list {
    STL_Forward_list_node *bp;
    STL_Forward_list_node *lp;
    size_t size;
} STL_Forward_list;

#endif
