/*
Standard Template Library for C — free shared library, that contains an attempt of recreation of libc++ STL
Copyright © Pavlovsky Anton, 2019-2022

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

#include "../../STL_Headers/STL/STL_Forward_list.h"

#include <stdlib.h>
#include <string.h>


static void STL_Forward_list_check_pointers(STL_Forward_list *l)
{

    /* Main part */
    if ((l->bp != NULL && l->lp == NULL)) {
        l->lp = l->bp->next;
    }
}

int STL_Forward_list_init(STL_Forward_list *l)
{

    /* Main part */
    if (l == NULL) {
        return STL_Forward_list_null_reference_error;
    }

    if ((l->bp = malloc(sizeof(STL_Forward_list_node))) == NULL) {
        return STL_Forward_list_memory_error;
    }

    if ((l->lp = l->bp->next = malloc(sizeof(STL_Forward_list_node))) == NULL) {
        return STL_Forward_list_memory_error;
    }

    l->size = 0;

    l->bp->value = l->lp->value = NULL;
    l->bp->size = 0;

    /* Returning value */
    return STL_Forward_list_OK;
}

int STL_Forward_list_init_cpy(STL_Forward_list *self, STL_Forward_list *other)
{

    /* Initializing variables */
    register STL_Forward_list_node *iter;
    auto int code;

    /* Main part */
    code = STL_Forward_list_init(self);
    if (other == NULL || code != STL_Forward_list_OK) {
        return code;
    }

    for (iter = STL_Forward_list_begin(other); iter != STL_Forward_list_end(other); iter = iter->next) {
        STL_Forward_list_push_front(self, iter->value, iter->size);
    }

    STL_Forward_list_reverse(self);

    /* Returning value */
    return STL_Forward_list_OK;
}

void STL_Forward_list_delete(STL_Forward_list *l)
{

    /* Main part */
    if (l == NULL) {
        return;
    }

    STL_Forward_list_clear(l);

    free(l->bp);
}

void *STL_Forward_list_front(const STL_Forward_list *l)
{

    /* VarCheck */
    if (l == NULL) {
        return NULL;
    }

    /* Main part */
    if (l->bp == NULL) {
        return NULL;
    } else if (l->bp->next == NULL) {
        return NULL;
    } else {
        return l->bp->next->value;
    }
}

STL_Forward_list_node *STL_Forward_list_before_begin(STL_Forward_list *l)
{

    /* Returning value */
    return l->bp;
}

STL_Forward_list_node *STL_Forward_list_begin(STL_Forward_list *l)
{

    /* VarCheck */
    if (l->bp == NULL) {
        return NULL;
    }

    /* Returning value */
    return l->bp->next;
}

STL_Forward_list_node *STL_Forward_list_end(STL_Forward_list *l)
{

    /* Returning value */
    return l->lp;
}

int STL_Forward_list_empty(STL_Forward_list *l)
{

    /* Returning value */
    return (l->size) ? forward_list_not_empty : forward_list_is_empty;
}

size_t STL_Forward_list_size(STL_Forward_list *l)
{

    /* Main part */
    if (l == NULL) {
        return 0;
    }

    /* Returning value */
    return l->size;
}

void STL_Forward_list_clear(STL_Forward_list *l)
{

    /* Main part */
    if (l == NULL) {
        return;
    }

    while (l->size) {
        STL_Forward_list_pop_front(l);
    }

    STL_Forward_list_check_pointers(l);
}

int STL_Forward_list_insert_after(STL_Forward_list *l, const void *elem, size_t size, STL_Forward_list_node *pos)
{

    /* Initializing variables */
    auto STL_Forward_list_node *new_element;

    /* Main part */
    if (l == NULL || elem == NULL) {
        return STL_Forward_list_null_reference_error;
    }

    /* Inserting element */
    if ((new_element = (STL_Forward_list_node *) calloc(1, sizeof(STL_Forward_list_node))) == NULL) {
        return STL_Forward_list_memory_error;
    }
    if ((new_element->value = malloc(size)) == NULL) {
        return STL_Forward_list_memory_error;
    }

    memcpy(new_element->value, elem, size);
    new_element->size = size;

    if (pos != NULL) {
        new_element->next = pos->next;
        pos->next = new_element;

        /* Managing list */
        if (new_element->next == NULL) {
            l->lp = new_element;
        }

        STL_Forward_list_check_pointers(l);

        ++l->size;
    } else {
        free(new_element);
    }


    /* Returning value */
    return STL_Forward_list_OK;
}

