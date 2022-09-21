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

add_executable(wase-engine-tests ${sources})

target_link_libraries(
    wase-engine-tests
    wase-engine
    GTest::gtest_main
)

include(GoogleTest)

gtest_discover_tests(wase-engine-tests)