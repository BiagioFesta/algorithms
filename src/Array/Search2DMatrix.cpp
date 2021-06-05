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
#include <algorithms/Array/Search2DMatrix.hpp>
#include <vector>

namespace algorithms {

bool Search2DMatrix(const std::vector<std::vector<int>>& matrix, int target) {
  if (matrix.empty()) return false;
  const std::size_t N = matrix.size();
  const std::size_t M = matrix[0].size();
  const std::size_t Size = N * M;

  std::size_t lo = 0, hi = Size, mid;
  while (lo < hi) {
    mid = (lo + hi) / 2;
    if (const int value = matrix[mid / M][mid % M]; value == target) {
      return true;
    } else if (value < target) {
      lo = mid + 1;
    } else {
      hi = mid;
    }
  }

  return false;
}

}  // namespace algorithms
