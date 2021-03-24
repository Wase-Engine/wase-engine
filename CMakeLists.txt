cmake_minimum_required(VERSION 3.17)
project(sdl-game-engine)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_mixer REQUIRED)

include_directories(${SDL2_INCLUDE_DIR}
        ${SDL2_IMAGE_INCLUDE_DIR}
        ${SDL2_MIXER_INCLUDE_DIR})

add_executable(sdl-game-engine
    main.cpp
)

target_link_libraries(sdl-game-engine ${SDL2_LIBRARY}
        ${SDL2_IMAGE_LIBRARIES}
        ${SDL2_MIXER_LIBRARIES})