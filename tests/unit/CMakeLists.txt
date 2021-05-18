Include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v2.13.1)

FetchContent_MakeAvailable(Catch2)

add_executable(Tests ${CMAKE_CURRENT_SOURCE_DIR}/tests/unit/unit_main.cpp)
target_link_libraries(Tests PRIVATE Catch2::Catch2)
target_sources(Tests PRIVATE
	${CMAKE_CURRENT_LIST_DIR}/linear-algebra/traits/element_promotion.test.cpp
	${CMAKE_CURRENT_LIST_DIR}/linear-algebra/traits/is_engine.test.cpp
	${CMAKE_CURRENT_LIST_DIR}/linear-algebra/traits/is_scalar_element.test.cpp

	${CMAKE_CURRENT_LIST_DIR}/linear-algebra/vector/fixed_vector_addition.test.cpp
	${CMAKE_CURRENT_LIST_DIR}/linear-algebra/vector/fixed_vector_math.test.cpp
	${CMAKE_CURRENT_LIST_DIR}/linear-algebra/vector/fixed_vector_subtraction.test.cpp
	${CMAKE_CURRENT_LIST_DIR}/linear-algebra/vector/fixed_vector_multiplication.test.cpp
	${CMAKE_CURRENT_LIST_DIR}/linear-algebra/vector/dynamic_vector_addition.test.cpp
	${CMAKE_CURRENT_LIST_DIR}/linear-algebra/vector/dynamic_vector_subtraction.test.cpp
	${CMAKE_CURRENT_LIST_DIR}/linear-algebra/vector/dynamic_vector_multiplication.test.cpp
	${CMAKE_CURRENT_LIST_DIR}/linear-algebra/quarternion/quarternion_addition.test.cpp
)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/tests/)

SetProjectWarnings(Tests)
SetBuildTypeOptions(Tests)
SetProjectProperties(Tests ${PROJECT_STANDARD})