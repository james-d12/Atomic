Include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v2.13.1)

FetchContent_MakeAvailable(Catch2)

add_executable(Tests ${CMAKE_CURRENT_SOURCE_DIR}/tests/unit/unit_main.cpp)
file(GLOB_RECURSE TEST_SOURCES CONFIGURE_DEPENDS "${CMAKE_SOURCE_DIR}/tests/unit/*.cpp")
target_link_libraries(Tests PRIVATE Catch2::Catch2)
target_sources(Tests PRIVATE ${TEST_SOURCES})
target_include_directories(Tests PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include/")

SetProjectWarnings(Tests)
SetBuildTypeOptions(Tests)
SetProjectProperties(Tests ${PROJECT_STANDARD})