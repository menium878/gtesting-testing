cmake_minimum_required(VERSION 3.14)
project(MyProject)

set(CMAKE_CXX_STANDARD 17)

# Enable testing
enable_testing()

# Include FetchContent for GoogleTest
include(FetchContent)

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/main.zip
)

# Prevent GTest from overriding compiler settings on Windows (safe on Linux)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

# ---- Library (utils) ----
file(GLOB UTILS_SOURCES "src/utils/*.cc")
add_library(utils ${UTILS_SOURCES})
target_include_directories(utils PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/utils)

# ---- Main program (optional, for future) ----
add_executable(main src/main.cc)
target_link_libraries(main PRIVATE utils)

# ---- Tests ----
add_executable(tests
    tests/testing.cc
)

target_link_libraries(tests
    PRIVATE
    utils
    gtest
    gtest_main
    pthread
)

add_test(NAME UnitTests COMMAND tests)

