cmake_minimum_required(VERSION 3.5)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake/")

find_package(SDL REQUIRED)
find_package(GLM REQUIRED)

include_directories(SDL_INCLUDE_DIR)
include_directories(GLM_INCLUDE_DIR)

set(SOURCE_FILES Source/drawing.cpp Source/SDLauxiliary.cpp Source/TestModel.cpp)

add_executable(main_solid_colour Source/main_solid_colour.cpp ${SOURCE_FILES})
add_executable(main_colour_wheel Source/main_colour_wheel.cpp ${SOURCE_FILES})
add_executable(main_starfield Source/main_starfield.cpp ${SOURCE_FILES})
add_executable(project_test Source/project_test.cpp ${SOURCE_FILES})

target_link_libraries(main_solid_colour ${SDL_LIBRARY})
target_link_libraries(main_colour_wheel ${SDL_LIBRARY})
target_link_libraries(main_starfield ${SDL_LIBRARY})
target_link_libraries(project_test ${SDL_LIBRARY})