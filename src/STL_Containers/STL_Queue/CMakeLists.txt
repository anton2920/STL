add_library(STL_Queue STATIC
            STL_Queue.c
            ../../STL_Headers/STL/STL_Queue.h
            ../../STL_Headers/STL/__internal/__STL_List_type.h)
target_link_libraries(STL_Queue STL_List)
