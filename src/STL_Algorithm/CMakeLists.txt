add_library(STL_Algorithm OBJECT
            STL_Algorithm_advanced_sorting.c
            STL_Algorithm_compare.c
            STL_Algorithm_other.c
            STL_Algorithm_sorting.c
            ../STL_Headers/STL/STL_Algorithm.h)
target_link_libraries(STL_Algorithm m)
