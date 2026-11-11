
#include "../string.hpp"

#include <gtest/gtest.h>

TEST(ExampleTest, Simple) {
  String s1("Please test your code");

  ASSERT_EQ(s1.Length(), 21);
  ASSERT_EQ(s1[0], 'P');
  ASSERT_EQ(s1[20], 'e');
  ASSERT_EQ(s1[5], 'e');

  String s2;
  ASSERT_TRUE(s2.Empty());
}

TEST(YourTest, Test) {
  String s;
}