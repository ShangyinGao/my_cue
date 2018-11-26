cmake_minimum_required(VERSION 3.5)
project(my_cue)

set(CMAKE_CXX_STANDARD 11)

find_library(Boost REQUIRED)


add_executable(multi_inherrt multi_inheritence.cpp)

add_executable(static static.cpp)

add_executable(boost boost.cpp)
target_link_libraries(boost ${Boost_LIBRARIES})