cmake_minimum_required (VERSION 2.8.11)
project(ctrl_types)

include(FindPkgConfig)
add_compile_options(-std=c++11)

set(PROJECT_VERSION 0.1)
set(API_VERSION ${PROJECT_VERSION})

include_directories(${PROJECT_SOURCE_DIR}/src)

add_subdirectory(src)
