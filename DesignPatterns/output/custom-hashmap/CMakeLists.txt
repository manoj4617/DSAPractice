cmake_minimum_required(VERSION 3.10)

project(CustomHashMap)

set(CMAKE_CXX_STANDARD 11)

include_directories(src)

file(GLOB SOURCES "src/*.cpp" "src/strategies/*.cpp")

add_executable(CustomHashMap ${SOURCES})