include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(${gmock_SOURCE_DIR}/include ${gmock_SOURCE_DIR})

add_executable(btstl_test testMain.cc testStack.cc testVector.cc)

target_link_libraries(btstl_test gtest gtest_main)
