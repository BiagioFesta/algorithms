/*
  Copyright (C) 2020  Biagio Festa

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
#include <algorithms/Array/RemoveDuplicatesSortedArrayII.hpp>
#include <utility>
#include <vector>

namespace {

bool SortedDuplicateAtMostTwice(const std::vector<int>& nums, const int len) {
  constexpr int kMaxDupsAllowed = 2;
  for (int i = 0; i < len; ++i) {
    if (i != 0 && nums[i] < nums[i - 1]) {
      return false;
    }
    if (i >= kMaxDupsAllowed && nums[i] == nums[i - kMaxDupsAllowed]) {
      return false;
    }
  }
  return true;
}

}  // anonymous namespace

namespace algorithms::test {

TEST(Array, RemoveDuplicatesSortedArrayII) {
  using Test = std::pair<std::vector<int>, int>;
  const std::vector<Test> testCases = {{{1, 1, 1, 2, 2, 3}, 5},
                                       {{0, 0, 1, 1, 1, 1, 2, 3, 3}, 7}};

  for (const auto& [nums, expt] : testCases) {
    auto mutableNums = nums;
    const auto ans = RemoveDuplicatesSortedArrayII(&mutableNums);

    ASSERT_EQ(ans, expt);
    ASSERT_TRUE(SortedDuplicateAtMostTwice(mutableNums, ans));
  }
}

}  // namespace algorithms::test
