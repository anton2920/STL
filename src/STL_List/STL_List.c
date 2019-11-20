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

#include <stdlib.h>
#include <string.h>

#include "../STL_Headers/STL/STL_List.h"

static void STL_List_check_pointers(STL_List *l) {
    if (l->bp != NULL && l->lp == NULL) {
        l->lp = l->bp;
    } else if (l->lp != NULL && l->bp == NULL) {
        l->bp = l->lp;
    }
}

int STL_List_init(STL_List *l) {

    /* Main part */
    if (l == NULL) {
        return STL_List_null_reference_error;
    }

    l->lp = l->bp = NULL;
    l->size = 0;

    /* Returning value */
    return STL_List_OK;
}

int STL_List_init_cpy(STL_List *self, STL_List *other) {

    /* Initializing variables */
    register STL_List_node *iter;
    auto int code;

    /* VarCheck */
    code = STL_List_init(self);
    if (other == NULL || code != STL_List_OK) {
        return code;
    }

    for (iter = STL_List_begin(other); iter != NULL; iter = iter->next) {
        STL_List_push_back(self, iter->value, iter->size);
    }

    /* Returning value */
    return STL_List_OK;
}

void STL_List_delete(STL_List *l) {

    /* Main part */
    if (l == NULL) {
        return;
    }

    STL_List_clear(l);
}

void STL_List_clear(STL_List *l) {

    /* Main part */
    if (l == NULL) {
        return;
    }

    while (l->size) {
        STL_List_pop_back(l);
    }
}

void *STL_List_front(const STL_List *l) {

    /* VarCheck */
    if (l == NULL) {
        return NULL;
    }

    /* Main part */
    if (l->bp == NULL) {
        return NULL;
    } else {
        return l->bp->value;
    }
}

void *STL_List_back(const STL_List *l) {

    /* VarCheck */
    if (l == NULL) {
        return NULL;
    }

    /* Main part */
    if (l->lp == NULL) {
        return NULL;
    } else {
        return l->lp->value;
    }
}

int STL_List_insert_pos(STL_List *l, const void *elem, size_t size, size_t pos) {

    /* Initializing variables */
    register size_t i;
    auto STL_List_node *iter;

    /* Main part */
    if (l == NULL || elem == NULL) {
        return STL_List_null_reference_error;
    }

    if (pos > l->size) {
        return STL_List_index_error;
    }

    if (l->bp == NULL) {
        return STL_List_push_front(l, elem, size);
    }

    if (pos > l->size / 2) {
        for (iter = STL_List_end(l), i = l->size; iter->prev != NULL && i >= pos; iter = iter->prev, --i)
            ;
    } else {
        for (iter = STL_List_begin(l), i = 0; iter->next != NULL && i < pos; iter = iter->next, ++i)
            ;
    }

    /* Returning value */
    return STL_List_insert(l, elem, size, iter);
}

int STL_List_insert(STL_List *l, const void *elem, size_t size, STL_List_node *pos) {

    /* Initializing variables */
    auto STL_List_node *new_element;

    /* Main part */
    if (l == NULL || elem == NULL) {
        return STL_List_null_reference_error;
    }

    /* Inserting element */
    if ((new_element = (STL_List_node *) calloc(1, sizeof(STL_List_node))) == NULL) {
        return STL_List_memory_error;
    }
    if ((new_element->value = malloc(size)) == NULL) {
        return STL_List_memory_error;
    }

    memcpy(new_element->value, elem, size);
    new_element->size = size;

    if (l->bp == NULL) {
        new_element->next = NULL;
        new_element->prev = NULL;
        l->bp = l->lp = new_element;
    } else if (pos != NULL) {
        new_element->next = pos;
        new_element->prev = pos->prev;

        if (pos->prev != NULL) {
            pos->prev->next = new_element;
        }
        pos->prev = new_element;

        /* Managing list */
        if (new_element->prev == NULL) {
            l->bp = new_element;
        } else if (new_element->next == NULL) {
            l->lp = new_element;
        }

        STL_List_check_pointers(l);
    }

    ++l->size;

    /* Returning value */
    return STL_List_OK;
}

int STL_List_push_back(STL_List *l, const void *elem, size_t size) {

    /* Initializing variables */
    auto STL_List_node *new_element;

    /* Main part */
    if (l == NULL || elem == NULL) {
        return STL_List_null_reference_error;
    }

    if ((new_element = (STL_List_node *) calloc(1, sizeof(STL_List_node))) == NULL) {
        return STL_List_memory_error;
    }
    if ((new_element->value = malloc(size)) == NULL) {
        return STL_List_memory_error;
    }

    memcpy(new_element->value, elem, size);
    new_element->size = size;

    if (l->bp == NULL) {
        new_element->next = NULL;
        new_element->prev = NULL;
        l->bp = l->lp = new_element;
    } else {
        new_element->next = NULL;
        new_element->prev = l->lp;
        l->lp->next = new_element;

        l->lp = new_element;
    }

    ++l->size;

    STL_List_check_pointers(l);

    /* Returning value */
    return STL_List_OK;
}

