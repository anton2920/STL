/*
Standard Template Library for C — free shared library, that contains an attempt of recreation of libc++ STL
Copyright © Pavlovsky Anton, 2019-2020

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
#include "__internal/__STL_Config.h"

/* Header inclusion */
#if (HAVE_STDDEF_H == 1)
    #include <stddef.h>
#endif

/* Include STL_List type definition */
#include "__internal/__STL_List_type.h"

/* STL_List errors */
enum STL_List_errors {
    STL_List_OK = 1,                /* Everything is OK. Not an error */
    STL_List_memory_error,          /* If STL_List routine can't allocate memory */
    STL_List_index_error,           /* If desired position is wrong */
    STL_List_null_reference_error   /* If (STL_List *) or (const void *elem) is NULL */
};

/* STL_List states */
enum STL_List_states {
    list_not_empty = 0,
    list_is_empty
};

/* STL_List methods */
/* Construction and destruction */
int STL_List_init(STL_List *list); /* Constructs the list. Returns STL_List_OK if OK */
int STL_List_init_cpy(STL_List *self, STL_List *other); /* Copies the list. Returns STL_List_OK if OK */
void STL_List_delete(STL_List *list); /* Destructs the list */

/* Element access */
void *STL_List_front(const STL_List *l); /* Accesses the first element */
void *STL_List_back(const STL_List *l); /* Accesses the last element */

/* Kinda iterators */
STL_List_node *STL_List_begin(STL_List *list); /* Returns STL_List->bp */
STL_List_node *STL_List_end(STL_List *list); /* Returns STL_List->lp */

/* Capacity */
int STL_List_empty(STL_List *list); /* Checks whether the container is empty */
size_t STL_List_size(STL_List *list); /* Returns the number of elements */

/* Modifiers */
void STL_List_clear(STL_List *list); /* Clears the contents */

int STL_List_insert_at(STL_List *list, const void *elem, size_t size, size_t pos); /* Inserts element of size "size" at address "elem" before "pos". Returns STL_List_OK if OK */
int STL_List_insert(STL_List *list, const void *elem, size_t size, STL_List_node *pos); /* Inserts element of size "size" at address "elem" before "pos". Returns STL_List_OK if OK */
STL_List_node *STL_List_erase_at(STL_List *list, size_t pos); /* Removes element before "pos". Returns node after deleted element if OK */
STL_List_node *STL_List_erase(STL_List *list, STL_List_node *pos); /* Removes element at "pos". Returns node after deleted element if OK */

int STL_List_push_back(STL_List *list, const void *elem, size_t size); /* Inserts element of size "size" at address "elem" at the last position. Returns STL_List_OK if OK */
STL_List_node *STL_List_pop_back(STL_List *list); /* Removes element at the last position. Returns node after deleted element if OK */
int STL_List_push_front(STL_List *list, const void *elem, size_t size); /* Inserts element of size "size" at address "elem" at the first position. Returns STL_List_OK if OK */
STL_List_node *STL_List_pop_front(STL_List *list); /* Removes element at the first position. Returns node after deleted element if OK */

void STL_List_swap(STL_List *self, STL_List *other); /* Swaps the contents of two STL_Lists */

/* Operations */
void STL_List_merge(STL_List *self, STL_List *other, int (*cmp)(const void *, const void *)); /* Merges two sorted lists into one. The lists should be sorted into ascending order */
void STL_List_reverse(STL_List *self); /* Reverses the order of elements */
void STL_List_sort(STL_List *list, size_t n, int (*cmp)(const void *, const void *)); /* Sorts the list */

/* Miscellaneous routines */
void STL_List_swap_nodes(STL_List_node *self_node, STL_List_node *other_node); /* Swaps the contents of two STL_List_nodes */
size_t STL_List_size_node(STL_List_node *node); /* Returns the size of the STL_List_node->elem */

#endif
