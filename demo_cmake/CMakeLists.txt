cmake_minimum_required(VERSION 3.5)
project(demo_cmake)

add_subdirectory(src/myMath_lib)
include_directories(src/myMath_lib)

message(STATUS "cmake binary dir: " ${CMAKE_BINARY_DIR})
message(STATUS "project source dir: " ${PROJECT_SOURCE_DIR})

add_executable(test_mymath src/main.cpp)
target_link_libraries(test_mymath myMath)
install(TARGETS test_mymath DESTINATION bin)
