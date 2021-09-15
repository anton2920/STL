#include <stdio.h>
#include <stdlib.h>

#include "../src/STL_Headers/STL/STL_Stack.h"

main() {

    /* Initializing variables */
    STL_Stack a;
    STL_Stack_init(&a);
    int *iter;
    int i;

    /* Main part */
    for (i = 0; i < 10; ++i) {
        STL_Stack_push(&a, &i, sizeof(int));
    }

    while (!STL_Stack_empty(&a)) {
        i = *((int *) STL_Stack_top(&a));
        printf("%d ", i);
        STL_Stack_pop(&a);
    }

    STL_Stack_delete(&a);

    /* Returning value */
    return 0;
}