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
#include <algorithms/Graph/BusRoutes.hpp>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

namespace algorithms {

int BusRoutes(const std::vector<std::vector<int>>& routes,
              const int S,
              const int T) {
  std::unordered_map<int, std::unordered_set<std::size_t>> stop2bus;
  for (std::size_t i = 0; i < routes.size(); ++i) {
    for (const int j : routes[i]) {
      stop2bus[j].insert(i);
    }
  }

  std::queue<std::pair<int, int>> bfs;
  std::unordered_set<int> visited;

  bfs.emplace(S, 0);
  visited.insert(S);

  while (!bfs.empty()) {
    const auto [currentStop, depth] = bfs.front();
    bfs.pop();

    if (currentStop == T) {
      return depth;
    }

    for (const std::size_t bus : stop2bus[currentStop]) {
      for (const int nextStop : routes[bus]) {
        if (!visited.count(nextStop)) {
          bfs.emplace(nextStop, depth + 1);
          visited.insert(nextStop);
        }
      }
    }
  }

  return -1;
}

}  // namespace algorithms
