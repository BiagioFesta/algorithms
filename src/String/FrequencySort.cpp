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
#include <algorithms/String/FrequencySort.hpp>
#include <queue>
#include <string>
#include <utility>

namespace algorithms {

std::string FrequencySort(const std::string& s) {
  using HeapNode = std::pair<char, int>;
  struct HeapComparator {
    bool operator()(const HeapNode& a, const HeapNode& b) const noexcept {
      return a.second < b.second;
    }
  };
  using Heap = std::priority_queue<HeapNode, std::vector<HeapNode>, HeapComparator>;
  constexpr std::size_t kHashSize = sizeof(char) << 8;

  int hashTable[kHashSize]{};

  for (const char c : s) {  // O(N)
    ++(hashTable[static_cast<int>(c)]);
  }

  Heap heap;
  for (std::size_t i = 0; i < kHashSize; ++i) {  // O(1)
    if (hashTable[i]) {
      heap.emplace(static_cast<char>(i), hashTable[i]);  // O(1)
    }
  }

  std::string rtn;
  rtn.reserve(s.size());

  while (!heap.empty()) {  // O(1)
    rtn.append(heap.top().second, heap.top().first);
    heap.pop();
  }

  return rtn;
}

}  // namespace algorithms
