cmake_minimum_required(VERSION 3.5)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake/")

find_package(SDL REQUIRED)
find_package(GLM REQUIRED)

include_directories(SDL_INCLUDE_DIR)
include_directories(GLM_INCLUDE_DIR)

add_executable(skeleton Source/skeleton.cpp)
target_link_libraries(skeleton ${SDL_LIBRARY})