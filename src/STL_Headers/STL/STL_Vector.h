/*
Standard Template Library for C — free shared library, that contains an attempt of recreation of libc++ STL
Copyright © Pavlovsky Anton, 2019-2021

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

#ifndef SRC_STL_VECTOR_H
#define SRC_STL_VECTOR_H

#include <stddef.h>

/* Definition of STL_Vector type */
typedef struct __STL_Vector {
    void *data;

    size_t nbytes;
    size_t nelem;
    size_t max_nelem;
} STL_Vector;

/* STL_Vector errors */
enum STL_Vector_errors {
    STL_Vector_OK = 1,                /* Everything is OK. Not an error */
    STL_Vector_memory_error,          /* If STL_Vector routine can't allocate memory */
    STL_Vector_index_error,           /* If desired position is wrong */
    STL_Vector_null_reference_error   /* If (STL_Vector *) or (const void *elem) is NULL */
};

/* STL_Vector states */
enum STL_Vector_states {
    vector_not_empty = 0,
    vector_is_empty
};

/* STL_Vector methods */
/* Construction and destruction */
int STL_Vector_init(STL_Vector *self, size_t nbytes); /* Constructs the vector for the values of size nbytes. Returns STL_Vector_OK if OK */
int STL_Vector_init_cpy(STL_Vector *self, STL_Vector *other); /* Copies the vector. Returns STL_Vector_OK if OK */
void STL_Vector_delete(STL_Vector *self); /* Destructs the vector */

/* Element access */
void *STL_Vector_at(STL_Vector *self, size_t n); /* Accesses specified element with bounds checking */
void *STL_Vector_front(STL_Vector *self); /* Accesses the first element */
void *STL_Vector_last(STL_Vector *self); /* Accesses the last element */
void *STL_Vector_data(STL_Vector *self); /* Direct access to the underlying array */

/* Kinda iterators */
void *STL_Vector_begin(STL_Vector *self); /* Returns iterator to the beginning */
void *STL_Vector_end(STL_Vector *self); /* Returns iterator to the end */

/* Capacity */
int STL_Vector_empty(STL_Vector *self); /* Checks whether the container is empty */
size_t STL_Vector_size(STL_Vector *self); /* Returns the number of elements */
int STL_Vector_reserve(STL_Vector *self, size_t new_cap); /* Reserves storage */
size_t STL_Vector_capacity(STL_Vector *self); /* Returns the number of elements that can be held in currently allocated storage */
int STL_Vector_shrink_to_fit(STL_Vector *self); /* Reduces memory usage by freeing unused memory */

/* Modifiers */
void STL_Vector_clear(STL_Vector *self); /* Clears the contents */

void *STL_Vector_insert_at(STL_Vector *self, const void *elem, size_t pos); /* Inserts elem before pos. Returns iterator pointing to the inserted value */
void *STL_Vector_insert(STL_Vector *self, const void *elem, void *pos); /* Inserts elem before pos. Returns iterator pointing to the inserted value */

void *STL_Vector_erase_pos(STL_Vector *self, size_t pos); /* Erases element at pos. Returns iterator following removed element */
void *STL_Vector_erase(STL_Vector *self, void *pos); /* Erases element at pos. Returns iterator following removed element */

int STL_Vector_push_back(STL_Vector *self, const void *elem); /* Adds element to the end */
void STL_Vector_pop_back(STL_Vector *self); /* Removes the last element */

int STL_Vector_resize(STL_Vector *self, size_t count); /* Changes the number of elements stored */
void STL_Vector_swap(STL_Vector *self, STL_Vector *other); /* Swaps the contents */

#endif