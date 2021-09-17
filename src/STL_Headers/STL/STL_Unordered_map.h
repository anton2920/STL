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

#ifndef SRC_STL_UNORDERED_MAP_H
#define SRC_STL_UNORDERED_MAP_H

#include <stddef.h>

/* Include STL_Forward_list type */
#include "__internal/__STL_Forward_list_type.h"

/* Include STL_Unordered_multimap */
#include "__internal/__STL_Unordered_multimap.h"

/* Definition of STL_Unordered_map type */
typedef void *STL_Unordered_map_bucket_t;
typedef size_t STL_Unordered_map_key_t;
typedef STL_Unordered_map_key_t (*STL_Unordered_map_hash_function_t)(void *elem, size_t total_elem);

enum STL_Unordered_map_defaults {
    DEFAULT_NBUCKET = 0x3,
    DEFAULT_MAX_LOAD_FACTOR = 1
};

typedef struct __STL_Unordered_map {
    STL_Unordered_map_bucket_t *buckets;

    size_t nelem;
    size_t size;

    size_t nbuckets;

    STL_Unordered_map_hash_function_t hasher;

    float load_factor;
    float max_load_factor;
} STL_Unordered_map;

/* STL_Unordered_map errors */
enum STL_Unordered_map_errors {
    STL_Unordered_map_OK = 1,                /* Everything is OK. Not an error */
    STL_Unordered_map_memory_error,          /* If STL_Unordered_map routine can't allocate memory */
    STL_Unordered_map_index_error,           /* If desired position is wrong */
    STL_Unordered_map_null_reference_error   /* If (STL_Unordered_map *) or (const void *elem) is NULL */
};

/* STL_Unordered_map states */
enum STL_Unordered_map_states {
    unordered_map_not_empty = 0,
    unordered_map_is_empty
};

/* STL_Unordered_map methods */
/* Construction and destruction */
int STL_Unordered_map_init(STL_Unordered_map *self, size_t elem_size,
                           STL_Unordered_map_hash_function_t func); /* Constructs the unordered_map. Returns STL_Unordered_map_OK if OK */
int STL_Unordered_map_init_cpy(STL_Unordered_map *self,
                               STL_Unordered_map *other); /* Copies the unordered_map. Returns STL_Unordered_map_OK if OK */
void STL_Unordered_map_delete(STL_Unordered_map *self); /* Destructs the unordered_map */

/* Iterators */
void *STL_Unordered_map_begin(STL_Unordered_map *self); /* Returns an iterator to the beginning */
void *STL_Unordered_map_end(STL_Unordered_map *self); /* Returns an iterator to the end */

/* Capacity */
int STL_Unordered_map_empty(STL_Unordered_map *self); /* Checks whether the container is empty */
size_t STL_Unordered_map_size(STL_Unordered_map *self); /* Returns the number of elements */

/* Modifiers */
void STL_Unordered_map_clear(STL_Unordered_map *self); /* Clears the contents */

int STL_Unordered_map_insert(STL_Unordered_map *self, const void *elem); /* Inserts an element */
int STL_Unordered_map_insert_or_assign(STL_Unordered_map *self,
                                       const void *elem); /* Inserts an element or assigns to the current element if the key already exists */

void STL_Unordered_map_erase(STL_Unordered_map *self, void *pos); /* Erases an element at "pos" */

void STL_Unordered_map_swap(STL_Unordered_map *self, STL_Unordered_map *other); /* Swaps the contents */

/* Lookup */
void *STL_Unordered_map_at(STL_Unordered_map *self, size_t pos); /* Access specified element with bounds checking */
size_t STL_Unordered_map_count(STL_Unordered_map *self, STL_Unordered_map_key_t key); /* Returns the number if elements matching specific key */
void *STL_Unordered_map_find(STL_Unordered_map *self, STL_Unordered_map_key_t key); /* Finds element with specific key */

/* Bucket interface */
void *STL_Unordered_map_bucket_begin(STL_Unordered_map *self,
                                     size_t n); /* Return an iterator to the beginning of the specific bucket */
void *STL_Unordered_map_bucket_end(STL_Unordered_map *self,
                                   size_t n); /* Returns an iterator to the end of the specific bucket */

size_t STL_Unordered_map_bucket_count(STL_Unordered_map *self); /* Returns the number of buckets */
size_t STL_Unordered_map_bucket_size(STL_Unordered_map *self,
                                     size_t n); /* Returns the number of elements in specific bucket */

void *STL_Unordered_map_bucket(STL_Unordered_map *self,
                               STL_Unordered_map_key_t key); /* Returns the bucket for specific key */

/* Hash policy */
float STL_Unordered_map_load_factor(STL_Unordered_map *self); /* Returns average number of elements per bucket */
float STL_Unordered_map_max_load_factor(STL_Unordered_map *self); /* Returns maximum average number of elements per bucket */

void STL_Unordered_map_rehash(STL_Unordered_map *self, size_t count); /* */
void STL_Unordered_map_reserve(STL_Unordered_map *self, size_t count); /* */

STL_Unordered_map_hash_function_t STL_Unordered_map_hash_function(STL_Unordered_map *self); /* Returns function used to hash the keys */

#endif
