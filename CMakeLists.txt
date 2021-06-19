cmake_minimum_required(VERSION 3.17)

set(CMAKE_GENERATOR_PLATFORM win32)

project(sdl-game-engine)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib/x86)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_mixer REQUIRED)
find_package(SDL2_ttf REQUIRED)

include_directories(${SDL2_INCLUDE_DIR}
        ${SDL2_IMAGE_INCLUDE_DIR}
        ${SDL2_MIXER_INCLUDE_DIR}
        ${SDL2_TTF_INCLUDE_DIR})

add_library(sdl-game-engine
    src/sge/core/engine.h
    src/sge/core/engine.cpp
    src/sge/core/renderer.h
    src/sge/core/renderer.cpp
    src/sge/core/window.h
    src/sge/core/window.cpp
    src/sge/core/input.h
    src/sge/core/input.cpp
    src/sge/core/events.h
    src/sge/core/events.cpp
    src/sge/core/scene.h
    src/sge/core/scene.cpp
    src/sge/core/timer.h
    src/sge/core/timer.cpp
    src/sge/core/draw.h
    src/sge/core/draw.cpp
    src/sge/core/vector2.h
    src/sge/core/utils/log_utils.h
    src/sge/core/utils/log_utils.cpp
    src/sge/core/managers/scene_manager.h
    src/sge/core/managers/scene_manager.cpp
    src/sge/core/managers/resource_manager.h
    src/sge/core/managers/resource_manager.cpp
    src/sge/ecs/component.h
    src/sge/ecs/component.cpp
    src/sge/ecs/entity.h
    src/sge/ecs/entity.cpp
    src/sge/ecs/entity_manager.h
    src/sge/ecs/entity_manager.cpp
    src/sge/ecs/components/transform.h
    src/sge/ecs/components/sprite_renderer.h
    src/sge/ecs/components/audio_source.h
    src/sge/ecs/components/colliders/collider.h
    src/sge/ecs/components/colliders/collider.cpp
    src/sge/ecs/components/colliders/box_collider_2d.h
    src/sge/ecs/components/colliders/box_collider_2d.cpp
    src/sge/ecs/components/ui/label.h
    src/sge/ecs/components/ui/label.cpp
)

# Group the core files
source_group(core FILES
    src/sge/core/engine.h
    src/sge/core/engine.cpp
    src/sge/core/renderer.h
    src/sge/core/renderer.cpp
    src/sge/core/window.h
    src/sge/core/window.cpp
    src/sge/core/input.h
    src/sge/core/input.cpp
    src/sge/core/events.h
    src/sge/core/events.cpp
    src/sge/core/scene.h
    src/sge/core/scene.cpp
    src/sge/core/timer.h
    src/sge/core/timer.cpp
    src/sge/core/draw.h
    src/sge/core/draw.cpp
    src/sge/core/vector2.h
    src/sge/core/managers/scene_manager.h
    src/sge/core/managers/scene_manager.cpp
    src/sge/core/managers/resource_manager.h
    src/sge/core/managers/resource_manager.cpp
)

source_group(core/utils FILES
    src/sge/core/utils/log_utils.h
    src/sge/core/utils/log_utils.cpp
)

# Group the ecs files
source_group(ecs FILES
    src/sge/ecs/component.h
    src/sge/ecs/component.cpp
    src/sge/ecs/entity.h
    src/sge/ecs/entity.cpp
    src/sge/entity_manager.h
    src/sge/ecs/entity_manager.cpp
)

source_group(ecs/components FILES
    src/sge/ecs/components/transform.h
    src/sge/ecs/components/sprite_renderer.h
    src/sge/ecs/components/audio_source.h
    src/sge/ecs/components/colliders/collider.h
    src/sge/ecs/components/colliders/collider.cpp
    src/sge/ecs/components/colliders/box_collider_2d.h
    src/sge/ecs/components/colliders/box_collider_2d.cpp
    src/sge/ecs/components/ui/label.h
    src/sge/ecs/components/ui/label.cpp
)

target_link_libraries(sdl-game-engine ${SDL2_LIBRARY}
        ${SDL2_IMAGE_LIBRARIES}
        ${SDL2_MIXER_LIBRARIES}
        ${SDL2_TTF_LIBRARIES})

file(COPY src/ DESTINATION ${CMAKE_BINARY_DIR}/include)