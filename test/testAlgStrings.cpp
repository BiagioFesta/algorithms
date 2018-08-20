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
#include <AlgStrings.hpp>
#include <Utilities.hpp>
#include <algorithm>
#include <memory>
#include <string>
#include <tuple>
#include <vector>

namespace algorithms::test {

TEST(AlgStrings, isPermutation) {
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

TEST(AlgStrings, URLify) {
  constexpr const char kStr[] = "Mr John Smith";
  constexpr const char kExpectedResult[] = "Mr%20John%20Smith";
  constexpr int kLenStr = sizeof(kStr) - 1;

  std::string aBuffer(kStr);
  const int aNoSpaces = std::count(aBuffer.cbegin(), aBuffer.cend(), ' ');
  aBuffer.resize(aBuffer.size() + (aNoSpaces * 2), ' ');

  URLify(aBuffer.data(), kLenStr);

  ASSERT_TRUE(std::strcmp(aBuffer.c_str(), kExpectedResult) == 0);
}

TEST(AlgStrings, palindromePermutation) {
  const char* str1 = "tactocoa";
  const char* str2 = "dog";
  const char* str3 = "bbiia";

  ASSERT_TRUE(palindromePermutation(str1));
  ASSERT_FALSE(palindromePermutation(str2));
  ASSERT_TRUE(palindromePermutation(str3));
}

TEST(AlgStrings, oneWay) {
  using Case = std::tuple<std::string, std::string, bool>;
  const std::vector<Case> testCases = {{"pale", "ple", true},
                                       {"pales", "pale", true},
                                       {"pale", "bale", true},
                                       {"pale", "bae", false},
                                       {"paless", "pale", false}};

  for (const auto& [str1, str2, exp] : testCases) {
    ASSERT_EQ(oneWay(str1, str2), exp);
    ASSERT_EQ(oneWay(str2, str1), exp);
  }
}

TEST(AlgStrings, stringCompression) {
  using Test = std::tuple<const char*, int, bool, std::string>;
  const std::vector<Test> testCases = {{"aabcccccaaa", 11, true, "2ab5c3a"},
                                       {"abc", 3, false, ""},
                                       {"abcc", 3, false, ""},
                                       {"abcccccccccc", 4, false, ""}};

  for (const auto& [str, bufferSize, expt, result] : testCases) {
    const auto buffer = std::make_unique<char[]>(bufferSize);
    ASSERT_EQ(stringCompression(str, buffer.get(), bufferSize), expt);
    if (expt == true) {
      ASSERT_EQ(std::string(buffer.get()), result);
    }
  }
}

TEST(AlgStrings, maxLenSubWithoutRep) {
  const std::vector<std::pair<std::string, int>> testCases = {
      {"abcabcbb", 3}, {"bbbbb", 1}, {"pwwkew", 3}, {"", 0}, {"abba", 2}};

  for (const auto& [str, exp] : testCases) {
    ASSERT_EQ(maxLenSubWithoutRep(str), exp);
  }
}

TEST(AlgStrings, lenLastWord) {
  using Test = std::pair<std::string, int>;
  std::vector<Test> testCases = {{"Hello World", 5},
                                 {"On", 2},
                                 {"", 0},
                                 {"A BC DEFG", 4},
                                 {"   ab", 2},
                                 {"a   ", 1}};

  for (const auto& [str, exp] : testCases) {
    ASSERT_EQ(lenLastWord(str.c_str()), exp);
  }
}

TEST(AlgStrings, countSegment) {
  using Test = std::pair<const char*, int>;
  const std::vector<Test> testCases = {{"Hello, my name is Biagio", 5},
                                       {"    Hello, my name is Biagio    ", 5},
                                       {"OneSingleWord", 1}};

  for (const auto& [str, expt] : testCases) {
    ASSERT_EQ(countSegment(str), expt);
  }
}

TEST(AlgStrings, letterCasePermutation) {
  using Test = std::pair<std::string, std::vector<std::string>>;
  const std::vector<Test> testCases = {
      {"a1b2", {"a1b2", "a1B2", "A1b2", "A1B2"}},
      {"3z4", {"3z4", "3Z4"}},
      {"12345", {"12345"}},
      {"AB", {"AB", "aB", "Ab", "ab"}}};

  std::vector<std::string> result;
  for (const auto& [str, expt] : testCases) {
    letterCasePermutation(str, &result);
    ASSERT_TRUE(haveSameValues(expt, result));
  }
}

TEST(AlgStrings, steadyGene) {
  using Test = std::pair<std::string, int>;
  const std::vector<Test> testCases{
      {"GAAATAAA", 5}, {"", 0}, {"ACTGGTCA", 0}, {"GAAATAAT", 3}};

  for (const auto& [str, expt] : testCases) {
    ASSERT_EQ(steadyGene(str), expt);
  }
}

TEST(AlgStrings, encryptionStr) {
  using Test = std::pair<std::string, std::string>;
  const std::vector<Test> testCases{
      {"haveaniceday", "hae and via ecy"},
      {"if man was meant to stay on the ground god would have given us roots",
       "imtgdvs fearwer mayoogo anouuio ntnnlvt wttddes aohghn sseoau"},
      {"feedthedog", "fto ehg ee dd"},
      {"chillout", "clu hlt io"},
      {"halo", "hl ao"}};

  for (const auto& [str, expt] : testCases) {
    ASSERT_EQ(encryptionStr(str), expt);
  }
}

TEST(AlgStrings, biggerIsGreater) {
  using Test = std::pair<std::string, std::string>;
  const std::vector<Test> testCases{{"dkhc", "hcdk"},
                                    {"ab", "ba"},
                                    {"bb", "no answer"},
                                    {"hefg", "hegf"},
                                    {"dhck", "dhkc"}};

  for (const auto& [str, expt] : testCases) {
    ASSERT_EQ(biggerIsGreater(str), expt);
  }
}

TEST(AlgStrings, findLongestWord) {
  using Test = std::tuple<std::string, std::vector<std::string>, int>;
  const std::vector<Test> testCases{
      {"abpcplea", {"ale", "apple", "monkey", "plea"}, 1},
      {"abpcplea", {"a", "b", "c"}, 0},
      {"abc", {"d"}, -1}};

  for (const auto& [str, dict, expt] : testCases) {
    ASSERT_EQ(findLongestWord(str, dict), expt);
  }
}

TEST(AlgStrings, detectCapitalUse) {
  using Test = std::pair<std::string, bool>;
  const std::vector<Test> testCases{{"USA", true},
                                    {"FlaG", false},
                                    {"lower", true},
                                    {"AAAAa", false},
                                    {"mL", false},
                                    {"Leetcode", true}};

  for (const auto& [str, expt] : testCases) {
    ASSERT_EQ(detectCapitalUse(str), expt);
  }
}

TEST(AlgStrings, findTheDifference) {
  using Test = std::tuple<std::string, std::string, char>;
  const std::vector<Test> testCases{
      {"abcd", "abcde", 'e'}, {"abc", "ccba", 'c'}, {"abc", "bca", '\0'}};

  for (const auto& [s, t, expt] : testCases) {
    ASSERT_EQ(findTheDifference(s, t), expt);
  }
}

TEST(AlgStrings, strStr) {
  using Test = std::tuple<std::string, std::string, int>;
  const std::vector<Test> testCases{{"hello", "ll", 2},
                                    {"aaaaa", "bba", -1},
                                    {"whatever", "", 0},
                                    {"", "", 0},
                                    {"", "b", -1},
                                    {"mississippi", "issip", 4},
                                    {"aaaabbcc", "bbccdd", -1}};

  for (const auto& [s, t, expt] : testCases) {
    ASSERT_EQ(strStr(s, t), expt);
  }
}

}  // namespace algorithms::test
