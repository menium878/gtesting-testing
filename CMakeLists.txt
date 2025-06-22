cmake_minimum_required(VERSION 3.14)
project(MyProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
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
file(GLOB_RECURSE LIB_SOURCES CONFIGURE_DEPENDS "src/*.cc")
# Remove main.cc if it's present
list(FILTER LIB_SOURCES EXCLUDE REGEX "src/main\\.cc$")
add_library(mylib ${LIB_SOURCES})
target_include_directories(mylib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
#target_include_directories(utils PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/utils)
#target_include_directories(core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/core)

# ---- Main program (optional, for future) ----
add_executable(main src/main.cc)
target_link_libraries(main PRIVATE mylib)

# ---- Tests ----
add_executable(tests
    tests/testing.cc
)

target_link_libraries(tests
    PRIVATE
    mylib
    gtest
    gtest_main
    pthread
)

add_test(NAME UnitTests COMMAND tests)

