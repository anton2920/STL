/*
Standard Template Library for C — free shared library, that contains an attempt of recreation of libc++ STL
Copyright © Pavlovsky Anton, 2019

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

#ifndef SRC_STL_LIST_H
#define SRC_STL_LIST_H

/* Include autoconf config.h */
#include "../STL_Config.h"

/* Header inclusion */
#if (HAVE_STDIO_H == 1)
    #include <stdio.h>
#endif

/* Macros */
#ifndef SWAP
    #define SWAP(a, b, size)                \
        do {                                \
            int __size = (size);            \
            char *__a = (a), *__b = (b);    \
            do {                            \
                char __tmp = *__a;          \
                *__a++ = *__b;              \
                *__b++ = __tmp;             \
            } while (--__size > 0);         \
        } while (0)
#endif

/* Definition of STL_List type */
typedef struct __STL_List_node {
    void *value;
    size_t size;
    struct __STL_List_node *next;
    struct __STL_List_node *prev;
} STL_List_node;

typedef struct __STL_List {
    STL_List_node *bp;      /* STL_List->bp is reserved and should not be changed */
    STL_List_node *lp;
    size_t size;
} STL_List;

/* STL_List errors */
enum STL_List_errors {
    STL_List_OK = 1,                /* Everything is OK. Not an error */
    STL_List_memory_error,          /* If STL_List routine can't allocate memory */
    STL_List_index_error,           /* If desired position is wrong */
    STL_List_null_reference_error   /* If (STL_List *) or (const void *elem) is NULL */
};

enum STL_List_states {
    not_empty = 0,
    empty = 1
};

/* STL_List methods */
int STL_List_init(STL_List *); /* Constructs the list. Returns STL_List_OK if OK */
void STL_List_delete(STL_List *); /* Destructs the list */
void STL_List_clear(STL_List *); /* Cleats the contents */

int STL_List_insert_pos(STL_List *, const void *elem, size_t size, size_t pos); /* Inserts element of size "size" at address "elem" before "pos". Returns STL_List_OK if OK */
int STL_List_insert(STL_List *, const void *elem, size_t size, STL_List_node *pos); /* Inserts element of size "size" at address "elem" before "pos". Returns STL_List_OK if OK */
int STL_List_push_back(STL_List *, const void *elem, size_t size); /* Inserts element of size "size" at address "elem" at the last position. Returns STL_List_OK if OK */
int STL_List_push_front(STL_List *, const void *elem, size_t size); /* Inserts element of size "size" at address "elem" at the first position. Returns STL_List_OK if OK */

STL_List_node *STL_List_erase_pos(STL_List *, size_t pos); /* Removes element of size "size" at address "elem" before "pos". Returns node after deleted element if OK */
STL_List_node *STL_List_erase(STL_List *, STL_List_node *pos); /* Removes element of size "size" at address "elem" before "pos". Returns node after deleted element if OK */
STL_List_node *STL_List_pop_back(STL_List *); /* Removes element of size "size" at address "elem" at the last position. Returns node after deleted element if OK */
STL_List_node *STL_List_pop_front(STL_List *); /* Removes element of size "size" at address "elem" at the first position. Returns node after deleted element if OK */

int STL_List_empty(STL_List *); /* Checks whether STL_List->size == 0 */
size_t STL_List_size(STL_List *); /* Returns STL_List->size */

STL_List_node *STL_List_begin(STL_List *); /* Returns STL_List->bp */
STL_List_node *STL_List_end(STL_List *); /* Returns STL_List->lp */

void mergeNatural(STL_List *, int (*cmp)(const void *, const void *));
void STL_List_sort(STL_List *, int (*cmp)(const void *, const void *)); /* Sorts the list */

void STL_List_swap_nodes(STL_List_node *, STL_List_node *); /* Swaps the contents of two STL_List_nodes */
void STL_List_swap(STL_List *this, STL_List *other); /* Swaps the contents of two STL_Lists */
size_t STL_List_size_node(STL_List_node *); /* Returns the size of the STL_List_node->elem */

#endif
