cmake_minimum_required(VERSION 3.17)

project(wase-engine)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_mixer REQUIRED)
find_package(SDL2_ttf REQUIRED)

include_directories(${SDL2_INCLUDE_DIR}
        ${SDL2_IMAGE_INCLUDE_DIR}
        ${SDL2_MIXER_INCLUDE_DIR}
        ${SDL2_TTF_INCLUDE_DIR})

add_library(wase-engine
    src/wase/core/engine.h
    src/wase/core/engine.cpp
    src/wase/core/renderer.h
    src/wase/core/renderer.cpp
    src/wase/core/window.h
    src/wase/core/window.cpp
    src/wase/core/input.h
    src/wase/core/input.cpp
    src/wase/core/terminate_exception.h
    src/wase/core/events.h
    src/wase/core/events.cpp
    src/wase/core/scene.h
    src/wase/core/scene.cpp
    src/wase/core/timer.h
    src/wase/core/timer.cpp
    src/wase/core/draw.h
    src/wase/core/draw.cpp
    src/wase/core/vector2.h
    src/wase/core/size.h
    src/wase/core/utils/log_utils.h
    src/wase/core/utils/log_utils.cpp
    src/wase/core/managers/scene_manager.h
    src/wase/core/managers/scene_manager.cpp
    src/wase/core/managers/resource_manager.h
    src/wase/core/managers/resource_manager.cpp
    src/wase/ecs/component.h
    src/wase/ecs/component.cpp
    src/wase/ecs/entity.h
    src/wase/ecs/entity.cpp
    src/wase/ecs/camera.h
    src/wase/ecs/entity_manager.h
    src/wase/ecs/entity_manager.cpp
    src/wase/ecs/components/transform.h
    src/wase/ecs/components/sprite_renderer.h
    src/wase/ecs/components/sprite_renderer.cpp
    src/wase/ecs/components/audio_source.h
    src/wase/ecs/components/audio_source.cpp
    src/wase/ecs/components/animator.h
    src/wase/ecs/components/animator.cpp
    src/wase/ecs/components/colliders/collider.h
    src/wase/ecs/components/colliders/collider.cpp
    src/wase/ecs/components/colliders/box_collider_2d.h
    src/wase/ecs/components/colliders/box_collider_2d.cpp
    src/wase/ecs/components/ui/label.h
    src/wase/ecs/components/ui/label.cpp
    src/wase/ecs/components/ui/button.h
    src/wase/ecs/components/ui/button.cpp
)

# Group the core files
source_group(core FILES
    src/wase/core/engine.h
    src/wase/core/engine.cpp
    src/wase/core/renderer.h
    src/wase/core/renderer.cpp
    src/wase/core/window.h
    src/wase/core/window.cpp
    src/wase/core/input.h
    src/wase/core/input.cpp
    src/wase/core/terminate_exception.h
    src/wase/core/events.h
    src/wase/core/events.cpp
    src/wase/core/scene.h
    src/wase/core/scene.cpp
    src/wase/core/timer.h
    src/wase/core/timer.cpp
    src/wase/core/draw.h
    src/wase/core/draw.cpp
    src/wase/core/vector2.h
    src/wase/core/size.h
    src/wase/core/managers/scene_manager.h
    src/wase/core/managers/scene_manager.cpp
    src/wase/core/managers/resource_manager.h
    src/wase/core/managers/resource_manager.cpp
)

source_group(core/utils FILES
    src/wase/core/utils/log_utils.h
    src/wase/core/utils/log_utils.cpp
)

# Group the ecs files
source_group(ecs FILES
    src/wase/ecs/component.h
    src/wase/ecs/component.cpp
    src/wase/ecs/entity.h
    src/wase/ecs/entity.cpp
    src/wase/ecs/camera.h
    src/wase/entity_manager.h
    src/wase/ecs/entity_manager.cpp
)

source_group(ecs/components FILES
    src/wase/ecs/components/transform.h
    src/wase/ecs/components/sprite_renderer.h
    src/wase/ecs/components/sprite_renderer.cpp
    src/wase/ecs/components/audio_source.h
    src/wase/ecs/components/audio_source.cpp
    src/wase/ecs/components/animator.h
    src/wase/ecs/components/animator.cpp
    src/wase/ecs/components/colliders/collider.h
    src/wase/ecs/components/colliders/collider.cpp
    src/wase/ecs/components/colliders/box_collider_2d.h
    src/wase/ecs/components/colliders/box_collider_2d.cpp
    src/wase/ecs/components/ui/label.h
    src/wase/ecs/components/ui/label.cpp
    src/wase/ecs/components/ui/button.h
    src/wase/ecs/components/ui/button.cpp
)

target_link_libraries(wase-engine ${SDL2_LIBRARY}
        ${SDL2_IMAGE_LIBRARIES}
        ${SDL2_MIXER_LIBRARIES}
        ${SDL2_TTF_LIBRARIES})

if(MINGW)
    target_link_libraries(wase-engine mingw32)
endif(MINGW)

file(COPY src/ DESTINATION ${CMAKE_BINARY_DIR}/include)

if(DEFINED enable_test)
  include(FetchContent)
  FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
  )
  # For Windows: Prevent overriding the parent project's compiler/linker settings
  set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
  FetchContent_MakeAvailable(googletest)

  enable_testing()

  add_executable(
    main_test
    test/main_test.cpp
    test/component_test.cpp
    test/entity_test.cpp
  )
  target_link_libraries(
    main_test
    wase-engine
    gtest_main
  )

  include(GoogleTest)
  gtest_discover_tests(main_test)

  #add_custom_command(TARGET main_test
  #                  POST_BUILD
  #                  COMMAND ctest -C $<CONFIGURATION> --output-on-failure)
endif()