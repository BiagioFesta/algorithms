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
#include <algorithms/BackTracking/CombinationSum3.hpp>
#include <tuple>
#include <vector>

namespace {

//! \brief It checks all values in the container are sorted AND they are unique.
template <typename Container>
bool isUniqueSortedValues(const Container& iContainer) {
  return (std::is_sorted(std::cbegin(iContainer), std::cend(iContainer))) &&
         (std::adjacent_find(std::cbegin(iContainer), std::cend(iContainer)) ==
          std::cend(iContainer));
}

}  // anonymous namespace

namespace algorithms::test {

TEST(BackTracking, CombinationSum3) {
  using Result = std::vector<std::vector<int>>;
  using Test = std::tuple<int, int, Result>;

  const std::vector<Test> testCases = {
      {3, 7, {{1, 2, 4}}},
      {3, 9, {{1, 2, 6}, {1, 3, 5}, {2, 3, 4}}},
      {1, 10, {}},
      {1, 9, {{9}}},
      {2, 14, {{6, 8}, {5, 9}}}};

  for (const auto& [k, n, expt] : testCases) {
    const auto aResult = CombinationSum3(k, n);

    ASSERT_TRUE(std::all_of(aResult.cbegin(),
                            aResult.cend(),
                            ::isUniqueSortedValues<std::vector<int>>));
    ASSERT_TRUE(std::all_of(
        expt.cbegin(), expt.cend(), ::isUniqueSortedValues<std::vector<int>>));

    ASSERT_TRUE(std::is_permutation(
        aResult.cbegin(), aResult.cend(), expt.cbegin(), expt.cend()));
  }
}

}  // namespace algorithms::test
