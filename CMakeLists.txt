cmake_minimum_required(VERSION 3.5)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake/")

find_package(SDL REQUIRED)
find_package(GLM REQUIRED)

include_directories(SDL_INCLUDE_DIR)
include_directories(GLM_INCLUDE_DIR)

add_executable(assignment_01 Source/assignment_01.cpp Source/drawing.cpp Source/SDLauxiliary.cpp Source/TestModel.cpp)
add_executable(assignment_01_test Source/assignment_01_test.cpp Source/drawing.cpp Source/SDLauxiliary.cpp Source/TestModel.cpp)

target_link_libraries(assignment_01 ${SDL_LIBRARY})
target_link_libraries(assignment_01_test ${SDL_LIBRARY})