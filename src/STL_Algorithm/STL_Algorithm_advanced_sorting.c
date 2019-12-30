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

#include "../STL_Headers/STL/STL_Algorithm.h"

#if (HAVE_STRING_H == 1)
    #include <string.h>
#endif

#if (HAVE_LIMITS_H == 1)
    #include <limits.h>
#endif

#if (HAVE_STDLIB_H == 1)
#include <stdlib.h>
#endif

/* Miscellaneous routines */
static void *pivot_arr (void *arr, size_t nbytes, size_t low, size_t high, int (*cmp)(const void *, const void *)) {

    /* This functions is used for taking a choice for a pivot and rearranging
     * array, that elements smaller than a pivot go to left of pivot, and all greater
     * elements go to right of pivot */

    /* Initializing variables */
    auto char *p = (char *) arr;
    auto char *x = p + high * nbytes;
    register size_t i = low - 1, j;

    /* Main part */
    for (j = low; j <= high - 1; ++j) {
        if ((*cmp)((const void *) (p + j * nbytes), (const void *) (x)) <= 0) {
            ++i;
            SWAP((p + i * nbytes), (p + j * nbytes), nbytes);
        }
    }
    SWAP((p + (i + 1) * nbytes), x, nbytes);

    /* Returning value */
    return (void *) (p + (i + 1) * nbytes);
}

static void merge(void *pbase, size_t nbytes, size_t left, int mid, int right, int (*cmp)(const void *, const void *)) {

    /* Initializing variables */
    auto char *p = (char *) pbase;
    register size_t i, j, k;
    auto size_t n1 = mid - left + 1, n2 = right - mid;

    /*auto char L[n1 * nbytes], R[n2 * nbytes];*/
    auto char *L = malloc(n1 * nbytes);
    auto char *R = malloc(n2 * nbytes);

    if (L == NULL || R == NULL) {
        return;
    }

    /* Main part */
    for (i = 0; i < n1; ++i) {
        memcpy((L + i * nbytes), (p + (left + i) * nbytes), nbytes);
    }
    for (j = 0; j < n2; ++j) {
        memcpy((R + j * nbytes), (p + (mid + 1 + j) * nbytes), nbytes);
    }

    for (i = 0, j = 0, k = left; i < n1 && j < n2; ) {
        if ((*cmp)((const void *) (L + i * nbytes), (const void *) (R + j * nbytes)) <= 0) {
            memcpy((p + k * nbytes), (L + i * nbytes), nbytes);
            ++i;
        } else {
            memcpy((p + k * nbytes), (R + j * nbytes), nbytes);
            ++j;
        }
        ++k;
    }

    for ( ; i < n1; ++i, ++k) {
        memcpy((p + k * nbytes), (L + i * nbytes), nbytes);
    }

    for ( ; j < n2; ++j, ++k) {
        memcpy((p + k * nbytes), (R + j * nbytes), nbytes);
    }

    free(L);
    free(R);
}

typedef struct {
    char *lo;
    char *hi;
} stack_node;

#define STACK_SIZE          (CHAR_BIT * sizeof (size_t))
#define PUSH(low, high)     ((void) ((top->lo = (low)), (top->hi = (high)), ++top))
#define POP(low, high)      ((void) (--top, (low = top->lo), (high = top->hi)))
#define STACK_NOT_EMPTY     (stack < top)

/* Advanced sorting algorithms */
void STL_quick_sort(void *pbase, size_t n, size_t nbytes, int (*cmp)(const void *, const void *)) {

    /* VarCheck */
    if (n <= 1) {
        return;
    }

    /* Initializing variables */
    auto char *base_ptr = (char *) pbase, *piv = NULL;
    auto char *lo = base_ptr;
    auto char *hi = &lo[nbytes * (n - 1)];

    /* Auxiliary stack sh**t */
    auto stack_node stack[STACK_SIZE];
    register stack_node *top = stack;

    PUSH(lo, hi);

    /* Main part */
    for ( ; STACK_NOT_EMPTY; ) {
        POP(lo, hi);

        piv = pivot_arr(pbase, nbytes, (lo - base_ptr) / nbytes, (hi - base_ptr) / nbytes, cmp);

        if (piv - nbytes > lo) {
            PUSH(lo, piv-nbytes);
        }

        if (piv + nbytes < hi) {
            PUSH(piv + nbytes, hi);
        }
    }
}

void STL_merge_sort(void *pbase, size_t n, size_t nbytes, int (*cmp)(const void *, const void *)) {

    /* Initializing variables */
    register size_t curr_size, left_start;

    auto size_t mid, right_end;

    /* Main part */
    for (curr_size = 1; curr_size <= n - 1; curr_size <<= 1) {
        for (left_start = 0; left_start < n - 1; left_start += curr_size << 1) {
            mid = left_start + curr_size - 1;
            right_end = MIN((left_start + (curr_size << 1) - 1), n - 1);

            if (mid >= right_end) {
                break;
            }
            merge(pbase, nbytes, left_start, mid, right_end, cmp);
        }
    }
}