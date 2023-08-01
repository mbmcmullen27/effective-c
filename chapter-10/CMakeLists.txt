cmake_minimum_required(VERSION 3.10)
project(primetest VERSION "1.0.0")

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

Set(CMAKE_C_STANDARD 11)

if(${CMAKE_CXX_COMPILER_ID} STREQUAL MSVC)
  add_compile_options(-W4)
  add_compile_options(-WX)
elseif((${CMAKE_CXX_COMPILER_ID} STREQUAL GNU)
       OR (${CMAKE_CXX_COMPILER_ID} STREQUAL Clang))
  add_compile_options(-Wall -Wextra -Wpointer-arith -Wshadow -Werror)
else()
  # You may need to add compiler-specific options here if generating
  # for a compiler other than Visual Studio, Clang, or GCC.
endif()

include_directories(include)
add_subdirectory(src)
add_subdirectory(lib)
