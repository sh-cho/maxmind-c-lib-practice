cmake_minimum_required(VERSION 3.24)
project(maxmind_c_lib_practice)

set(CMAKE_CXX_STANDARD 17)

## External Libraries
include(FetchContent)

FetchContent_Declare(
        maxminddb
        GIT_REPOSITORY "https://github.com/maxmind/libmaxminddb"
        GIT_TAG "1.7.1"
)
FetchContent_MakeAvailable(maxminddb)

# Ref: https://google.github.io/googletest/quickstart-cmake.html
FetchContent_Declare(
        googletest
        GIT_REPOSITORY "https://github.com/google/googletest"
        GIT_TAG "main"
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(maxmind_c_lib_practice main.cc geo_ip_loader.cc)
target_link_libraries(maxmind_c_lib_practice maxminddb)

## gtest
enable_testing()
add_executable(
        main_test
        main_test.cc
        geo_ip_loader.cc
)
target_link_libraries(main_test
        GTest::gtest_main
        maxminddb
)
include(GoogleTest)
gtest_discover_tests(main_test)
