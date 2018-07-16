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
#include <AlgArrays.hpp>
#include <tuple>
#include <vector>

namespace {

template <typename T>
bool checkEqualityVectors(const std::vector<T>& v1, const std::vector<T>& v2) {
  if (v1.size() != v2.size()) return false;
  for (std::size_t i = 0; i < v1.size(); ++i) {
    if (v1[i] != v2[i]) return false;
  }
  return true;
}

}  // anonymous namespace

namespace algorithms::test {

TEST(AlgArrays, isAlmostNonDecreasing) {
  using Test = std::pair<std::vector<int>, bool>;
  const std::vector<Test> TestCases = {
      {{4, 2, 3}, true}, {{4, 2, 1}, false}, {{3, 4, 2, 3}, false}};

  for (const auto& [str, exp] : TestCases) {
    ASSERT_EQ(isAlmostNonDecreasing(str.data(), str.size()), exp);
  }
}

TEST(AlgArrays, minSizeSubArraySum) {
  const std::vector<int> kData1 = {2, 3, 1, 2, 4, 3};
  ASSERT_EQ(minSizeSubArraySum(kData1.data(), kData1.size(), 7), 2);

  const std::vector<int> kData2 = {1};
  ASSERT_EQ(minSizeSubArraySum(kData2.data(), kData2.size(), 7), 0);

  const std::vector<int> kData3 = {1, 1, 4, 3, 1, 1, 1};
  ASSERT_EQ(minSizeSubArraySum(kData3.data(), kData3.size(), 7), 2);

  const std::vector<int> kData4 = {};
  ASSERT_EQ(minSizeSubArraySum(kData4.data(), kData4.size(), 100), 0);

  const std::vector<int> kData5 = {
      12, 28, 83, 4, 25, 26, 25, 2, 25, 25, 25, 12};
  ASSERT_EQ(minSizeSubArraySum(kData5.data(), kData5.size(), 213), 8);
}

TEST(AlgArrays, findDisappearedNumbers) {
  using Test = std::pair<std::vector<int>, std::vector<int>>;

  const Test test1 = {{4, 3, 2, 7, 8, 2, 3, 1}, {5, 6}};
  const auto result1 = findDisappearedNumbers(test1.first);
  ASSERT_TRUE(::checkEqualityVectors(result1, test1.second));
}

TEST(AlgArrays, findLengthOfLCIS) {
  using Test = std::pair<std::vector<int>, int>;

  const Test test1 = {{1, 3, 5, 4, 7}, 3};
  ASSERT_EQ(findLengthOfLCIS(test1.first), test1.second);

  const Test test2 = {{2, 2, 2, 2}, 1};
  ASSERT_EQ(findLengthOfLCIS(test2.first), test2.second);

  const Test test3 = {{}, 0};
  ASSERT_EQ(findLengthOfLCIS(test3.first), test3.second);

  const Test test4 = {{1}, 1};
  ASSERT_EQ(findLengthOfLCIS(test4.first), test4.second);
}

}  // namespace algorithms::test
