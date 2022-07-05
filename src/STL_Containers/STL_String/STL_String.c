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

#include "../../STL_Headers/STL/STL_String.h"

#include <stdlib.h>
#include <string.h>

#ifndef min
#define min(x, y) ((x) < (y) ? (x) : (y))
#endif

static const size_t thresh = 16;
static const size_t npos = -1;

enum yn {
    NO,
    YES
};

static int STL_String_allocate_size(STL_String *self, size_t nchar, enum yn prev)
{

    /* Main part */
    if (prev == YES) {
        if ((self->data = realloc(self->data, nchar)) == NULL) {
            return STL_String_memory_error;
        }
    } else if ((self->data = calloc(nchar, sizeof(char))) == NULL) {
        return STL_String_memory_error;
    }

    /* Returning value */
    return STL_String_OK;
}

static int STL_String_reallocate(STL_String *self, size_t new_size)
{

    /* Initializing variables */
    auto void *tmp = malloc(self->nchar * self->charWidth);

    /* Main part */
    if (tmp == NULL) {
        return STL_String_memory_error;
    }
    memcpy(tmp, self->data, self->nchar * self->charWidth);

    if (STL_String_allocate_size(self, new_size, YES) != STL_String_OK) {
        return STL_String_memory_error;
    }

    self->max_nchar = new_size / self->charWidth;
    self->nchar = (self->nchar > self->max_nchar) ? self->max_nchar : self->nchar;

    memcpy(self->data, tmp, self->charWidth * self->nchar);

    free(tmp);

    /* Returning value */
    return STL_String_OK;
}

int STL_String_init(STL_String *self)
{

    /* Initializing variables */
    if (STL_String_allocate_size(self, thresh, NO) != STL_String_OK) {
        return STL_String_memory_error;
    }

    self->nchar = 0;
    self->max_nchar = thresh;
    self->charWidth = 1;

    /* Returning value */
    return STL_String_OK;
}

int STL_String_init_cpy(STL_String *self, STL_String *other)
{

    /* Main part */
    if (self == NULL || other == NULL) {
        return STL_String_null_reference_error;
    }

    if (STL_String_allocate_size(self, other->charWidth * other->max_nchar, NO) != STL_String_OK) {
        return STL_String_memory_error;
    }

    memcpy(self->data, other->data, other->charWidth * other->nchar);
    self->nchar = other->nchar;
    self->max_nchar = other->max_nchar;
    self->charWidth = other->charWidth;

    /* Returning value */
    return STL_String_OK;
}

void STL_String_delete(STL_String *self)
{

    /* VarCheck */
    if (self == NULL) {
        return;
    }

    /* Main part */
    free(self->data);
}

char *STL_String_at(STL_String *self, size_t n)
{

    /* VarCheck */
    if (self == NULL) {
        return NULL;
    }

    if (n >= self->nchar) {
        return NULL;
    }

    /* Returning value */
    return (char *) (self->data + n);
}

char *STL_String_front(STL_String *self)
{

    /* Returning value */
    return STL_String_at(self, 0);
}

char *STL_String_back(STL_String *self)
{

    /* Returning value */
    return STL_String_at(self, self->nchar - 1);
}

char *STL_String_data(STL_String *self)
{

    /* VarCheck */
    if (self == NULL) {
        return NULL;
    }

    /* Returning value */
    return (char *) self->data;
}

const char *STL_String_c_str(STL_String *self)
{

    /* Returning value */
    return (const char *) STL_String_data(self);
}

char *STL_String_begin(STL_String *self)
{

    /* VarCheck */
    if (self == NULL) {
        return NULL;
    }

    /* Returning value */
    return (char *) self->data;
}

char *STL_String_end(STL_String *self)
{

    /* VarCheck */
    if (self == NULL) {
        return NULL;
    }

    /* Returning value */
    return (char *) (self->data + self->nchar * self->charWidth);
}

int STL_String_empty(STL_String *self)
{

    /* VarCheck */
    if (self == NULL) {
        return STL_String_null_reference_error;
    }

    /* Returning value */
    return (!self->nchar) ? string_is_empty : string_not_empty;
}

size_t STL_String_size(STL_String *self)
{

    /* VarCheck */
    if (self == NULL) {
        return -1;
    }

    /* Returning value */
    return self->nchar;
}

size_t STL_String_length(STL_String *self)
{

    /* Returning value */
    return STL_String_size(self);
}

int STL_String_reserve(STL_String *self, size_t new_cap)
{

    /* VarCheck */
    if (self == NULL) {
        return STL_String_null_reference_error;
    }

    /* Main part */
    if (new_cap <= STL_String_capacity(self)) {
        return STL_String_OK;
    }

    /* Returning value */
    return STL_String_reallocate(self, new_cap * self->charWidth);
}

size_t STL_String_capacity(STL_String *self)
{

    /* VarCheck */
    if (self == NULL) {
        return -1;
    }

    /* Returning value */
    return self->max_nchar;
}

