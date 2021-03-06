cmake_minimum_required(VERSION 3.10)

project(Atomic VERSION 0.1.0)
set(PROJECT_STANDARD 14)

include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/CompilerWarnings.cmake)
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/BuildTypeOptions.cmake)
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/Properties.cmake)

add_library(Atomic INTERFACE)
target_sources(Atomic INTERFACE 
    ${CMAKE_SOURCE_DIR}/include/atomic/core/operating_system.hpp
    ${CMAKE_SOURCE_DIR}/include/atomic/core/standard.hpp
    ${CMAKE_SOURCE_DIR}/include/atomic/core/compiler.hpp
    ${CMAKE_SOURCE_DIR}/include/atomic/core/logging.hpp
    ${CMAKE_SOURCE_DIR}/include/atomic/core.hpp
    
    ${CMAKE_SOURCE_DIR}/include/atomic/linear-algebra/dynamic_matrix_engine.hpp
    ${CMAKE_SOURCE_DIR}/include/atomic/linear-algebra/dynamic_vector_engine.hpp
    ${CMAKE_SOURCE_DIR}/include/atomic/linear-algebra/fixed_matrix_engine.hpp
    ${CMAKE_SOURCE_DIR}/include/atomic/linear-algebra/fixed_vector_engine.hpp
    ${CMAKE_SOURCE_DIR}/include/atomic/linear-algebra/engine_properties.hpp 
    ${CMAKE_SOURCE_DIR}/include/atomic/linear-algebra/traits.hpp 
    ${CMAKE_SOURCE_DIR}/include/atomic/linear-algebra/forwarder.hpp 
    ${CMAKE_SOURCE_DIR}/include/atomic/linear-algebra/matrix_order.hpp
    ${CMAKE_SOURCE_DIR}/include/atomic/linear-algebra.hpp
     
    ${CMAKE_SOURCE_DIR}/include/atomic/math/constants.hpp
    ${CMAKE_SOURCE_DIR}/include/atomic/math/random.hpp
    ${CMAKE_SOURCE_DIR}/include/atomic/math/sequence.hpp
    ${CMAKE_SOURCE_DIR}/include/atomic/math/timer.hpp

    ${CMAKE_SOURCE_DIR}/include/atomic/physics/constants.hpp 

    ${CMAKE_SOURCE_DIR}/include/atomic/geometry/circle.hpp 
    ${CMAKE_SOURCE_DIR}/include/atomic/geometry/line_segment.hpp 
    ${CMAKE_SOURCE_DIR}/include/atomic/geometry/line.hpp 
    ${CMAKE_SOURCE_DIR}/include/atomic/geometry/ray.hpp 
    ${CMAKE_SOURCE_DIR}/include/atomic/geometry/triangle.hpp  
    ${CMAKE_SOURCE_DIR}/include/atomic/geometry/forwarder.hpp 

    ${CMAKE_SOURCE_DIR}/include/atomic/container/dynamic_stack.hpp
    ${CMAKE_SOURCE_DIR}/include/atomic/container/fixed_stack.hpp
)

target_include_directories(Atomic INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include/)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/)

include(tests/CMakeLists.txt)
include(example/CMakeLists.txt)