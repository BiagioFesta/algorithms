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
#include <algorithm>
#include <algorithms/String/KSimilarStrings.hpp>
#include <cassert>
#include <iterator>
#include <queue>
#include <string>
#include <unordered_set>
#include <utility>

namespace algorithms {

int KSimilarStrings(const std::string& A, const std::string& B) {
  using State = std::pair<std::string, int>;
  using Queue = std::queue<State>;
  using CacheTable = std::unordered_set<std::string>;

  assert(std::is_permutation(A.cbegin(), A.cend(), B.cbegin(), B.cend()));

  Queue bfs;
  CacheTable visited;

  bfs.emplace(A, 0);
  visited.insert(A);
  while (true) {
    auto [str, depth] = std::move(bfs.front());
    bfs.pop();

    std::size_t miss = 0;
    while (miss < str.size() && str[miss] == B[miss]) {
      ++miss;
    }

    if (miss == str.size()) {
      return depth;
    }

    std::size_t i = miss + 1;
    while (i < str.size()) {
      if (str[i] == B[miss]) {
        std::swap(str[i], str[miss]);
        if (visited.insert(str).second) {
          bfs.emplace(str, depth + 1);
        }
        std::swap(str[i], str[miss]);
      }
      ++i;
    }
  }
}

}  // namespace algorithms
