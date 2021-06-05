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
#include <algorithms/Misc/FindItinerary.hpp>
#include <cassert>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

namespace algorithms {

std::vector<std::string> FindItinerary(const std::vector<std::vector<std::string>>& tickets) {
  using HashTable = std::unordered_map<std::string, std::multiset<std::string>>;
  constexpr const char* kStartingAirport = "JFK";

  HashTable hashTable;
  for (const auto& link : tickets) {
    assert(link.size() == 2);
    hashTable[link[0]].insert(link[1]);
  }  // O(NlogN)

  std::vector<std::string> itinerary;
  itinerary.reserve(tickets.size() + 1);

  std::stack<std::string> dfs;
  dfs.emplace(kStartingAirport);

  while (!dfs.empty()) {                                    // O(N)
    auto& current = dfs.top();                              // O(1)
    if (auto& nexts = hashTable[current]; nexts.empty()) {  // O(1)
      itinerary.push_back(std::move(current));              // O(1)
      dfs.pop();                                            // O(1)
    } else {
      dfs.push(std::move(*(nexts.begin())));  // O(1)
      nexts.erase(nexts.begin());             // O(logN)
    }
  }

  std::reverse(itinerary.begin(), itinerary.end());  // O(N)
  return itinerary;
}

}  // namespace algorithms
