if(POLICY CMP0135)
    cmake_policy(SET CMP0135 NEW)
endif()

# gtest setup
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

get_target_property(sources main SOURCES)

list(TRANSFORM sources PREPEND "${PROJECT_SOURCE_DIR}/src/")

message("sources = ${sources}")

add_library(main_mockup STATIC ${sources})

add_executable(main_test test_util.cpp main_test.h)

target_link_libraries(main_test PRIVATE GTest::gtest_main main_mockup)
