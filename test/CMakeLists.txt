add_executable(STL_Algorithm_test STL_Algorithm_test.c)
target_link_libraries(STL_Algorithm_test STL)
add_test(NAME STL_Algorithm_test COMMAND STL_Algorithm_test)

add_executable(STL_Stack_test STL_Stack_test.c)
target_link_libraries(STL_Stack_test STL)
add_test(NAME STL_Stack_test COMMAND STL_Stack_test)
