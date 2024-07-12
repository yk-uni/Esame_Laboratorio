cmake_minimum_required(VERSION 3.27)
project(Esame_Laboratorio)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(Test)
set(SOURCE_FILES ShoppingList.cpp ShoppingList.h Observer.h Subject.h Item.h Item.cpp)

add_executable(Esame_Laboratorio main.cpp)

add_library(core ${SOURCE_FILES})
target_link_libraries(Esame_Laboratorio core)