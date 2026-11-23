#include <gtest/gtest.h>
#include <no_strings_attached/string_split.h>

#include <string>
#include <vector>

using no_strings_attached::Split;

TEST(SplitTest, SplitsTwoWordsOnSpace) {
  const std::vector<std::string> expected{"hello", "world"};
  EXPECT_EQ(Split("hello world", " "), expected);
}

TEST(SplitTest, KeepsEmptyPieces) {
  const std::vector<std::string> expected{"", "ab", "ba"};
  EXPECT_EQ(Split("aaabaaba", "aa"), expected);
}

TEST(SplitTest, OnlyKeepsFirstPart) {
  const std::vector<std::string> expected{"hello"};
  EXPECT_EQ(Split("hello world", " ", 1), expected);
}

TEST(SplitTest, KeepsBothParts) {
  const std::vector<std::string> expected{"hello", "world"};
  EXPECT_EQ(Split("hello world", " ", 2), expected);
}

TEST(SplitTest, KeepsFirstTwoParts) {
  const std::vector<std::string> expected{"", "ab"};
  EXPECT_EQ(Split("aaabaaba", "aa", 2), expected);
}