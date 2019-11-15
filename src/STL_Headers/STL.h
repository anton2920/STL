#ifndef SRC_STL_H
#define SRC_STL_H

/* Include autoconf config.h */
#include "STL_Config.h"

/* Headers that provide access to STL containers and container adaptors */
/* Sequence containers implement data structures which can be accessed sequentially */
#include "STL/STL_List.h" /* doubly-linked list */

/* Container adaptors provide a different interface for sequential containers */
#include "STL/STL_Stack.h" /* adapts a container to provide stack (LIFO data structure) */
#include "STL/STL_Queue.h" /* adapts a container to provide queue (FIFO data structure) */

/* Headers that provide access to STL algorithms */
#include "STL/STL_Algorithm.h"

#endif
