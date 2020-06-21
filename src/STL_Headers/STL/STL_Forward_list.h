#ifndef SRC_STL_FORWARD_LIST_H
#define SRC_STL_FORWARD_LIST_H

/* Include autoconf config.h */
#include "../STL_Config.h"

/* Header inclusion */
#if (HAVE_STDDEF_H == 1)
#include <stddef.h>
#endif

/* Include STL_Forward_list type definition */
#include "__internal/__STL_Forward_list_type.h"

/* STL_Forward_list errors */
enum STL_Forward_list_errors {
    STL_Forward_list_OK = 1,                /* Everything is OK. Not an error */
    STL_Forward_list_memory_error,          /* If STL_Forward_list routine can't allocate memory */
    STL_Forward_list_index_error,           /* If desired position is wrong */
    STL_Forward_list_null_reference_error   /* If (STL_Forward_list *) or (const void *elem) is NULL */
};

/* STL_Forward_list states */
enum STL_Forward_list_states {
    forward_list_not_empty = 0,
    forward_list_is_empty
};

/* STL_Forward_list methods */
/* Construction and destruction */
int STL_Forward_list_init(STL_Forward_list *list); /* Constructs the list. Returns STL_Forward_list_OK if OK */
int STL_Forward_list_init_cpy(STL_Forward_list *self, STL_Forward_list *other); /* Copies the list. Returns STL_Forward_list_OK if OK */
void STL_Forward_list_delete(STL_Forward_list *list); /* Destructs the list */

/* Element access */
void *STL_Forward_list_front(const STL_Forward_list *l); /* Accesses the first element */

/* Kinda iterators */
STL_Forward_list_node *STL_Forward_list_before_begin(STL_Forward_list *list); /* Returns STL_Forward_list->bp */
STL_Forward_list_node *STL_Forward_list_begin(STL_Forward_list *list); /* Returns STL_Forward_list->bp->next */
STL_Forward_list_node *STL_Forward_list_end(STL_Forward_list *list); /* Returns STL_Forward_list->lp */

/* Capacity */
int STL_Forward_list_empty(STL_Forward_list *list); /* Checks whether the container is empty */
size_t STL_Forward_list_size(STL_Forward_list *list); /* Returns the number of elements */

/* Modifiers */
void STL_Forward_list_clear(STL_Forward_list *list); /* Clears the contents */

int STL_Forward_list_insert_after(STL_Forward_list *list, const void *elem, size_t size, STL_Forward_list_node *pos); /* Inserts element of size "size" at address "elem" after "pos". Returns STL_Forward_list_OK if OK */
STL_Forward_list_node *STL_Forward_list_erase_after(STL_Forward_list *list, STL_Forward_list_node *pos); /* Removes element after "pos". Returns node after deleted element if OK */

int STL_Forward_list_push_front(STL_Forward_list *list, const void *elem, size_t size); /* Inserts element of size "size" at address "elem" at the first position. Returns STL_Forward_list_OK if OK */
STL_Forward_list_node *STL_Forward_list_pop_front(STL_Forward_list *list); /* Removes element at the first position. Returns node after deleted element if OK */

void STL_Forward_list_swap(STL_Forward_list *self, STL_Forward_list *other); /* Swaps the contents of two STL_Forward_lists */

/* Operations */
void STL_Forward_list_merge(STL_Forward_list *self, STL_Forward_list *other, int (*cmp)(const void *, const void *)); /* Merges two sorted lists into one. The lists should be sorted into ascending order */
void STL_Forward_list_reverse(STL_Forward_list *self); /* Reverses the order of elements */
void STL_Forward_list_sort(STL_Forward_list *list, size_t n, int (*cmp)(const void *, const void *)); /* Sorts the list */

/* Miscellaneous routines */
void STL_Forward_list_swap_nodes(STL_Forward_list_node *self_node, STL_Forward_list_node *other_node); /* Swaps the contents of two STL_Forward_list_nodes */
size_t STL_Forward_list_size_node(STL_Forward_list_node *node); /* Returns the size of the STL_Forward_list_node->elem */

#endif
