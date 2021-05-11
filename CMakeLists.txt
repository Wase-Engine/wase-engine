cmake_minimum_required(VERSION 3.17)

set(CMAKE_GENERATOR_PLATFORM win32)

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
    core/engine.h
    core/engine.cpp
    core/renderer.h
    core/renderer.cpp
    core/window.h
    core/window.cpp
    core/input.h
    core/input.cpp
    core/scene.h
    core/scene.cpp
    core/scene_manager.h
    core/scene_manager.cpp
    core/timer.h
    core/timer.cpp
    core/utils/log_utils.h
    core/utils/log_utils.cpp
    ecs/component.h
    ecs/component.cpp
    ecs/entity.h
    ecs/entity.cpp
    ecs/entity_manager.h
    ecs/entity_manager.cpp
    ecs/components/transform.h
    ecs/components/sprite_renderer.h
    ecs/components/audio_source.h
    example-game/main.cpp
    example-game/scenes/example_scene.h
    example-game/scenes/example_scene.cpp
)

# Group the core files
source_group(core FILES
    core/engine.h
    core/engine.cpp
    core/renderer.h
    core/renderer.cpp
    core/window.h
    core/window.cpp
    core/input.h
    core/input.cpp
    core/scene.h
    core/scene.cpp
    core/scene_manager.h
    core/scene_manager.cpp
    core/timer.h
    core/timer.cpp
)

source_group(core/utils FILES
    core/utils/log_utils.h
    core/utils/log_utils.cpp
)

# Group the ecs files
source_group(ecs FILES
    ecs/component.h
    ecs/component.cpp
    ecs/entity.h
    ecs/entity.cpp
    ecs/entity_manager.h
    ecs/entity_manager.cpp
)

source_group(ecs/components FILES
    ecs/components/transform.h
    ecs/components/sprite_renderer.h
    ecs/components/audio_source.h
)

# Group the example-game files
source_group(example-game FILES
    example-game/main.cpp
)

source_group(example-game/scenes FILES 
    example-game/scenes/example_scene.h
    example-game/scenes/example_scene.cpp
)

# Copy the assets folder from the example-game
install(DIRECTORY DESTINATION ${CMAKE_BINARY_DIR}/example-game)
file(COPY example-game/assets DESTINATION ${CMAKE_BINARY_DIR}/example-game)

target_link_libraries(sdl-game-engine ${SDL2_LIBRARY}
        ${SDL2_IMAGE_LIBRARIES}
        ${SDL2_MIXER_LIBRARIES})