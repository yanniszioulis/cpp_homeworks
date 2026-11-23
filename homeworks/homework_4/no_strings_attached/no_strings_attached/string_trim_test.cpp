#include <gtest/gtest.h>
#include <no_strings_attached/string_trim.h>

#include <string>
#include <vector>

using no_strings_attached::Trim;

TEST(TrimTest, TrimLeft) {
  const std::string expected{"hello "};
  EXPECT_EQ(Trim("  hello ", ' ', no_strings_attached::Side::kLeft), expected);
}

TEST(TrimTest, TrimRight) {
  const std::string expected{"  hello"};
  EXPECT_EQ(Trim("  hello ", ' ', no_strings_attached::Side::kRight), expected);
}

TEST(TrimTest, TrimBoth) {
  const std::string expected{"hello"};
  EXPECT_EQ(Trim("  hello ", ' ', no_strings_attached::Side::kBoth), expected);
}

TEST(TrimTest, TrimLeftNonSpace) {
  const std::string expected{"ello"};
  EXPECT_EQ(Trim("hello", 'h', no_strings_attached::Side::kLeft), expected);
}

TEST(TrimTest, TrimOverload) {
  const std::string expected{"hello"};
  EXPECT_EQ(Trim("  hello "), expected);
}
