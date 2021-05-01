add_executable(Test-Performance ${CMAKE_CURRENT_SOURCE_DIR}/tests/performance/main.cpp)

target_sources(Test-Performance PRIVATE

)

target_include_directories(Test-Performance INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/tests/performance/)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/performance/)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/external/)

SetProjectWarnings(Test-Performance)
SetBuildTypeOptions(Test-Performance)
SetProjectProperties(Test-Performance ${PROJECT_STANDARD})