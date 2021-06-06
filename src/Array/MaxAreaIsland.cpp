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
#include <algorithm>
#include <algorithms/Array/MaxAreaIsland.hpp>
#include <stack>
#include <vector>

namespace algorithms {

int MaxAreaIsland(const std::vector<std::vector<int>>& grid) {
  if (grid.empty()) return 0;

  const int R = grid.size();
  const int C = grid[0].size();
  const int N = R * C;

  std::stack<int> dfs;
  std::vector<bool> closed(N);
  int maxArea = 0, cArea;

  for (int z = 0; z < N; ++z) {
    if (grid[z / C][z % C] && !closed[z]) {
      dfs.push(z);
      closed[z] = true;
      cArea = 0;

      while (!dfs.empty()) {
        int x = dfs.top();
        dfs.pop();
        cArea += 1;

        if (x % C != 0 && grid[x / C][(x - 1) % C] && !closed[x - 1]) {
          dfs.push(x - 1);
          closed[x - 1] = true;
        }
        if (x % C != C - 1 && grid[x / C][(x + 1) % C] && !closed[x + 1]) {
          dfs.push(x + 1);
          closed[x + 1] = true;
        }
        if (x >= C && grid[(x - C) / C][x % C] && !closed[x - C]) {
          dfs.push(x - C);
          closed[x - C] = true;
        }
        if (x + C < N && grid[(x + C) / C][x % C] && !closed[x + C]) {
          dfs.push(x + C);
          closed[x + C] = true;
        }
      }

      maxArea = std::max(maxArea, cArea);
    }
  }

  return maxArea;
}

}  // namespace algorithms
