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

/* Miscellaneous routines */
void *STL_binary_search(const void *key, const void *pbase, size_t n, size_t nbytes, int (*cmp)(const void *, const void *)) {

    /* Initializing variables */
    auto const char *p = (char *) pbase, *pivot = NULL;
    int res;

    /* Main part */
    for ( ; n > 0; n >>= 1) {
        pivot = p + (n >> 1) * nbytes;
        if (!(res = (*cmp)(key, (const void *) pivot))) {
            return (void *) pivot;
        }

        if (res > 0) {
            p = pivot + nbytes;
            --n;
        }
    }

    /* Returning value */
    return NULL;
}