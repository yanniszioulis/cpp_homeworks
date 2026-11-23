# A library target named string_split, built from this .cpp file
add_library(string_split string_split.cpp)
add_library(string_trim string_trim.cpp)

# PUBLIC: string_split uses cxx_setup's settings, AND passes them on
# to anything that links string_split later
target_link_libraries(string_split PUBLIC cxx_setup)
target_link_libraries(string_trim PUBLIC cxx_setup)

if(BUILD_TESTING)
  include(GoogleTest)    # provides gtest_discover_tests
  add_executable(string_split_test string_split_test.cpp)
  target_link_libraries(string_split_test PRIVATE string_split GTest::gtest_main)
  gtest_discover_tests(string_split_test)

  add_executable(string_trim_test string_trim_test.cpp)
  target_link_libraries(string_trim_test PRIVATE string_trim GTest::gtest_main)
  gtest_discover_tests(string_trim_test)
endif()