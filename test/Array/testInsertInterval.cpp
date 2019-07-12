/*
  Copyright (C) 2019  Biagio Festa

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
#include <algorithms/Array/InsertInterval.hpp>
#include <tuple>
#include <vector>

namespace algorithms::test {

TEST(Array, InsertInterval) {
  using Test = std::tuple<std::vector<std::vector<int>>,
                          std::vector<int>,
                          std::vector<std::vector<int>>>;
  const std::vector<Test> testCases = {
      {{{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}},
       {4, 8},
       {{1, 2}, {3, 10}, {12, 16}}},
      {{{1, 3}, {6, 9}}, {2, 5}, {{1, 5}, {6, 9}}},
      {{{1, 3}}, {5, 6}, {{1, 3}, {5, 6}}},
      {{{1, 5}}, {0, 0}, {{0, 0}, {1, 5}}}};

  for (const auto& [intervals, newInterval, expt] : testCases) {
    ASSERT_EQ(InsertInterval(intervals, newInterval), expt);
  }
}

}  // namespace algorithms::test