int STL_String_shrink_to_fit(STL_String *self)
{

    /* VarCheck */
    if (self == NULL) {
        return STL_String_null_reference_error;
    }

    /* Returning value */
    return STL_String_reallocate(self, self->charWidth * self->nchar);
}

void STL_String_clear(STL_String *self)
{

    /* VarCheck */
    if (self == NULL) {
        return;
    }

    /* Main part */
    self->nchar = 0;
}

int STL_String_insert(STL_String *self, size_t pos, char ch, size_t count)
{

    /* VarCheck */
    if (self == NULL) {
        return STL_String_null_reference_error;
    }

    if (pos > self->nchar + 1) {
        return STL_String_index_error;
    }

    /* Initializing variables */
    register size_t i;
    auto size_t newSize;

    /* Main part */
    newSize = self->nchar + count;
    while (newSize >= self->max_nchar - 1) {
        if (STL_String_reallocate(self, self->max_nchar * 2) != STL_String_OK) {
            return STL_String_memory_error;
        }
    }
    self->nchar = newSize;
    memmove(self->data + pos + count,
            self->data + pos, count);
    for (i = 0; i < count; ++i) {
        *((char *) (self->data + pos + i)) = ch;
    }
    *((char *) (self->data + self->nchar)) = '\0';

    /* Returning value */
    return STL_String_OK;
}

int STL_String_insert_str(STL_String *self, size_t pos, const char *str)
{

    /* VarCheck */
    if (self == NULL) {
        return STL_String_null_reference_error;
    }

    if (pos > self->nchar + 1) {
        return STL_String_index_error;
    }

    /* Initializing variables */
    auto size_t len = strlen(str);
    auto size_t newSize;

    /* Main part */
    newSize = self->nchar + len;
    while (newSize >= self->max_nchar - 1) {
        if (STL_String_reallocate(self, self->max_nchar * 2) != STL_String_OK) {
            return STL_String_memory_error;
        }
    }

    if (pos != self->nchar) {
        memmove(self->data + pos + len,
                self->data + pos, strlen(self->data + pos));
    }
    self->nchar = newSize;
    memcpy(self->data + pos, str, len);

    /* Returning value */
    return STL_String_OK;
}

void STL_String_erase(STL_String *self, size_t pos, size_t count)
{

    /* VarCheck */
    if (self == NULL) {
        return;
    }

    if (STL_String_empty(self)) {
        return;
    }

    /* Initializing variables */
    auto size_t toRemove = min(count, self->nchar - pos);

    /* Main part */
    self->nchar -= count;

    memmove(self->data + pos, self->data + pos + toRemove, strlen(self->data + pos + toRemove) + 1);
}

void STL_String_push_back(STL_String *self, char ch)
{

    /* Main part */
    STL_String_insert(self, self->nchar, ch, 1lu);
}

void STL_String_pop_back(STL_String *self)
{

    /* Main part */
    STL_String_erase(self, self->nchar, 1lu);
}

void STL_String_append(STL_String *self, char ch, size_t count)
{

    /* Main part */
    STL_String_insert(self, self->nchar, ch, count);
}

void STL_String_append_str(STL_String *self, const char *str)
{

    /* Main part */
    STL_String_insert_str(self, self->nchar, str);
}

int STL_String_compare(STL_String *self, STL_String *other)
{

    /* Returning value */
    return strcmp(self->data, other->data);
}

int STL_String_starts_with(STL_String *self, const char *prefix)
{

    /* VarCheck */
    if (self == NULL || prefix == NULL) {
        return STL_String_null_reference_error;
    }

    /* Returning value */
    return strstr(self->data, prefix) == self->data;
}

int STL_String_ends_with(STL_String *self, const char *prefix)
{

    /* VarCheck */
    if (self == NULL || prefix == NULL) {
        return STL_String_null_reference_error;
    }

    /* Returning value */
    return strlen(strstr(self->data, prefix)) == strlen(self->data);
}

void STL_String_replace(STL_String *self, size_t pos, const char *str, size_t count)
{

    /* VarCheck */
    if (self == NULL || str == NULL) {
        return;
    }

    /* Initializing variables */
    register size_t i;
    auto int toReplace = min(count, self->nchar - pos);

    /* Main part */
    for (i = 0; i < toReplace; ++i) {
        *((char *) self->nchar + pos + i) = *(str + i);
    }
}

STL_String STL_String_substr(STL_String *self, size_t pos, size_t count)
{

    /* Initializing variables */
    STL_String str;
    str.nchar = 0;
    str.max_nchar = 0;
    str.data = NULL;
    str.charWidth = 0;

    /* VarCheck */
    if (self == NULL) {
        return str;
    }

    auto size_t toReturn = min(count, self->nchar - pos);

    /* Main part */
    STL_String_init(self);
    STL_String_insert_str(&str, 0, STL_String_data(self));

    /* Returning value */
    return str;
}

