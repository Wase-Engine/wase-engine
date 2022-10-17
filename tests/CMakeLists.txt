include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
IF(WIN32)
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
ENDIF()
FetchContent_MakeAvailable(googletest)

enable_testing()

file(GLOB_RECURSE sources
    "*.cpp"
)

foreach(source IN LISTS sources)
    get_filename_component(source_path "${source}" PATH ABSOLUTE)

    file(RELATIVE_PATH
        item_path_rel
        ${PROJECT_SOURCE_DIR}
        ${source_path})

    source_group("${item_path_rel}" FILES "${source}")
endforeach()

add_executable(wase-engine-tests ${sources})

target_link_libraries(
    wase-engine-tests
    wase-engine
    GTest::gtest_main
    gmock
)

include(GoogleTest)

gtest_discover_tests(wase-engine-tests)