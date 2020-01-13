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
#include <algorithm>
#include <algorithms/Graph/CourseScheduleII.hpp>
#include <cassert>
#include <vector>

namespace algorithms {

std::vector<int> CourseScheduleII(
    const int numCourses,
    const std::vector<std::vector<int>>& prerequisites) {
  assert(numCourses >= 0);

  std::vector<int> inDegrees(numCourses, 0);
  std::vector<std::vector<int>> nextHops(numCourses);

  for (const auto& edge : prerequisites) {  // O(|E|)
    assert(edge.size() == 2);
    assert(edge[0] < numCourses);
    assert(edge[1] < numCourses);
    nextHops[edge[0]].push_back(edge[1]);
    ++(inDegrees[edge[1]]);
  }

  std::vector<int> roots;
  for (int i = 0; i < numCourses; ++i) {  // O(|V|)
    if (inDegrees[i] == 0) {
      roots.push_back(i);
    }
  }

  std::vector<int> topOrder;
  topOrder.reserve(numCourses);
  int numVisited = 0;

  while (!roots.empty()) {  // O(|V|)
    const int root = roots.back();
    roots.pop_back();

    topOrder.push_back(root);

    for (const int nextHop : nextHops[root]) {
      if ((--(inDegrees[nextHop])) == 0) {
        roots.push_back(nextHop);
      }
    }

    ++numVisited;
  }

  if (numVisited != numCourses) {
    topOrder.clear();
  }

  std::reverse(topOrder.begin(), topOrder.end());

  return topOrder;
}

}  // namespace algorithms
