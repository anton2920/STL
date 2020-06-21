/*
Standard Template Library for C — free shared library, that contains an attempt of recreation of libc++ STL
Copyright © Pavlovsky Anton, 2019-2020

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

#include "../../STL_Headers/STL/STL_Vector.h"

#if (HAVE_STDLIB_H == 1)
    #include <stdlib.h>
#endif

#if (HAVE_STRING_H == 1)
    #include <string.h>
#endif

static const size_t thresh = 16;

enum yn {
    NO,
    YES
};

static int STL_Vector_allocate_size(STL_Vector *self, size_t nbytes, enum yn prev) {

    /* Main part */
    if (prev == YES) {
        if ((self->data = realloc(self->data, nbytes)) == NULL) {
            return STL_Vector_memory_error;
        }
    } else if ((self->data = malloc(nbytes)) == NULL) {
        return STL_Vector_memory_error;
    }

    /* Returning value */
    return STL_Vector_OK;
}

static int STL_Vector_reallocate(STL_Vector *self, size_t new_size) {

    /* Initializing variables */
    auto void *tmp = malloc(self->nelem * self->nbytes);

    /* Main part */
    if (tmp == NULL) {
        return STL_Vector_memory_error;
    }
    memcpy(tmp, self->data, self->nelem * self->nbytes);

    if (STL_Vector_allocate_size(self, new_size, YES) != STL_Vector_OK) {
        return STL_Vector_memory_error;
    }

    self->max_nelem = new_size / self->nbytes;
    self->nelem = ((self->nelem > self->max_nelem) ? self->max_nelem : self->nelem);

    memcpy(self->data, tmp, self->nbytes * self->nelem);

    free(tmp);

    /* Returning value */
    return STL_Vector_OK;
}

int STL_Vector_init(STL_Vector *self, size_t nbytes) {

    /* Initializing variables */
    if (STL_Vector_allocate_size(self, nbytes * thresh, NO) != STL_Vector_OK) {
        return STL_Vector_memory_error;
    }

    self->nelem = 0;
    self->max_nelem = thresh;
    self->nbytes = nbytes;

    /* Returning value */
    return STL_Vector_OK;
}

int STL_Vector_init_cpy(STL_Vector *self, STL_Vector *other) {

    /* Main part */
    if (self == NULL || other == NULL) {
        return STL_Vector_null_reference_error;
    }

    if (STL_Vector_allocate_size(self, other->nbytes * other->max_nelem, NO) != STL_Vector_OK) {
        return STL_Vector_memory_error;
    }

    memcpy(self->data, other->data, other->nbytes * other->nelem);
    self->nelem = other->nelem;
    self->max_nelem = other->max_nelem;
    self->nbytes = other->nbytes;

    /* Returning value */
    return STL_Vector_OK;
}

void STL_Vector_delete(STL_Vector *self) {

    /* VarCheck */
    if (self == NULL) {
        return;
    }

    /* Main part */
    free(self->data);
}

void *STL_Vector_at(STL_Vector *self, size_t n) {

    /* VarCheck */
    if (self == NULL) {
        return NULL;
    }

    if (n >= self->nelem) {
        return NULL;
    }

    /* Returning value */
    return (self->data + n * self->nbytes);
}

void *STL_Vector_front(STL_Vector *self) {

    /* Returning value */
    return STL_Vector_at(self, 0);
}

void *STL_Vector_last(STL_Vector *self) {

    /* Returning value */
    return STL_Vector_at(self, self->nelem - 1);
}

void *STL_Vector_data(STL_Vector *self) {

    /* VarCheck */
    if (self == NULL) {
        return NULL;
    }

    /* Returning value */
    return self->data;
}

void *STL_Vector_begin(STL_Vector *self) {

    /* VarCheck */
    if (self == NULL) {
        return NULL;
    }

    /* Returning value */
    return self->data;
}

void *STL_Vector_end(STL_Vector *self) {

    /* VarCheck */
    if (self == NULL) {
        return NULL;
    }

    /* Returning value */
    return (self->data + self->nelem * self->nbytes + self->nbytes);
}

int STL_Vector_empty(STL_Vector *self) {

    /* VarCheck */
    if (self == NULL) {
        return STL_Vector_null_reference_error;
    }

    /* Returning value */
    return (!self->nelem) ? vector_is_empty : vector_not_empty;
}

size_t STL_Vector_size(STL_Vector *self) {

    /* VarCheck */
    if (self == NULL) {
        return -1;
    }

    /* Returning value */
    return self->nelem;
}

int STL_Vector_reserve(STL_Vector *self, size_t new_cap) {

    /* VarCheck */
    if (self == NULL) {
        return STL_Vector_null_reference_error;
    }

    /* Main part */
    if (new_cap <= STL_Vector_capacity(self)) {
        return STL_Vector_OK;
    }

    /* Returning value */
    return STL_Vector_reallocate(self, new_cap * self->nbytes);
}

