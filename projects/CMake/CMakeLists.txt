cmake_minimum_required(VERSION 3.11) # FetchContent is available in 3.11+
project(raylib-cpp-example)

# raylib
find_package(raylib 3.0.0 QUIET)
if (NOT raylib_FOUND)
  include(FetchContent)
  FetchContent_Declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    GIT_TAG 7ef114d1da2c34a70bba5442497103441647d8f3
  )
  FetchContent_GetProperties(raylib)
  if (NOT raylib_POPULATED) # Have we downloaded raylib yet?
    set(FETCHCONTENT_QUIET NO)
    FetchContent_Populate(raylib)
    set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
    set(BUILD_GAMES    OFF CACHE BOOL "" FORCE)
    set(BUILD_TESTING  OFF CACHE BOOL "" FORCE)
    add_subdirectory(${raylib_SOURCE_DIR} ${raylib_BINARY_DIR})
  endif()
endif()

# raylib-cpp
find_package(raylib-cpp 0.3.0 QUIET)
if (NOT raylib-cpp_FOUND)
  include(FetchContent)
  FetchContent_Declare(
    raylib-cpp
    GIT_REPOSITORY https://github.com/RobLoach/raylib-cpp.git
    GIT_TAG a6117d25e8a2102cfeee966e7c59f2d65479d042
  )
  FetchContent_GetProperties(raylib-cpp)
  if (NOT raylib-cpp_POPULATED) # Have we downloaded raylib yet?
    set(FETCHCONTENT_QUIET NO)
    FetchContent_Populate(raylib-cpp)
    set(BUILD_RAYLIB_CPP_STATIC   OFF CACHE BOOL "" FORCE)
    set(BUILD_RAYLIB_CPP_EXAMPLES OFF CACHE BOOL "" FORCE)
    set(BUILD_TESTING             OFF CACHE BOOL "" FORCE)
    add_subdirectory(${raylib-cpp_SOURCE_DIR} ${raylib-cpp_BINARY_DIR})
  endif()
endif()

# This is the main part:
set(PROJECT_NAME raylib-cpp-example)
set(PROJECT_SOURCES main.cpp)
add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})
set(raylib_VERBOSE 1)
target_link_libraries(${PROJECT_NAME} PUBLIC raylib raylib-cpp)

# That's it! You should have an example executable that you can run. Have fun!
