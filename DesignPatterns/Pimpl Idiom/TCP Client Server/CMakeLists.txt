cmake_minimum_required(VERSION 3.10)

project(TCPNetworking LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -g")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_library(client SHARED clientImpl.cpp)
add_library(server SHARED serverImpl.cpp)

target_include_directories(client PUBLIC ${CMAKE_SOURCE_DIR})
target_include_directories(server PUBLIC ${CMAKE_SOURCE_DIR})

add_executable(client_app testclient.cpp)
target_link_libraries(client_app PRIVATE client)

add_executable(server_app testServer.cpp)
target_link_libraries(server_app PRIVATE server)