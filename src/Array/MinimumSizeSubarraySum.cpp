/*
  Copyright (C) 2019  Biagio Festa

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
#include <algorithms/Array/MinimumSizeSubarraySum.hpp>
#include <algorithm>
#include <cassert>
#include <limits>

namespace algorithms {

int MinimumSizeSubarraySum(const int* iArray, const int iSize, int s) {
  assert(s > 0);
  int min = std::numeric_limits<int>::max();
  int sum = 0;
  int i = 0;
  int j = 0;

  for (; j < iSize; ++j) {
    sum += iArray[j];
    if (sum >= s) {
      min = std::min(min, j + 1 - i);
    }

    while (i < j && sum - iArray[i] >= s) {
      sum -= iArray[i];
      ++i;
      min = std::min(min, j + 1 - i);
    }
  }

  return min == std::numeric_limits<int>::max() ? 0 : min;
}

}  // namespace algorithms
