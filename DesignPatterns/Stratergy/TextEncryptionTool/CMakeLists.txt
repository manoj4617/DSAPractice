# Minimum version of CMake
cmake_minimum_required(VERSION 3.15)

# Project name and language
project(TextEncryptionTool LANGUAGES CXX)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Path to OpenSSL headers and libraries
set(OPENSSL_ROOT_DIR "C:\\Program Files\\OpenSSL-Win64")
set(OPENSSL_INCLUDE_DIR "${OPENSSL_ROOT_DIR}/include")
set(OPENSSL_LIBRARIES "${OPENSSL_ROOT_DIR}/ib/VC/x64/MTd")

# Find OpenSSL package
find_package(OpenSSL REQUIRED)

# Include directories
include_directories(${OPENSSL_INCLUDE_DIR})

# Add the executable
add_executable(text_encryptor enc_strategy.cpp)

# Link OpenSSL libraries
target_link_libraries(text_encryptor OpenSSL::SSL OpenSSL::Crypto)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)