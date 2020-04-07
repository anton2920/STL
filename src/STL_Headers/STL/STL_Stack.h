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

#ifndef SRC_STL_STACK_H
#define SRC_STL_STACK_H

/* Include autoconf config.h */
#include "../STL_Config.h"

/* Header inclusion */
#if (HAVE_STDDEF_H == 1)
    #include <stddef.h>
#endif
/* Include STL_List type definition */
#include "__STL_List_type.h"

/* Definition of STL_Queue type */
typedef STL_List STL_Stack;
typedef STL_List_node STL_Stack_node;

/* STL_Stack errors */
enum STL_Stack_errors {
    STL_Stack_OK = 1,                /* Everything is OK. Not an error */
    STL_Stack_memory_error,          /* If STL_Stack routine can't allocate memory */
    STL_Stack_index_error,           /* If desired position is wrong */
    STL_Stack_null_reference_error   /* If (STL_Stack *) or (const void *elem) is NULL */
};

/* STL_Stack methods */
/* Construction and destruction */
int STL_Stack_init(STL_Stack *self); /* Constructs the stack. Returns STL_Stack_OK if OK */
int STL_Stack_init_cpy(STL_Stack *self, STL_Stack *other); /* Copies the stack. Returns STL_Stack_OK if OK */
void STL_Stack_delete(STL_Stack *stack); /* Destructs the stack */

/* Element access */
void *STL_Stack_top(const STL_Stack *stack); /* Accesses stack's top element */

/* Capacity */
int STL_Stack_empty(const STL_Stack *stack); /* Returns STL_List_states::list_is_empty if STL_Stack->size == 0 */
size_t STL_Stack_size(const STL_Stack *stack); /* Returns STL_Stack->size */

/* Modifiers */
int STL_Stack_push(STL_Stack *stack, const void *elem, size_t nbytes); /* Inserts element of size "size" at address "elem" at the first position. Returns STL_Stack_OK if OK */
void STL_Stack_pop(STL_Stack *stack); /* Removes element at the last position */

void STL_Stack_swap(STL_Stack *self, STL_Stack *other); /* Swaps the contents of two STL_Stacks */

#endif
