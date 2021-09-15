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

/* Header inclusion */
#include "../../STL_Headers/STL/STL_Unordered_map.h"

#include <stdlib.h>
#include <string.h>


static STL_Unordered_map_key_t default_hash_f(void *elem, size_t total_elem) {

    /* Initializing variables */
    auto char *str = (char *) elem;
    auto unsigned long hash = 5381u;
    auto int c;

    /* Main part */
    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c;
    }

    /* Returning value */
    return hash % total_elem;
}

int STL_Unordered_map_init(STL_Unordered_map *self, size_t elem_size, STL_Unordered_map_hash_function_t func) {

    /* VarCheck */
    if (self == NULL) {
        return STL_Unordered_map_null_reference_error;
    }

    /* Main part */
    if ((self->buckets = (STL_Unordered_map_bucket_t *) calloc(DEFAULT_NBUCKET + 1, sizeof(STL_Unordered_map_bucket_t))) == NULL) {
        return STL_Unordered_map_memory_error;
    }

    self->size = elem_size;
    self->nbuckets = DEFAULT_NBUCKET;
    self->nelem = 0lu;

    self->hasher = (func == NULL) ? default_hash_f : func;

    /* Returning value */
    return STL_Unordered_map_OK;
}

int STL_Unordered_map_init_cpy(STL_Unordered_map *self, STL_Unordered_map *other) {

    /* Initializing variables */
    auto size_t i;

    /* VarCheck */
    if (self == NULL || other == NULL) {
        return STL_Unordered_map_null_reference_error;
    }

    /* Main part */
    STL_Unordered_map_init(self, other->size, other->hasher);

    for (i = 0; i < STL_Unordered_map_size(other); ++i) {
        STL_Unordered_map_insert(self, STL_Unordered_map_at(other, i));
    }

    /* Returning value */
    return STL_Unordered_map_OK;
}

void STL_Unordered_map_delete(STL_Unordered_map *self) {

    /* VarCheck */
    if (self == NULL) {
        return;
    }

    /* Main part */
    STL_Unordered_map_clear(self);

    free(self->buckets);
}

void *STL_Unordered_map_begin(STL_Unordered_map *self) {

    /* VarCheck */
    if (self == NULL) {
        return (void *) STL_Unordered_map_null_reference_error;
    }

    /* Returning value */
    return *(self->buckets);
}

void *STL_Unordered_map_end(STL_Unordered_map *self) {

    /* VarCheck */
    if (self == NULL) {
        return (void *) STL_Unordered_map_null_reference_error;
    }

    /* Returning value */
    return self->buckets + (self->nbuckets + 1) * self->size;
}

int STL_Unordered_map_empty(STL_Unordered_map *self) {

    /* VarCheck */
    if (self == NULL) {
        return STL_Unordered_map_null_reference_error;
    }

    /* Returning value */
    return (self->size > 0) ? unordered_map_not_empty : unordered_map_is_empty;
}

size_t STL_Unordered_map_size(STL_Unordered_map *self) {

    /* VarCheck */
    if (self == NULL) {
        return STL_Unordered_map_null_reference_error;
    }

    /* Returning value */
    return self->nelem;
}

void STL_Unordered_map_clear(STL_Unordered_map *self) {

}

int STL_Unordered_map_insert(STL_Unordered_map *self, const void *elem) {

}

int STL_Unordered_map_insert_or_assign(STL_Unordered_map *self, const void *elem) {

}

void STL_Unordered_map_erase(STL_Unordered_map *self, void *pos) {

}

void STL_Unordered_map_swap(STL_Unordered_map *self, STL_Unordered_map *other) {

}

void *STL_Unordered_map_at(STL_Unordered_map *self, size_t pos) {

}

size_t STL_Unordered_map_count(STL_Unordered_map *self, STL_Unordered_map_key_t key) {

}

void *STL_Unordered_map_find(STL_Unordered_map *self, STL_Unordered_map_key_t key) {

}

void *STL_Unordered_map_bucket_begin(STL_Unordered_map *self, size_t n) {

}

void *STL_Unordered_map_bucket_end(STL_Unordered_map *self, size_t n) {

}

size_t STL_Unordered_map_bucket_count(STL_Unordered_map *self) {

}

size_t STL_Unordered_map_bucket_size(STL_Unordered_map *self, size_t n) {

}

void *STL_Unordered_map_bucket(STL_Unordered_map *self, STL_Unordered_map_key_t key) {

}

float STL_Unordered_map_load_factor(STL_Unordered_map *self) {

}

float STL_Unordered_map_max_load_factor(STL_Unordered_map *self) {

}

void STL_Unordered_map_rehash(STL_Unordered_map *self, size_t count) {

}

void STL_Unordered_map_reserve(STL_Unordered_map *self, size_t count) {

}

STL_Unordered_map_hash_function_t STL_Unordered_map_hash_function(STL_Unordered_map *self) {

}
