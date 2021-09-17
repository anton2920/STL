/*
Sorting library — free shared library, that contains a few general-purpose sorting algorithms
Copyright © Pavlovsky Anton, 2019-2021

This file is part of Sorting library.

Sorting library is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Sorting library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Sorting library. If not, see <https://www.gnu.org/licenses/>.
*/

#include "../STL_Headers/STL/STL_Algorithm.h"

#include <stdlib.h>


/* Basic functions for compare */
int STL_numcmp(const void *num1, const void *num2)
{

    /* Compares two strings numerically */

    /* Initializing variables */
    auto double d1 = atof(num1), d2 = atof(num2);

    /* Returning value */
    return (d1 > d2) ? GREATER : (d1 < d2) ? LESS : EQUALS;
}

int STL_inumcmp(const void *num1, const void *num2)
{

    /* Compares integers */

    /* Initializing variables */
    auto int d1 = *((int *) num1), d2 = *((int *) num2);

    /* Returning value */
    return (d1 > d2) ? GREATER : (d1 < d2) ? LESS : EQUALS;
}

int STL_dnumcmp(const void *num1, const void *num2)
{

    /* Compares doubles */

    /* Initializing variables */
    auto double d1 = *((double *) num1), d2 = *((double *) num2);

    /* Returning value */
    return (d1 > d2) ? GREATER : (d1 < d2) ? LESS : EQUALS;
}