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
#include <algorithms/Array/LarrysArray.hpp>
#include <vector>

namespace algorithms {

bool LarrysArray(const std::vector<int>& iVector) {
  const int kSize = iVector.size();
  std::vector<bool> visitedTable(kSize, false);

  // Info: aCountSwap will count the number of swaps needed to sort the array
  // with Intersion Sort.
  int aCountSwap = 0;
  for (int i = 0; i < kSize; ++i) {
    int aSwapForCurrent = 0;
    int j = i;
    while (!visitedTable[iVector[j] - 1]) {
      visitedTable[iVector[j] - 1] = true;
      ++aSwapForCurrent;
      j = iVector[j] - 1;
    }
    aCountSwap += aSwapForCurrent ? aSwapForCurrent - 1 : 0;
  }
  return !(aCountSwap % 2);
}

}  // namespace algorithms
