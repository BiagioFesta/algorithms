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
#include <algorithms/Graph/CourseSchedule.hpp>
#include <cassert>
#include <stack>
#include <unordered_map>
#include <utility>
#include <vector>

namespace algorithms {

bool CourseSchedule(const int numCourses,
                    const std::vector<std::vector<int>>& prerequisites) {
  using NextHops = std::unordered_map<int, std::vector<int>>;
  NextHops nextHops;
  for (const auto& edge : prerequisites) {
    assert(edge.size() == 2);
    nextHops[edge[0]].push_back(edge[1]);
  }

  std::vector<bool> visited(numCourses, false);
  std::stack<std::pair<int, int>> dfs;

  for (int i = 0; i < numCourses; ++i) {
    if (!visited[i]) {
      dfs.emplace(i, 0);
      while (!dfs.empty()) {
        const auto [index, layer] = dfs.top();
        dfs.pop();
        visited[index] = true;
        if (layer > numCourses) {
          return false;
        }
        for (const int next : nextHops[index]) {
          dfs.emplace(next, layer + 1);
        }  // for all next hops
      }    // while dfs
    }      // i is not visited
  }        // for all i

  return true;
}

}  // namespace algorithms
