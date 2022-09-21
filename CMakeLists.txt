cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(wase-engine LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CXX_EXTENSIONS OFF)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)

file(GLOB_RECURSE sources
    "src/*.h"
    "src/*.cpp"
)

add_library(wase-engine ${sources})

target_include_directories(wase-engine PUBLIC 
    ${PROJECT_SOURCE_DIR}/src
)

foreach(source IN LISTS sources)
    get_filename_component(source_path "${source}" PATH ABSOLUTE)

    file(RELATIVE_PATH
        item_path_rel
        ${PROJECT_SOURCE_DIR}
        ${source_path})

    source_group("${item_path_rel}" FILES "${source}")
endforeach()

# OpenGL
find_package(OpenGL REQUIRED)

# GLFW
add_subdirectory(${PROJECT_SOURCE_DIR}/vendor/glfw EXCLUDE_FROM_ALL)
target_link_libraries(wase-engine glfw)
target_include_directories(wase-engine PUBLIC ${PROJECT_SOURCE_DIR}/vendor/glfw/include)

# GLEW
add_definitions(-DGLEW_STATIC)
add_subdirectory(${PROJECT_SOURCE_DIR}/vendor/glew-cmake EXCLUDE_FROM_ALL)
target_link_libraries(wase-engine libglew_static)

# Tests
if(DEFINED enable_test)
  add_subdirectory(tests)
endif()