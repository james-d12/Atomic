#file(GLOB files "example/atomic/linear-algebra/*.cpp")
#foreach(file ${files})
#    string(REPLACE "example/atomic/linear-algebra")
#    message(${file})
#endforeach()

set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Examples)

add_executable(matrix_engine_arithmetic example/atomic/linear-algebra/matrix_engine_arithmetic.example.cpp)
add_executable(vector_engine_arithmetic example/atomic/linear-algebra/vector_engine_arithmetic.example.cpp)
add_executable(vector_print example/atomic/linear-algebra/vector_print.example.cpp)
add_executable(vector example/atomic/linear-algebra/vector.example.cpp)
add_executable(fixed_stack_la example/atomic/container/fixed_stack_la.example.cpp)
