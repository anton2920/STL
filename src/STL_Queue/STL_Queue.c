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

#include "../STL_Headers/STL/STL_Queue.h"

int STL_Queue_init(STL_Queue *self) {

    /* Returning value */
    return STL_List_init((STL_List *) self);
}

void STL_Queue_delete(STL_Queue *self) {

    /* Main part */
    STL_List_delete((STL_List *) self);
}

void *STL_Queue_front(const STL_Queue *queue) {

    /* Returning value */
    return STL_List_front((STL_List *) queue);
}

void *STL_Queue_back(const STL_Queue *queue) {

    /* Returning value */
    return STL_List_back((STL_List *) queue);
}

int STL_Queue_empty(const STL_Queue *queue) {

    /* Returning value */
    return STL_List_empty((STL_List *) queue);
}

size_t STL_Queue_size(const STL_Queue *queue) {

    /* Returning value */
    return STL_List_size((STL_List *) queue);
}

int STL_Queue_push(STL_Queue *self, const void *elem, size_t nbytes) {

    /* Returning value */
    return STL_List_push_front((STL_List *) self, elem, nbytes);
}

void STL_Queue_pop(STL_Queue *self) {

    /* Main part */
    STL_List_pop_back((STL_List *) self);
}

void STL_Queue_swap(STL_Queue *self, STL_Queue *other) {

    /* Main part */
    STL_List_swap((STL_List *) self, (STL_List *) other);
}
