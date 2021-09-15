add_library(STL_Stack STATIC
            STL_Stack.c
            ../../STL_Headers/STL/STL_Stack.h
            ../../STL_Headers/STL/__internal/__STL_List_type.h)
target_link_libraries(STL_Stack STL_List)
