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

#include "../STL_Headers/STL/STL_Algorithm.h"

#include <math.h>
#include <string.h>


/* Basic sorting algorithms */
void STL_bubble_sort(void *pbase, size_t n, size_t nbytes, int (*cmp)(const void *, const void *)) {

    /* Initializing variables */
    register size_t i, j;
    auto char *p = (char *) pbase;
    auto __bool is_swapped;

    /* Main part */
    for (i = 1; i < n; ++i) {
        is_swapped = __false;
        for (j = 0; j < n - i; ++j) {
            if ((*cmp)((const void *) (p + j * nbytes), (const void *) (p + (j + 1) * nbytes)) > 0) {
                SWAP((p + j * nbytes), (p + (j + 1) * nbytes), nbytes);
                is_swapped = __true;
            }
        }

        if (!is_swapped) {
            break;
        }
    }
}

void STL_selection_sort(void *pbase, size_t n, size_t nbytes, int (*cmp)(const void *, const void *)) {

    /* Initializing variables */
    register size_t i, j, min_index = 0;
    auto char *p = (char *) pbase;

    /* Main part */
    for (i = 0; i < n - 1; ++i) {
        min_index = i;
        for (j = i + 1; j < n; ++j) {
            if ((*cmp)((const void *) (p + j * nbytes), (const void *) (p + min_index * nbytes)) < 0) {
                min_index = j;
            }
        }

        if (i != min_index) {
            SWAP((p + i * nbytes), (p + min_index * nbytes), nbytes);
        }
    }
}

void STL_insertion_sort(void *pbase, size_t n, size_t nbytes, int (*cmp)(const void *, const void *)) {

    /* Initializing variables */
    register long i, j;
    auto char *p = (char *) pbase, key[nbytes];

    /* Main part */
    for (i = 1; i < n; ++i) {
        memcpy(key, (p + i * nbytes), nbytes);

        for (j = i - 1; j >= 0 &&
                (*cmp)((const void *) (p + j * nbytes), (const void *) key) > 0; --j) {
            memcpy((p + (j + 1) * nbytes), (p + j * nbytes), nbytes);
        }

        memcpy((p + (j + 1) * nbytes), key, nbytes);
    }
}

void STL_shell_sort(void *pbase, size_t n, size_t nbytes, int (*cmp)(const void *, const void *)) {

    /* Initializing variables */
    auto char *p = (char *) pbase, temp[nbytes];
    register size_t i, j, gap;

    /* Main part */
    for (gap = 1; gap < n / 3 ; gap = gap * 3 + 1)
        ;

    for ( ; gap > 0; gap = (gap - 1) / 3) {
        for (i = gap; i < n; ++i) {
            memcpy(temp, (p + i * nbytes), nbytes);
            for (j = i; j >= gap && (*cmp)((const void *) (p + (j - gap) * nbytes), (const void *) temp) > 0; j -= gap) {
                memcpy((p + j * nbytes), (p + (j - gap) * nbytes), nbytes);
            }

            memcpy((p + j * nbytes), temp, nbytes);
        }
    }
}