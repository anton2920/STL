cmake_minimum_required(VERSION 3.15)
project(src C)

set(CMAKE_C_STANDARD 90)

set(STL_List STL_List/STL_List.c STL_Headers/STL/STL_List.h)
set(STL_Queue STL_Queue/STL_Queue.c STL_Headers/STL/STL_Queue.h)
set(STL_Algorithm STL_Algorithm/STL_Algorithm_sorting.c STL_Algorithm/STL_Algorithm_advanced_sorting.c STL_Algorithm/STL_Algorithm_other.c STL_Algorithm/STL_Algorithm_compare.c STL_Headers/STL/STL_Algorithm.h)
set(STL_Stack STL_Stack/STL_Stack.c STL_Headers/STL/STL_Stack.h)

add_library(STL STL_Headers/STL.h STL_Headers/STL_Config.h ${STL_List} ${STL_Queue} ${STL_Algorithm} ${STL_Stack})