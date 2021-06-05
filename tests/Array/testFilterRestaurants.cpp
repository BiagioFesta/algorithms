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
#include <algorithms/Array/FilterRestaurants.hpp>
#include <tuple>
#include <vector>

namespace algorithms::test {

TEST(Array, FilterRestaurants) {
  using Test = std::tuple<std::vector<std::vector<int>>, int, int, int, std::vector<int>>;
  const std::vector<Test> testCases = {
      {{{1, 4, 1, 40, 10}, {2, 8, 0, 50, 5}, {3, 8, 1, 30, 4}, {4, 10, 0, 10, 3}, {5, 1, 1, 15, 1}},
       1,
       50,
       10,
       {3, 1, 5}},
      {{{1, 4, 1, 40, 10}, {2, 8, 0, 50, 5}, {3, 8, 1, 30, 4}, {4, 10, 0, 10, 3}, {5, 1, 1, 15, 1}},
       0,
       50,
       10,
       {4, 3, 2, 1, 5}},
      {{{1, 4, 1, 40, 10}, {2, 8, 0, 50, 5}, {3, 8, 1, 30, 4}, {4, 10, 0, 10, 3}, {5, 1, 1, 15, 1}}, 0, 30, 3, {4, 5}}};

  for (const auto& [rests, veg, maxPrice, maxDist, expt] : testCases) {
    ASSERT_EQ(FilterRestaurants(rests, veg, maxPrice, maxDist), expt);
  }
}

}  // namespace algorithms::test
