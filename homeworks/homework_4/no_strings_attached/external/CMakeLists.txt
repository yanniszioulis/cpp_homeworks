# Applies only to this folder and below (so only to GoogleTest)
set(CMAKE_CXX_STANDARD 17)
# Build GoogleTest. This creates the targets GTest::gtest and GTest::gtest_main
add_subdirectory(googletest)