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
#include <algorithms/Array/NumOfIslands.hpp>
#include <cassert>
#include <queue>
#include <vector>

namespace {

bool IsProperMatrix(const std::vector<std::vector<char>>& iGrid) {
  if (iGrid.empty()) {
    return true;
  }
  const auto M = iGrid.front().size();
  return std::all_of(iGrid.cbegin(), iGrid.cend(), [M](const auto& row) {
    return row.size() == M;
  });
}

}  // anonymous namespace

namespace algorithms {

int NumIslands(const std::vector<std::vector<char>>& iGrid) {
  using Queue = std::queue<std::size_t>;
  constexpr char kLandTile = '1';

  assert(::IsProperMatrix(iGrid));
  if (iGrid.empty()) {
    return 0;
  }
  const auto N = iGrid.size();
  const auto M = iGrid.front().size();
  const auto Size = N * M;

  int islandsCounter = 0;

  std::vector<bool> tileChecked(Size, false);
  Queue queue;

  for (std::size_t i = 0; i < N; ++i) {
    for (std::size_t j = 0; j < M; ++j) {
      if (iGrid[i][j] == kLandTile) {
        const auto index = i * M + j;
        assert(index < Size);

        if (!tileChecked[index]) {
          ++islandsCounter;
          queue.emplace(index);
          tileChecked[index] = true;

          while (!queue.empty()) {
            const std::size_t current = queue.front();
            queue.pop();
            if (iGrid[current / M][current % M] == kLandTile) {
              if (((current + 1) % M) != 0 && !tileChecked[current + 1]) {
                queue.emplace(current + 1);
                tileChecked[current + 1] = true;
              }
              if ((current % M) != 0 && !tileChecked[current - 1]) {
                queue.emplace(current - 1);
                tileChecked[current - 1] = true;
              }
              if ((current >= M) && !tileChecked[current - M]) {
                queue.emplace(current - M);
                tileChecked[current - M] = true;
              }
              if ((current + M < Size) && !tileChecked[current + M]) {
                queue.emplace(current + M);
                tileChecked[current + M] = true;
              }
            }
          }  // until queue not empty
        }
      }
    }  // for j
  }    // for i

  return islandsCounter;
}

}  // namespace algorithms
