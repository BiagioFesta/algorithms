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
#include <algorithms/Graph/CourseScheduleII.hpp>
#include <tuple>
#include <vector>

namespace algorithms::test {

TEST(Graph, CourseScheduleII) {
  using Test = std::
      tuple<int, std::vector<std::vector<int>>, std::vector<std::vector<int>>>;
  const std::vector<Test> testCases = {
      {2, {{1, 0}}, {{0, 1}}},
      {4, {{1, 0}, {2, 0}, {3, 1}, {3, 2}}, {{0, 1, 2, 3}, {0, 2, 1, 3}}},
      {2, {{1, 0}, {0, 1}}, {{}}},
      {3, {{1, 0}, {2, 0}}, {{0, 2, 1}, {0, 1, 2}}}};

  for (const auto& [numCourses, deps, expts] : testCases) {
    const auto result = CourseScheduleII(numCourses, deps);
    ASSERT_TRUE(
        std::any_of(expts.cbegin(), expts.cend(), [&result](const auto& expt) {
          return result == expt;
        }));
  }
}

}  // namespace algorithms::test
