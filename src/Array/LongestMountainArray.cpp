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
#include <algorithms/Array/LongestMountainArray.hpp>
#include <vector>

namespace algorithms {

int LongestMountainArray(const std::vector<int>& A) {
  const int size = A.size();
  int i, j, max = 0;

  i = 0;
  while (i < size - 2) {
    while (i < size - 1 && A[i + 1] <= A[i]) ++i;
    j = i + 1;
    while (j < size && A[j - 1] < A[j]) ++j;
    if (j < size && A[j - 1] != A[j]) {
      while (j < size && A[j] < A[j - 1]) ++j;
      max = std::max(max, j - i);
    }

    i = j - 1;
  }

  return max;
}

}  // namespace algorithms
