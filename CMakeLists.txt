cmake_minimum_required(VERSION 3.15)
project(DiscMathlib CXX)

set(CMAKE_CXX_STANDARD 17)

add_library(DiscMathlib SHARED
    src/AdjMatFromSeq.cpp
    src/AdjMatrixToList.cpp
    src/approximation.cpp
    src/dllmain.cpp
    src/ExtendedEuclideanAlgorithm.cpp
    src/FractionalPart.cpp
    src/GeneratePruferCode.cpp
    src/IsEulerianGraph.cpp
    src/DiscMath.h
    src/framework.h
)

target_compile_definitions(DiscMathlib PRIVATE DISCMATHLIB_EXPORTS)

target_include_directories(DiscMathlib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

# 
# STATIC BUILD
# dllmain.cpp do not needed!
# 
# 
# add_library(DiscMathlib STATIC
#     src/AdjMatFromSeq.cpp
#     src/AdjMatrixToList.cpp
#     src/approximation.cpp
#     src/ExtendedEuclideanAlgorithm.cpp
#     src/FractionalPart.cpp
#     src/GeneratePruferCode.cpp
#     src/IsEulerianGraph.cpp
#     src/DiscMath.h
#     src/framework.h
# )
# target_include_directories(DiscMathlib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)
#