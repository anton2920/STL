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

#ifndef SRC_STL_ALGORITHM_H
#define SRC_STL_ALGORITHM_H

#include <stddef.h>

/* Macros */
#ifndef GREATER
    #define GREATER (1)
#endif
#ifndef LESS
    #define LESS (-1)
#endif
#ifndef EQUALS
    #define EQUALS (0)
#endif

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

#ifndef MIN
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#endif

/* Types */
#ifndef __BOOL_TYPE
    #define __BOOL_TYPE
    typedef enum {
        __false = 0,
        __true = 1
    } __bool;
#endif

/* Basic functions for compare */
int STL_numcmp(const void *, const void *); /* Compares strings numerically */
int STL_inumcmp(const void *, const void *); /* Compares integers */
int STL_dnumcmp(const void *, const void *); /* Compares doubles */

/* Miscellaneous routines */
void *STL_binary_search(const void *key, const void *pbase, size_t n, size_t nbytes, int (*cmp)(const void *, const void *));

/* Basic sorting algorithms */
void STL_bubble_sort(void *pbase, size_t n, size_t nbytes, int (*cmp)(const void *, const void *));
void STL_selection_sort(void *pbase, size_t n, size_t nbytes, int (*cmp)(const void *, const void *));
void STL_insertion_sort(void *pbase, size_t n, size_t nbytes, int (*cmp)(const void *, const void *));
void STL_shell_sort(void *pbase, size_t n, size_t nbytes, int (*cmp)(const void *, const void *));

/* Advanced sorting algorithms */
void STL_quick_sort(void *pbase, size_t n, size_t nbytes, int (*cmp)(const void *, const void *));
void STL_merge_sort(void *pbase, size_t n, size_t nbytes, int (*cmp)(const void *, const void *));

#endif