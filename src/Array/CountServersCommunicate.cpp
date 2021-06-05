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
#include <algorithms/Array/CountServersCommunicate.hpp>
#include <cassert>
#include <vector>

namespace algorithms {

int CountServersCommunicate(const std::vector<std::vector<int>>& grid) {
  assert(!grid.empty());
  const std::size_t m = grid.size();
  const std::size_t n = grid[0].size();

  std::vector<int> rowsCounter(m);
  std::vector<int> colsCounter(n);

  for (std::size_t i = 0; i < m; ++i) {    // O(M)
    for (std::size_t j = 0; j < n; ++j) {  // O(N)
      if (grid[i][j]) {
        ++rowsCounter[i];
        ++colsCounter[j];
      }
    }
  }

  int ans = 0;
  for (std::size_t i = 0; i < m; ++i) {    // O(M)
    for (std::size_t j = 0; j < n; ++j) {  // O(N)
      if (grid[i][j] && (rowsCounter[i] > 1 || colsCounter[j] > 1)) {
        ++ans;
      }
    }
  }

  return ans;
}

}  // namespace algorithms