size_t STL_Vector_capacity(STL_Vector *self) {

    /* VarCheck */
    if (self == NULL) {
        return -1;
    }

    /* Returning value */
    return self->max_nelem;
}

int STL_Vector_shrink_to_fit(STL_Vector *self) {

    /* VarCheck */
    if (self == NULL) {
        return STL_Vector_null_reference_error;
    }

    /* Returning value */
    return STL_Vector_reallocate(self, self->nbytes * self->nelem);
}

void STL_Vector_clear(STL_Vector *self) {

    /* VarCheck */
    if (self == NULL) {
        return;
    }

    /* Main part */
    self->nelem = 0;
}

void *STL_Vector_insert_at(STL_Vector *self, const void *elem, size_t pos) {

    /* Returning value */
    return STL_Vector_insert(self, elem, STL_Vector_at(self, pos));
}

void *STL_Vector_insert(STL_Vector *self, const void *elem, void *pos) {

    /* VarCheck */
    if (self == NULL) {
        return NULL;
    }

    /* Initializing variables */
    size_t pos_val = (pos - self->data) / self->nbytes;

    /* VarCheck */
    if (pos > STL_Vector_end(self) || pos < STL_Vector_begin(self)) {
        return NULL;
    }

    /* Main part */
    if (++self->nelem >= self->max_nelem) {
        if (STL_Vector_reallocate(self, self->nbytes * self->max_nelem * 2) != STL_Vector_OK) {
            return NULL;
        }
        pos = self->data + pos_val * self->nbytes;
    }

    if (pos != STL_Vector_end(self) - self->nbytes) {
        memmove(pos, pos - self->nbytes, (self->data + self->nelem * self->nbytes) - (pos - self->nbytes));
        memcpy(pos, elem, self->nbytes);
    } else {
        memcpy(pos - self->nbytes, elem, self->nbytes);
    }
    /*    0         1         2       6       3        4         5    */
    /* pos - 3   pos - 2   pos - 1   pos   pos + 1  pos + 2   pos + 3*/

    /* Returning value */
    return pos;
}

void *STL_Vector_erase_pos(STL_Vector *self, size_t pos) {

    /* Returning value */
    return STL_Vector_erase(self, self->data + pos);
}

void *STL_Vector_erase(STL_Vector *self, void *pos) {

    /* VarCheck */
    if (self == NULL) {
        return NULL;
    }

    if (STL_Vector_empty(self)) {
        return NULL;
    }

    /* Main part */
    --self->nelem;

    memmove(pos, pos + self->nbytes, self->data + (self->nelem + 1) * self->nbytes - pos);

    /* Returning value */
    return pos;
}

int STL_Vector_push_back(STL_Vector *self, const void *elem) {

    /* VarCheck */
    if (self == NULL) {
        return STL_Vector_memory_error;
    }

    /* Main part */
    /*if (++self->nelem >= self->max_nelem) {
        if (STL_Vector_reallocate(self, self->nbytes * self->max_nelem * 2) != STL_Vector_OK) {
            return STL_Vector_memory_error;
        }
    }

    memcpy(self->data + self->nbytes * (self->nelem - 1), elem, self->nbytes);*/

    /* Returning value */
    return (int) STL_Vector_insert(self, elem, STL_Vector_end(self));
}

void STL_Vector_pop_back(STL_Vector *self) {

    /* VarCheck */
    if (self == NULL) {
        return;
    }

    /* Main part */
    if (!STL_Vector_empty(self)) {
        --self->nelem;
    }
}

int STL_Vector_resize(STL_Vector *self, size_t count) {

    /* Initializing variables */
    auto size_t old_size;

    /* VarCheck */
    if (self == NULL) {
        return STL_Vector_null_reference_error;
    }

    /* Main part */
    old_size = self->nelem;
    if (STL_Vector_reallocate(self, count * self->nbytes) != STL_Vector_OK) {
        return STL_Vector_memory_error;
    }

    if (count > old_size) {
        memset(self->data, 0, (self->nelem - old_size) * self->nbytes);
    }

    /* Returning value */
    return STL_Vector_OK;
}

void STL_Vector_swap(STL_Vector *self, STL_Vector *other) {

    auto STL_Vector tmp;

    /* VarCheck */
    if (self == NULL || other == NULL) {
        return;
    }

    /* Main part */
    tmp.data = other->data;
    tmp.nelem = other->nelem;
    tmp.nbytes = other->nbytes;
    tmp.max_nelem = other->max_nelem;

    other->data = self->data;
    other->nelem = self->nelem;
    other->nbytes = self->nbytes;
    other->max_nelem = self->max_nelem;

    self->data = tmp.data;
    self->nelem = tmp.nelem;
    self->nbytes = tmp.nbytes;
    self->max_nelem = tmp.max_nelem;
}