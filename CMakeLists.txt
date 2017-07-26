cmake_minimum_required(VERSION 3.7)
project(btstl)

set(CMAKE_CXX_STANDARD 11)


set(BTSTL_ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR})

set(BTSTL_INCLUDE_DIR ${BTSTL_ROOT_DIR}/include)
set(BTSTL_EXTERNAL_DIR ${BTSTL_ROOT_DIR}/external)
set(BTSTL_TEST_DIR ${BTSTL_ROOT_DIR}/tests)

include_directories(${BTSTL_INCLUDE_DIR})

add_subdirectory(${BTSTL_EXTERNAL_DIR})
add_subdirectory(${BTSTL_TEST_DIR})