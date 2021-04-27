add_executable(Tests ${CMAKE_CURRENT_SOURCE_DIR}/tests/main.cpp)

target_sources(Tests PRIVATE
	
	${CMAKE_CURRENT_SOURCE_DIR}/tests/linear-algebra/is_engine.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/tests/linear-algebra/is_scalar_element.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/tests/linear-algebra/vector/fixed_vector_addition.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/tests/linear-algebra/vector/fixed_vector_subtraction.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/tests/linear-algebra/vector/fixed_vector_multiplication.cpp
)

target_include_directories(Tests INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/tests/)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/tests/)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/external/)

SetProjectWarnings(Tests)
SetBuildTypeOptions(Tests)
SetProjectProperties(Tests ${PROJECT_STANDARD})