int STL_List_push_front(STL_List *l, const void *elem, size_t size) {

    /* Returning value */
    return STL_List_insert(l, elem, size, l->bp);
}

STL_List_node *STL_List_erase_pos(STL_List *l, size_t pos) {

    /* Initializing variables */
    register size_t i;
    auto STL_List_node *iter;

    /* Main part */
    if (l == NULL) {
        return NULL;
    }

    if (pos > l->size / 2) {
        for (iter = STL_List_end(l), i = l->size; iter->prev != NULL && i >= pos; iter = iter->prev, --i)
            ;
    } else {
        for (iter = STL_List_begin(l), i = 0; iter->next != NULL && i <= pos; iter = iter->next, ++i)
            ;
    }

    /* Returning value */
    return STL_List_erase(l, iter);
}

STL_List_node *STL_List_erase(STL_List *l, STL_List_node *pos) {

    /* Initializing variables */
    auto STL_List_node *ret;

    /* Main part */
    if (l == NULL || pos == NULL) {
        return NULL;
    }

    if (pos->prev != NULL) {
        pos->prev->next = pos->next;
    } else {
        l->bp = pos->next;
    }
    if (pos->next != NULL) {
        pos->next->prev = pos->prev;
    } else {
        l->lp = pos->prev;
    }

    free(pos->value);
    if (pos->next == NULL) {
        ret = STL_List_end(l);
    } else {
        ret = pos->next;
    }
    free(pos);

    --l->size;

    STL_List_check_pointers(l);

    /* Returning value */
    return ret;
}

STL_List_node *STL_List_pop_back(STL_List *l) {

    /* Returning value */
    return STL_List_erase(l, l->lp);
}

STL_List_node *STL_List_pop_front(STL_List *l) {

    /* Returning value */
    return STL_List_erase(l, l->bp);
}

int STL_List_empty(STL_List *l) {

    /* Returning value */
    return (l->size) ? not_empty : is_empty;
}

size_t STL_List_size(STL_List *l) {

    /* Main part */
    if (l == NULL) {
        return 0;
    }

    /* Returning value */
    return l->size;
}

STL_List_node *STL_List_begin(STL_List *l) {

    /* Returning value */
    return l->bp;
}

STL_List_node *STL_List_end(STL_List *l) {

    /* Returning value */
    return l->lp;
}

void STL_List_merge(STL_List *self, STL_List *other, int (*cmp)(const void *, const void *)) {

    /* Initializing variables */
    auto STL_List_node *i1, *i2;

    /* VarCheck */
    if (self == NULL || other == NULL || STL_List_empty(other)) {
        return;
    }

    /* Main part */
    if (!STL_List_empty(self)) {
        for (i1 = STL_List_begin(self), i2 = STL_List_begin(other);
             i1 != NULL && i2 != NULL; ) {
            if (cmp(i1->value, i2->value) < 0) {
                i1 = i1->next;
            } else {
                STL_List_insert(self, i2->value, i2->size, i1);
                i2 = STL_List_erase(other, i2);
            };
        }

        if (!STL_List_empty(other)) {
            goto case_2;
        }
    } else {
case_2:
        for (i2 = STL_List_begin(other); i2 != NULL; i2 = STL_List_erase(other, i2)) {
            STL_List_push_back(self, i2->value, i2->size);
        }
    }

}

static void STL_List_sort_merge(STL_List_node **start1, STL_List_node **end1,
        STL_List_node **start2, STL_List_node **end2, int (*cmp)(const void *, const void *))
{

    /* Initializing variables */

}

void STL_List_sort(STL_List *l, size_t n, int (*cmp)(const void *, const void *)) {

    /* Initializing variables */

}

void STL_List_swap_nodes(STL_List_node *a, STL_List_node *b) {

    /* Initializing variables */
    auto STL_List_node tmp;

    /* Main part */
    tmp.value = b->value;
    tmp.size = b->size;

    b->value = a->value;
    b->size = a->size;

    a->value = tmp.value;
    a->size = tmp.size;
}

void STL_List_swap(STL_List *self, STL_List *other) {

    /* Initializing variables */
    auto STL_List tmp;

    /* Main part */
    tmp.bp = other->bp;
    tmp.lp = other->lp;
    tmp.size = other->size;

    other->bp = self->bp;
    other->lp = self->lp;
    other->size = self->size;

    self->bp = tmp.bp;
    self->lp = tmp.lp;
    self->size = tmp.size;
}

size_t STL_List_size_node(STL_List_node *l) {

    /* Returning value */
    return l->size;
}