cmake_minimum_required(VERSION 3.15)

project(Atomic VERSION 1.0.0)
set(PROJECT_STANDARD 14)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/StaticAnalyzers.cmake)
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/CompilerWarnings.cmake)
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/BuildTypeOptions.cmake)
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/Properties.cmake)

add_library(Atomic INTERFACE)
file(GLOB_RECURSE INCLUDE_HEADERS CONFIGURE_DEPENDS "${CMAKE_SOURCE_DIR}/include/*")
target_sources(Atomic INTERFACE ${INCLUDE_HEADERS})
target_include_directories(Atomic INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/include/")

include(tests/unit/CMakeLists.txt)