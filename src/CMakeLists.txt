add_subdirectory(STL_Algorithm)
add_subdirectory(STL_Containers)

add_library(STL SHARED null.c STL_Headers/STL.h)
target_link_libraries(STL STL_Containers)
target_link_libraries(STL STL_Algorithm)

install(TARGETS STL DESTINATION ${CMAKE_INSTALL_LIBDIR})
install(DIRECTORY STL_Headers/STL DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
