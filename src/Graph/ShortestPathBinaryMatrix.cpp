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
#include <algorithms/Graph/ShortestPathBinaryMatrix.hpp>
#include <cassert>
#include <queue>
#include <tuple>
#include <utility>
#include <vector>

namespace algorithms {

int ShortestPathBinaryMatrix(const std::vector<std::vector<int>>& grid) {
  constexpr int kEmptyCell = 0;
  const int N = grid.size();
  const int kMatrixSize = N * N;
  assert(kMatrixSize >= 1);

  std::queue<std::tuple<int, int, int>> bfs;
  std::vector<bool> visited(kMatrixSize);

  if (grid[0][0] == kEmptyCell) {
    bfs.emplace(0, 0, 1);
    visited[0] = true;
  }

  while (!bfs.empty()) {
    const auto [x, y, step] = bfs.front();
    bfs.pop();

    if (x == N - 1 && y == N - 1) {
      return step;
    }

    for (int dx = -1; dx < 2; ++dx) {
      if (const int nextX = x + dx; nextX >= 0 && nextX < N) {
        for (int dy = -1; dy < 2; ++dy) {
          if (const int nextY = y + dy; nextY >= 0 && nextY < N) {
            if (!visited[nextX * N + nextY]) {
              visited[nextX * N + nextY] = true;
              if (grid[nextX][nextY] == kEmptyCell) {
                bfs.emplace(nextX, nextY, step + 1);
              }
            }
          }
        }
      }
    }
  }

  return -1;
}

}  // namespace algorithms
