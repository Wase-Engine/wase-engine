cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(wase-engine LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CXX_EXTENSIONS OFF)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)

file(GLOB_RECURSE sources
    "src/*.h"
    "src/*.cpp"
    "src/*.inl"
    "assets/*.vert"
    "assets/*.frag"
)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Choose Release or Debug" FORCE)
endif()

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_definitions(-DWASE_DEBUG)
endif()

add_library(wase-engine ${sources})

target_include_directories(wase-engine PUBLIC 
    ${PROJECT_SOURCE_DIR}/src
    ${PROJECT_SOURCE_DIR}/vendor/stb_image
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
set(BUILD_GLFW3 ON)
add_subdirectory(${PROJECT_SOURCE_DIR}/vendor/glfw EXCLUDE_FROM_ALL)
target_link_libraries(wase-engine glfw)
target_include_directories(wase-engine PUBLIC ${PROJECT_SOURCE_DIR}/vendor/glfw/include)

# GLEW
add_definitions(-DGLEW_STATIC)
add_subdirectory(${PROJECT_SOURCE_DIR}/vendor/glew-cmake EXCLUDE_FROM_ALL)
target_link_libraries(wase-engine libglew_static)

# spdlog
add_subdirectory(${PROJECT_SOURCE_DIR}/vendor/spdlog EXCLUDE_FROM_ALL)
target_link_libraries(wase-engine spdlog)
target_include_directories(wase-engine PUBLIC ${PROJECT_SOURCE_DIR}/vendor/spdlog/include)

# GLM
add_subdirectory(${PROJECT_SOURCE_DIR}/vendor/glm EXCLUDE_FROM_ALL)
target_link_libraries(wase-engine glm)

# Wase ECS
add_subdirectory(${PROJECT_SOURCE_DIR}/vendor/wase-ecs EXCLUDE_FROM_ALL)
target_link_libraries(wase-engine wase-ecs)

# OpenAL
add_subdirectory(${PROJECT_SOURCE_DIR}/vendor/openal-soft EXCLUDE_FROM_ALL)
target_link_libraries(wase-engine OpenAL)

# Libsndfile
add_subdirectory(${PROJECT_SOURCE_DIR}/vendor/libsndfile EXCLUDE_FROM_ALL)
target_link_libraries(wase-engine sndfile)

# Box2D
set(BOX2D_BUILD_TESTBED OFF CACHE BOOL "Testing environment" FORCE)
set(BOX2D_BUILD_UNIT_TESTS OFF CACHE BOOL "Unit tests" FORCE)
add_subdirectory(${PROJECT_SOURCE_DIR}/vendor/box2d EXCLUDE_FROM_ALL)
target_link_libraries(wase-engine box2d)

# Tests
if(DEFINED enable_test)
  add_subdirectory(tests)
endif()