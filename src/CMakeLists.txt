cmake_minimum_required(VERSION 3.15)
project(src C)

set(CMAKE_C_STANDARD 90)

set(STL_List STL_Containers/STL_List/STL_List.c STL_Headers/STL/STL_List.h STL_Headers/STL/__internal/__STL_List_type.h)
set(STL_Queue STL_Containers/STL_Queue/STL_Queue.c STL_Headers/STL/STL_Queue.h)
set(STL_Algorithm STL_Algorithm/STL_Algorithm_sorting.c STL_Algorithm/STL_Algorithm_advanced_sorting.c STL_Algorithm/STL_Algorithm_other.c STL_Algorithm/STL_Algorithm_compare.c STL_Headers/STL/STL_Algorithm.h)
set(STL_Stack STL_Containers/STL_Stack/STL_Stack.c STL_Headers/STL/STL_Stack.h)
set(STL_Vector STL_Containers/STL_Vector/STL_Vector.c STL_Headers/STL/STL_Vector.h)
set(STL_Forward_list STL_Containers/STL_Forward_list/STL_Forward_list.c STL_Headers/STL/__internal/__STL_Forward_list_type.h)
set(STL_Unordered_map STL_Containers/STL_Unordered_map/STL_Unordered_map.c STL_Headers/STL/STL_Unordered_map.h STL_Headers/STL/__internal/__STL_Unordered_multimap.h)
set(STL_String STL_Containers/STL_String/STL_String.c STL_Headers/STL/STL_String.h STL_Headers/STL/__internal/__STL_Basic_string.h)

add_library(STL STL_Headers/STL.h STL_Headers/STL_Config.h ${STL_List} ${STL_Queue} ${STL_Algorithm} ${STL_Stack} ${STL_Vector}
        ${STL_Forward_list} ${STL_Unordered_map} ${STL_String})

#add_executable(main STL_Algorithm/STL_Algorithm_test.c)
add_executable(main main.c)
target_link_libraries(main STL)