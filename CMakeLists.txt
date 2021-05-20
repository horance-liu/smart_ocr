cmake_minimum_required(VERSION 3.2 FATAL_ERROR)

project(smart_ocr VERSION 1.0 LANGUAGES C CXX)

option(BUILD_TEST      "Set to ON to build tests"              ON)
option(BUILD_EXAMPLE   "Set to ON to build examples"           ON)

# Set c++ standard to c++14.
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
message(STATUS "C++14 support has been enabled by default.")

# smart_ocr target
file(GLOB_RECURSE smart_ocr_srcs CONFIGURE_DEPENDS
    src/*.cpp
    src/*.cc
    src/*.c
)

add_library(smart_ocr ${smart_ocr_srcs})

target_include_directories(smart_ocr
    PUBLIC  include
    PRIVATE src
)

if(BUILD_EXAMPLE)
    add_subdirectory(example)
endif(BUILD_EXAMPLE)

if(BUILD_TEST)
    enable_testing()
    add_subdirectory(test)
endif(BUILD_TEST)