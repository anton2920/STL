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

#ifndef SRC___STL_LIST_TYPE_H
#define SRC___STL_LIST_TYPE_H

/* Definition of STL_List type */
typedef struct __STL_List_node {
    void *value;
    size_t size;
    struct __STL_List_node *next;
    struct __STL_List_node *prev;
} STL_List_node;

typedef struct __STL_List {
    STL_List_node *bp;
    STL_List_node *lp;
    size_t size;
} STL_List;

#endif
