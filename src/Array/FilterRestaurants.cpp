/*
  Copyright (C) 2022  Biagio Festa

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
#include <algorithms/Array/FilterRestaurants.hpp>
#include <cassert>
#include <queue>
#include <utility>

namespace algorithms {

std::vector<int> FilterRestaurants(const std::vector<std::vector<int>>& restaurants,
                                   int veganFriendly,
                                   int maxPrice,
                                   int maxDistance) {
  std::priority_queue<std::pair<int, int>> ranks;
  std::vector<int> sortedIds;

  for (const auto& r : restaurants) {  // O(N)
    assert(r.size() == 5);
    if (veganFriendly <= r[2] && r[3] <= maxPrice && r[4] <= maxDistance) {
      ranks.emplace(r[1], r[0]);  // O(logN)
    }
  }

  sortedIds.reserve(ranks.size());
  while (!ranks.empty()) {                    // O(N)
    sortedIds.push_back(ranks.top().second);  // O(1)
    ranks.pop();                              // O(logN)
  }

  return sortedIds;
}

}  // namespace algorithms
