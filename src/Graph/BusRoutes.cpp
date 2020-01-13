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
  using Stop2Bus = std::unordered_map<int, std::unordered_set<std::size_t>>;
  using Queue = std::queue<std::pair<int, int>>;
  using VisitedSet = std::unordered_set<int>;

  if (S == T) {
    return 0;
  }

  Stop2Bus stop2bus;  // Given a stop, what bus we can take
  for (std::size_t i = 0; i < routes.size(); ++i) {
    for (const int j : routes[i]) {
      stop2bus[j].insert(i);
    }
  }

  Queue bfs;
  VisitedSet visited;

  for (const std::size_t bus : stop2bus[S]) {
    bfs.emplace(bus, 1);
    visited.insert(bus);
  }

  while (!bfs.empty()) {
    const auto [bus, depth] = bfs.front();
    bfs.pop();

    if (stop2bus[T].count(bus)) {
      return depth;
    }

    for (const int stop : routes[bus]) {
      for (const std::size_t nextBus : stop2bus[stop]) {
        if (auto r = visited.insert(nextBus); r.second) {
          bfs.emplace(nextBus, depth + 1);
        }
      }
    }
  }

  return -1;
}

}  // namespace algorithms
