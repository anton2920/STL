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

#ifndef SRC_STL_QUEUE_H
#define SRC_STL_QUEUE_H

/* Include autoconf config.h */
#include "../STL_Config.h"

/* Header inclusion */
#if (HAVE_STDDEF_H == 1)
    #include <stddef.h>
#endif

/* Include STL_List type definition */
#include "__STL_List_type.h"

/* Definition of STL_Queue type */
typedef STL_List STL_Queue;
typedef STL_List_node STL_Queue_node;

/* STL_Queue errors */
enum STL_Queue_errors {
    STL_Queue_OK = 1,                /* Everything is OK. Not an error */
    STL_Queue_memory_error,          /* If STL_Queue routine can't allocate memory */
    STL_Queue_index_error,           /* If desired position is wrong */
    STL_Queue_null_reference_error   /* If (STL_Queue *) or (const void *elem) is NULL */
};

/* STL_Queue methods */
/* Construction and destruction */
int STL_Queue_init(STL_Queue *self); /* Constructs the queue. Returns STL_Queue_OK if OK */
int STL_Queue_init_cpy(STL_Queue *self, STL_Queue *other); /* Copies the queue. Returns STL_Queue_OK if OK */
void STL_Queue_delete(STL_Queue *queue); /* Destructs the queue */

/* Element access */
void *STL_Queue_front(const STL_Queue *queue); /* Accesses the first element */
void *STL_Queue_back(const STL_Queue *queue); /* Accesses the last element */

/* Capacity */
int STL_Queue_empty(const STL_Queue *queue); /* Returns STL_List_states::is_empty if STL_Queue->size == 0 */
size_t STL_Queue_size(const STL_Queue *queue); /* Returns STL_Queue->size */

/* Modifiers */
int STL_Queue_push(STL_Queue *queue, const void *elem, size_t nbytes); /* Inserts element of size "size" at address "elem" at the first position. Returns STL_Queue_OK if OK */
void STL_Queue_pop(STL_Queue *queue); /* Removes element at the last position */

void STL_Queue_swap(STL_Queue *self, STL_Queue *other); /* Swaps the contents of two STL_Queues */

#endif
