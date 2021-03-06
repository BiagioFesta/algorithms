/*
  Copyright (C) 2021  Biagio Festa

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
#include <algorithms/Graph/BusRoutes.hpp>
#include <tuple>
#include <vector>

namespace algorithms::test {

TEST(Graph, BusRoutes) {
  using Test = std::tuple<std::vector<std::vector<int>>, int, int, int>;
  const std::vector<Test> testCases = {
      {{{1, 7}, {3, 5}}, 5, 5, 0}, {{{1, 2, 7}, {3, 6, 7}}, 1, 6, 2}, {{{1, 2, 3}, {3, 4, 5}}, 1, 6, -1}};

  for (const auto& [routes, s, t, expt] : testCases) {
    ASSERT_EQ(BusRoutes(routes, s, t), expt);
  }
}

}  // namespace algorithms::test
