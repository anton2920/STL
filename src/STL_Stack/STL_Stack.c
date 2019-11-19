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

#include "../STL_Headers/STL/STL_Stack.h"

int STL_Stack_init(STL_Stack *self) {

    /* Returning value */
    return STL_List_init((STL_List *) self);
}

void STL_Stack_delete(STL_Stack *self) {

    /* Main part */
    STL_List_delete((STL_List *) self);
}

void *STL_Stack_top(const STL_Stack *stack) {

    /* Returning value */
    return STL_List_back((STL_List *) stack);
}

int STL_Stack_empty(const STL_Stack *stack) {

    /* Returning value */
    return STL_List_empty((STL_List *) stack);
}

size_t STL_Stack_size(const STL_Stack *stack) {

    /* Returning value */
    return STL_List_size((STL_List *) stack);
}

int STL_Stack_push(STL_Stack *self, const void *elem, size_t nbytes) {

    /* Returning value */
    return STL_List_push_back((STL_List *) self, elem, nbytes);
}

void STL_Stack_pop(STL_Stack *self) {

    /* Main part */
    STL_List_pop_back((STL_List *) self);
}

void STL_Stack_swap(STL_Stack *self, STL_Stack *other) {

    /* Main part */
    STL_List_swap((STL_List *) self, (STL_List *) other);
}