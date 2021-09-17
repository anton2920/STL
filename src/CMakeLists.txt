add_subdirectory(STL_Algorithm)
add_subdirectory(STL_Containers)

add_library(STL SHARED STL_Headers/STL.h
            $<TARGET_OBJECTS:STL_Forward_list>
            $<TARGET_OBJECTS:STL_List>
            $<TARGET_OBJECTS:STL_Queue>
            $<TARGET_OBJECTS:STL_Stack>
            $<TARGET_OBJECTS:STL_String>
            $<TARGET_OBJECTS:STL_Vector>
            $<TARGET_OBJECTS:STL_Algorithm>)

install(TARGETS STL DESTINATION ${CMAKE_INSTALL_LIBDIR})
install(DIRECTORY STL_Headers/STL DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