STL_Forward_list_node *STL_Forward_list_erase_after(STL_Forward_list *l, STL_Forward_list_node *pos)
{

    /* Initializing variables */
    auto STL_Forward_list_node *ret;

    /* Main part */
    if (l == NULL || pos == NULL || STL_Forward_list_empty(l)) {
        return NULL;
    }

    pos->next = pos->next->next;

    free(pos->next->value);
    if (pos->next == NULL) {
        ret = STL_Forward_list_end(l);
    } else {
        ret = pos->next->next;
    }
    free(pos->next);

    --l->size;

    STL_Forward_list_check_pointers(l);

    /* Returning value */
    return ret;
}

int STL_Forward_list_push_front(STL_Forward_list *l, const void *elem, size_t size)
{

    /* Returning value */
    return STL_Forward_list_insert_after(l, elem, size, STL_Forward_list_before_begin(l));
}

STL_Forward_list_node *STL_Forward_list_pop_front(STL_Forward_list *l)
{

    /* Returning value */
    return STL_Forward_list_erase_after(l, STL_Forward_list_before_begin(l));
}

void STL_Forward_list_merge(STL_Forward_list *self, STL_Forward_list *other, int (*cmp)(const void *, const void *))
{

    /* Initializing variables */
    auto STL_Forward_list_node *i1 = STL_Forward_list_before_begin(self), *i2;

    /* VarCheck */
    if (self == NULL || other == NULL || STL_Forward_list_empty(other)) {
        return;
    }

    /* Main part */
    if (!STL_Forward_list_empty(self)) {
        for (i1 = STL_Forward_list_before_begin(self), i2 = STL_Forward_list_before_begin(other);
             i1->next != STL_Forward_list_end(self) && i2->next != STL_Forward_list_end(other); ) {
            if (cmp(i1->next->value, i2->value) < 0) {
                i1 = i1->next;
            } else {
                STL_Forward_list_insert_after(self, i2->value, i2->size, i1);
                i2 = STL_Forward_list_erase_after(other, i2);
            };
        }

        if (!STL_Forward_list_empty(other)) {
            goto case_2;
        }
    } else {
        case_2:
        for (i2 = STL_Forward_list_before_begin(other);
             i2->next != STL_Forward_list_end(other);
             i2 = STL_Forward_list_erase_after(other, i2)) {
            STL_Forward_list_insert_after(self, i2->next->value, i2->next->size, i1);
            i1 = i1->next;
        }
    }

}

void STL_Forward_list_reverse(STL_Forward_list *self)
{

    /* Initializing variables */
    auto STL_Forward_list_node *iter, *iter_2;
    auto STL_Forward_list other;
    STL_Forward_list_init(&other);

    /* Main part */
    for (iter = STL_Forward_list_begin(self); iter != STL_Forward_list_end(self); iter = iter->next) {
        STL_Forward_list_push_front(&other, iter->value, iter->size);
    }

    for (iter = STL_Forward_list_begin(self), iter_2 = STL_Forward_list_begin(&other);
         iter != STL_Forward_list_end(self);
         iter = iter->next, iter_2 = iter_2->next) {
        STL_Forward_list_swap_nodes(iter, iter_2);
    }

    STL_Forward_list_delete(&other);
}

void STL_Forward_list_sort(STL_Forward_list *l, size_t n, int (*cmp)(const void *, const void *))
{

    /* Initializing variables */

}

void STL_Forward_list_swap_nodes(STL_Forward_list_node *a, STL_Forward_list_node *b)
{

    /* Initializing variables */
    auto STL_Forward_list_node tmp;

    /* Main part */
    tmp.value = b->value;
    tmp.size = b->size;

    b->value = a->value;
    b->size = a->size;

    a->value = tmp.value;
    a->size = tmp.size;
}

void STL_Forward_list_swap(STL_Forward_list *self, STL_Forward_list *other)
{

    /* Initializing variables */
    auto STL_Forward_list tmp;

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

size_t STL_Forward_list_size_node(STL_Forward_list_node *node)
{

    /* Returning value */
    return node->size;
}