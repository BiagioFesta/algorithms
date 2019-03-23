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
#include <algorithm>
#include <algorithms/Array/Partition.hpp>
#include <functional>
#include <utility>
#include <vector>

namespace algorithms::test {

TEST(Array, Partition) {
  using Test = std::pair<std::vector<int>, std::function<bool(int)>>;

  static const auto isLessThanFive = [](const int iNumber) {
    return iNumber < 5;
  };

  std::vector<Test> testCases = {{{1, 2, 3, 4, 5, 6}, isLessThanFive},
                                 {{1, 2, 10, 11, 3}, isLessThanFive},
                                 {{}, isLessThanFive},
                                 {{1, 2, 3}, isLessThanFive},
                                 {{6, 7, 8}, isLessThanFive}};

  for (auto& [v, fn] : testCases) {
    Partition(&v, fn);
    ASSERT_TRUE(std::is_partitioned(v.cbegin(), v.cend(), fn));
  }
}

}  // namespace algorithms::test
