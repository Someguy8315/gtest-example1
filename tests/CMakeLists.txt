# gtest setup
include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG f8d7d77c06936315286eb55f8de22cd23c188571 # v1.14
)

if(WIN32)
    # For Windows: Prevent overriding the parent project's compiler/linker settings
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
endif()

FetchContent_MakeAvailable(googletest)

get_target_property(sources main SOURCES)

message("sources = ${sources}")

add_library(main_mockup STATIC ${sources})

add_executable(main_test test_util.cpp main_test.h)

target_link_libraries(main_test PRIVATE GTest::gtest_main main_mockup)
