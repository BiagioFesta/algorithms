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
#include <algorithms/Graph/CourseSchedule.hpp>
#include <tuple>
#include <vector>

namespace algorithms::test {

TEST(Graph, CourseSchedule) {
  using Test = std::tuple<int, std::vector<std::vector<int>>, bool>;

  const std::vector<Test> testCases = {
      {2, {{1, 0}}, true}, {2, {{1, 0}, {0, 1}}, false}, {3, {{0, 1}, {0, 2}, {1, 2}}, true}};

  for (const auto& [numCourses, edges, expt] : testCases) {
    ASSERT_EQ(CourseSchedule(numCourses, edges), expt);
  }
}

}  // namespace algorithms::test
