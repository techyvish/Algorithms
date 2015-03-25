cmake_minimum_required(VERSION 3.1)
project(CompProgramming)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libstdc++")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES SRM\ 653/RockPaperScissorsMagicEasy.cpp)

#set(SOURCE_FILES /SRM 653/RockPaperScissorsMagicEasy.cpp)
add_executable(CompProgramming ${SOURCE_FILES})