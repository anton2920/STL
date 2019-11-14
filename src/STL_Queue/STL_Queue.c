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

#include "../STL_List/STL_List.h"
#include "STL_Queue.h"

int STL_Queue_init(STL_Queue *this) {

    /* Returning value */
    return STL_List_init((STL_List *) this);
}

void STL_Queue_delete(STL_Queue *this) {

    /* Main part */
    STL_List_delete((STL_List *) this);
}

void *STL_Queue_front(STL_Queue *this) {

    /* Main part */
    if (this->bp == NULL) {
        return NULL;
    } else {
        return this->bp->value;
    }
}

void *STL_Queue_back(STL_Queue *this) {

    /* Main part */
    if (this->lp == NULL) {
        return NULL;
    } else {
        return this->lp->value;
    }
}

int STL_Queue_empty(STL_Queue *this) {

    /* Returning value */
    return STL_List_empty((STL_List *) this);
}

size_t STL_Queue_size(STL_Queue *this) {

    /* Returning value */
    return STL_List_size((STL_List *) this);
}

int STL_Queue_push(STL_Queue *this, const void *elem, size_t nbytes) {

    /* Returning value */
    return STL_List_push_front((STL_List *) this, elem, nbytes);
}

void STL_Queue_pop(STL_Queue *this) {

    /* Main part */
    STL_List_pop_back((STL_List *) this);
}

void STL_Queue_swap(STL_Queue *this, STL_Queue *other) {
    STL_List_swap((STL_List *) this, (STL_List *) other);
}