size_t STL_String_copy(STL_String *self, char *dest, size_t count, size_t pos)
{

    /* VarCheck */
    if (self == NULL || dest == NULL) {
        return STL_String_null_reference_error;
    }

    /* Initializing variables */
    auto size_t toCopy = min(count, self->nchar - pos);

    /* Main part */
    while (self->nchar + pos >= self->max_nchar) {
        if (STL_String_reallocate(self, self->max_nchar * 2) != STL_String_OK) {
            return STL_String_memory_error;
        }
    }
    memcpy(dest, (const void *) self->nchar + pos, toCopy);

    /* Returning value */
    return toCopy;
}

int STL_String_resize(STL_String *self, size_t count)
{

    /* VarCheck */
    if (self == NULL) {
        return STL_String_null_reference_error;
    }

    /* Main part */
    if (STL_String_reallocate(self, count) != STL_String_OK) {
        return STL_String_memory_error;
    }

    /* Returning value */
    return STL_String_OK;
}

void STL_String_swap(STL_String *self, STL_String *other)
{

    auto STL_String tmp;

    /* VarCheck */
    if (self == NULL || other == NULL) {
        return;
    }

    /* Main part */
    tmp.data = other->data;
    tmp.nchar = other->nchar;
    tmp.charWidth = other->charWidth;
    tmp.max_nchar = other->max_nchar;

    other->data = self->data;
    other->nchar = self->nchar;
    other->charWidth = self->charWidth;
    other->max_nchar = self->max_nchar;

    self->data = tmp.data;
    self->nchar = tmp.nchar;
    self->charWidth = tmp.charWidth;
    self->max_nchar = tmp.max_nchar;
}

size_t STL_String_find(STL_String *self, const char *str)
{

    /* VarCheck */
    if (self == NULL || str == NULL) {
        return STL_String_null_reference_error;
    }

    /* Initializing variables */
    auto char *substr = strstr(self->data, str);

    /* Returning value */
    return (substr == NULL) ? npos : (substr - (char *) self->data);
}

size_t STL_String_rfind(STL_String *self, const char *str)
{

    /* VarCheck */
    if (self == NULL || str == NULL) {
        return STL_String_null_reference_error;
    }

    /* Initializing variables */
    auto char *substr, *temp;

    /* Main part */
    while ((temp = strstr(self->data, str)) != NULL) {
        substr = temp;
    }

    /* Returning value */
    return (substr == NULL) ? npos : (substr - (char *) self->data);
}

size_t STL_String_find_first_of(STL_String *self, const char *str)
{

    /* VarCheck */
    if (self == NULL || str == NULL) {
        return STL_String_null_reference_error;
    }

    /* Initializing variables */
    register char *iter;
    register const char *iterStr;

    /* Main part */
    for (iter = STL_String_begin(self); iter != STL_String_end(self); ++iter) {
        for (iterStr = str; *iterStr != '\0'; ++iterStr) {
            if (*iter == *iterStr) {
                return iter - (char *) self->data;
            }
        }
    }

    /* Returning value */
    return npos;
}

size_t STL_String_find_first_not_of(STL_String *self, const char *str)
{

    /* VarCheck */
    if (self == NULL || str == NULL) {
        return STL_String_null_reference_error;
    }

    /* Initializing variables */
    register char *iter;
    register const char *iterStr;
    auto size_t notMatched;

    /* Main part */
    for (iter = STL_String_begin(self); iter != STL_String_end(self); ++iter) {
        for (iterStr = str, notMatched = 0; *iterStr != '\0'; ++iterStr) {
            if (*iter != *iterStr) {
                ++notMatched;
            }
        }

        if (notMatched == strlen(str)) {
            return iter - (char *) self->data;
        }
    }

    /* Returning value */
    return npos;
}

size_t STL_String_find_last_of(STL_String *self, const char *str)
{

    /* VarCheck */
    if (self == NULL || str == NULL) {
        return STL_String_null_reference_error;
    }

    /* Initializing variables */
    register char *iter;
    register const char *iterStr;

    /* Main part */
    for (iter = STL_String_end(self) - 1; iter != STL_String_begin(self) - 1; --iter) {
        for (iterStr = str; *iterStr != '\0'; ++iterStr) {
            if (*iter == *iterStr) {
                return iter - (char *) self->data;
            }
        }
    }

    /* Returning value */
    return npos;
}

size_t STL_String_find_last_not_of(STL_String *self, const char *str)
{

    /* VarCheck */
    if (self == NULL || str == NULL) {
        return STL_String_null_reference_error;
    }

    /* Initializing variables */
    register char *iter;
    register const char *iterStr;
    auto size_t notMatched;

    /* Main part */
    for (iter = STL_String_end(self) - 1; iter != STL_String_begin(self) - 1; --iter) {
        for (iterStr = str, notMatched = 0; *iterStr != '\0'; ++iterStr) {
            if (*iter != *iterStr) {
                ++notMatched;
            }
        }

        if (notMatched == strlen(str)) {
            return iter - (char *) self->data;
        }
    }

    /* Returning value */
    return npos;
}

size_t STL_String_npos()
{

    /* Returning value */
    return npos;
}
