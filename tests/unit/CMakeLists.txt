add_executable(Tests ${CMAKE_CURRENT_SOURCE_DIR}/tests/unit/main.cpp)

target_sources(Tests PRIVATE
	
	${CMAKE_CURRENT_SOURCE_DIR}/tests/unit/linear-algebra/is_engine.test.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/tests/unit/linear-algebra/is_scalar_element.test.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/tests/unit/linear-algebra/fixed_vector_addition.test.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/tests/unit/linear-algebra/fixed_vector_subtraction.test.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/tests/unit/linear-algebra/fixed_vector_multiplication.test.cpp
)

target_include_directories(Tests INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/tests/unit/)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/tests/)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/external/)

SetProjectWarnings(Tests)
SetBuildTypeOptions(Tests)
SetProjectProperties(Tests ${PROJECT_STANDARD})