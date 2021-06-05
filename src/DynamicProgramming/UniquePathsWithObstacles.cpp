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
#include <algorithms/DynamicProgramming/UniquePathsWithObstacles.hpp>
#include <cassert>
#include <vector>

namespace algorithms {

int UniquePathsWithObstacles(const std::vector<std::vector<int>>& iObstacleGrid) {
  const int n = static_cast<int>(iObstacleGrid.size());
  if (n == 0) return 0;
  const int m = static_cast<int>(iObstacleGrid[0].size());
  if (m == 0) return 0;

  const int size = m * n;
  std::vector<int> table(size);
  if (!iObstacleGrid[n - 1][m - 1]) {
    table.back() = 1;
  }

  for (int i = n - 1; i >= 0; --i) {
    assert(static_cast<int>(iObstacleGrid[i].size()) == m);
    for (int j = m - 1; j >= 0; --j) {
      if (!iObstacleGrid[i][j]) {
        if (i != n - 1) {
          table[i * m + j] += table[(i + 1) * m + j];
        }
        if (j != m - 1) {
          table[i * m + j] += table[i * m + j + 1];
        }
      }
    }
  }

  return table[0];
}

}  // namespace algorithms
