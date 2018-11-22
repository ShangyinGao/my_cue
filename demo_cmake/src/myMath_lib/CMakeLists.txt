cmake_minimum_required(VERSION 3.5)
project(myMath_lib)

add_library(myMath SHARED myMath.cpp)

# install(TARGETS myMath DESTINATION lib)
# install(FILES myMath.h DESTINATION include)

