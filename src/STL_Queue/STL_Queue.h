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

#ifndef SRC_STL_QUEUE_H
#define SRC_STL_QUEUE_H

/* Definition of STL_Queue type */
typedef STL_List STL_Queue;
typedef STL_List_node STL_Queue_node;

/* Functions declarations */
int STL_Queue_init(STL_Queue *);
void STL_Queue_delete(STL_Queue *);

void *STL_Queue_front(STL_Queue *);
void *STL_Queue_back(STL_Queue *);

int STL_Queue_empty(STL_Queue *);
size_t STL_Queue_size(STL_Queue *);

int STL_Queue_push(STL_Queue *, const void *, size_t);
void STL_Queue_pop(STL_Queue *);

void STL_Queue_swap(STL_Queue *, STL_Queue *);

#endif
