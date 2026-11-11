cmake_minimum_required(VERSION 3.24)
project(string_practice LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_COLOR_DIAGNOSTICS ON)

set(CMAKE_CXX_FLAGS_ASAN "-g -fsanitize=address,undefined -fno-sanitize-recover=all"
  CACHE STRING "Compiler flags in asan build"
  FORCE)

find_package(GTest QUIET)
if(NOT GTest_FOUND)
    include(FetchContent)
    FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.17.0.zip
        DOWNLOAD_EXTRACT_TIMESTAMP TRUE
    )
    set(BUILD_GMOCK OFF CACHE BOOL "Build GoogleMock" FORCE)
    set(gtest_force_shared_crt ON CACHE BOOL "Use the shared MSVC runtime" FORCE)
    FetchContent_MakeAvailable(googletest)
endif()

add_executable(test_string tests/test.cpp src/string.cpp string.hpp)
target_include_directories(test_string PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_link_libraries(test_string PRIVATE GTest::gtest_main)

enable_testing()
include(GoogleTest)
gtest_discover_tests(test_string)

add_executable(play_string play/main.cpp src/string.cpp string.hpp)
target_include_directories(play_string PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
