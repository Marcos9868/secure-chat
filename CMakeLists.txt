cmake_minimum_required(VERSION 3.20)
project(secure_chat LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Basic security
add_compile_options(
  -Wall 
  -Wextra
  -Wpedantic
)

find_package(PkgConfig REQUIRED)
pkg_check_modules(SODIUM REQUIRED libsodium)

add_subdirectory(src/core/crypto)
add_subdirectory(src/core/identity)

add_executable(secure_chat
  src/main.cpp
)

target_include_directories(secure_chat PRIVATE
  ${SODIUM_INCLUDE_DIRS}/src/core
)

target_link_libraries(secure_chat secure_crypto secure_identity)