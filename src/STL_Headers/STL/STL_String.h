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

#ifndef SRC_STL_STRING_H
#define SRC_STL_STRING_H

#include <stddef.h>

/* Include STL_Basic_string definition */
#include "__internal/__STL_Basic_string.h"

/* Definition of STL_String */
typedef STL_Basic_string STL_String;

/* STL_String errors */
enum STL_String_errors {
    STL_String_OK = 1,                /* Everything is OK. Not an error */
    STL_String_memory_error,          /* If STL_String routine can't allocate memory */
    STL_String_index_error,           /* If desired position is wrong */
    STL_String_null_reference_error   /* If (STL_String *) or (const void *elem) is NULL */
};

/* STL_String states */
enum STL_String_states {
    string_not_empty = 0,
    string_is_empty
};

/* STL_String methods */
/* Construction and destruction */
int STL_String_init(STL_String *self); /* Constructs a string. Returns STL_String_OK if OK */
int STL_String_init_cpy(STL_String *self, STL_String *other); /* Copies the string. Returns STL_String_OK if OK */
void STL_String_delete(STL_String *self); /* Destroys the string, deallocating internal storage if used */

/* Element access */
char *STL_String_at(STL_String *self, size_t pos); /* Accesses the specified character with bounds checking */
char *STL_String_front(STL_String *self); /* Accesses the first character */
char *STL_String_back(STL_String *self); /* Accesses the last character*/

char *STL_String_data(STL_String *self); /* Returns a pointer to the first character of a string */
const char *STL_String_c_str(STL_String *self); /* Returns a non-modifiable standard C character array version of the string */

/* Iterators */
char *STL_String_begin(STL_String *self); /* Returns an iterator to the beginning */
char *STL_String_end(STL_String *self); /* Returns an iterator to the end */

/* Capacity */
int STL_String_empty(STL_String *self); /* Checks whether the string is empty */
size_t STL_String_size(STL_String *self); /* Returns the number of characters */
size_t STL_String_length(STL_String *self); /* Returns the number of characters */

int STL_String_reserve(STL_String *self, size_t new_cap); /* Reserves storage */
size_t STL_String_capacity(STL_String *self); /* Returns the number of characters that can be held in currently allocated storage */
int STL_String_shrink_to_fit(STL_String *self); /* Reduces memory usage by freeing unused memory */

/* Operations */
void STL_String_clear(STL_String *self); /* Clears the contents */

int STL_String_insert(STL_String *self, size_t pos, char ch, size_t count); /* Inserts characters */
int STL_String_insert_str(STL_String *self, size_t pos, const char *str); /* Inserts substring */

void STL_String_erase(STL_String *self, size_t pos, size_t count); /* Removes characters */

void STL_String_push_back(STL_String *self, char ch); /* Appends a character to the end */
void STL_String_pop_back(STL_String *self); /* Removes the last character */

void STL_String_append(STL_String *self, char ch, size_t count); /* Appends characters to the end */
void STL_String_append_str(STL_String *self, const char *str); /* Appends substring to the end */

int STL_String_compare(STL_String *self, STL_String *other); /* Compares two strings */
int STL_String_starts_with(STL_String *self, const char *prefix); /* Checks if the string starts with the given prefix */
int STL_String_ends_with(STL_String *self, const char *prefix); /* Checks if the string ends with the given prefix */

void STL_String_replace(STL_String *self, size_t pos, const char *str, size_t count); /* Replaces specified portion of a string */
STL_String STL_String_substr(STL_String *self, size_t pos, size_t count); /* Returns a substring */

size_t STL_String_copy(STL_String *self, char *dest, size_t count, size_t pos); /* Copies characters */
int STL_String_resize(STL_String *self, size_t count); /* Changes the number of characters stored */

void STL_String_swap(STL_String *self, STL_String *other); /* Swaps the contents */

/* Search */
size_t STL_String_find(STL_String *self, const char *str); /* Find characters in the string */
size_t STL_String_rfind(STL_String *self, const char *str); /* Find the last occurrence of a substring */

size_t STL_String_find_first_of(STL_String *self, const char *str); /* Find the first occurrence of characters */
size_t STL_String_find_first_not_of(STL_String *self, const char *str); /* Find the first absence of characters */
size_t STL_String_find_last_of(STL_String *self, const char *str); /* Find the last occurrence of characters */
size_t STL_String_find_last_not_of(STL_String *self, const char *str); /* Find the last absence of characters */

size_t STL_String_npos(); /* Special value. The exact meaning depends on the context */

#endif
