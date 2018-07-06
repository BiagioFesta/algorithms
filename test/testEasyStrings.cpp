/*
          Copyright (C) 2018  Biagio Festa

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

 */
#include <gtest/gtest.h>
#include <algorithm>
#include <easyStrings.hpp>
#include <string>
#include <tuple>
#include <vector>

namespace algorithms::test {

TEST(easyStrings, isPermutation) {
  const char* str1 = "dog";
  const char* str2 = "god";
  const char* str3 = "God";
  const char* str4 = "god ";
  const char* str5 = "og";

  ASSERT_TRUE(isPermutation(str1, str2));
  ASSERT_FALSE(isPermutation(str1, str3));
  ASSERT_FALSE(isPermutation(str1, str4));
  ASSERT_FALSE(isPermutation(str1, str5));
}

TEST(easyStrings, URLify) {
  constexpr const char kStr[] = "Mr John Smith";
  constexpr const char kExpectedResult[] = "Mr%20John%20Smith";
  constexpr int kLenStr = sizeof(kStr) - 1;

  std::string aBuffer(kStr);
  const int aNoSpaces = std::count(aBuffer.cbegin(), aBuffer.cend(), ' ');
  aBuffer.resize(aBuffer.size() + (aNoSpaces * 2), ' ');

  URLify(aBuffer.data(), kLenStr);

  ASSERT_TRUE(std::strcmp(aBuffer.c_str(), kExpectedResult) == 0);
}

TEST(easyStrings, palindromePermutation) {
  const char* str1 = "tactocoa";
  const char* str2 = "dog";
  const char* str3 = "bbiia";

  ASSERT_TRUE(palindromePermutation(str1));
  ASSERT_FALSE(palindromePermutation(str2));
  ASSERT_TRUE(palindromePermutation(str3));
}

TEST(easyStrings, oneWay) {
  using Case = std::tuple<std::string, std::string, bool>;
  const std::vector<Case> testCases = {{"pale", "ple", true},
                                       {"pales", "pale", true},
                                       {"pale", "bale", true},
                                       {"pale", "bae", false},
                                       {"paless", "pale", false}};

  for (const auto& test : testCases) {
    ASSERT_EQ(oneWay(std::get<0>(test), std::get<1>(test)), std::get<2>(test));
    ASSERT_EQ(oneWay(std::get<1>(test), std::get<0>(test)), std::get<2>(test));
  }
}

TEST(easyStrings, stringCompression) {
  const char aStr1[] = "aabcccccaaa";
  const char aStr2[] = "abc";
  constexpr int kSizeBuffer1 = sizeof(aStr1);
  constexpr int kSizeBuffer2 = sizeof(aStr2);
  char aBuffer[kSizeBuffer1];

  ASSERT_TRUE(stringCompression(aStr1, aBuffer, kSizeBuffer1));
  ASSERT_EQ(std::string(aBuffer), "2ab5c3a");

  ASSERT_FALSE(stringCompression(aStr2, aBuffer, 3));
}

TEST(easyStrings, maxLenSubWithoutRep) {
  const std::vector<std::pair<std::string, int>> testCases = {
      {"abcabcbb", 3}, {"bbbbb", 1}, {"pwwkew", 3}, {"", 0}, {"abba", 2}};

  for (const auto& test : testCases) {
    ASSERT_EQ(maxLenSubWithoutRep(test.first), test.second);
  }
}

}  // namespace algorithms::test
