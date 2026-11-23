cmake_minimum_required(VERSION 3.16..3.24)

# Name the project. This also sets the variable PROJECT_NAME
project(no_strings_attached VERSION 0.0.1
                            DESCRIPTION "A small string processing library"
                            LANGUAGES CXX)

# If nobody chose a build type, build optimised (Release) code
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release CACHE STRING "" FORCE)
endif()

# A "settings bundle": compiles nothing, it only carries settings.
# Anything that links to it inherits these settings.
add_library(cxx_setup INTERFACE)
target_compile_options(cxx_setup INTERFACE -Wall -Wpedantic -Wextra)  # warnings on
target_compile_features(cxx_setup INTERFACE cxx_std_17)               # use C++17
target_include_directories(cxx_setup INTERFACE ${PROJECT_SOURCE_DIR}) # #include paths start from this folder

include(cmake/UpdateSubmodules.cmake)
include(CTest)

add_subdirectory(external)
add_subdirectory(${PROJECT_NAME})   # the inner no_strings_attached/ folder
add_subdirectory(examples)