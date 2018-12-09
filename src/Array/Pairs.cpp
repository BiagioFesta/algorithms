/*
  Copyright (C) 2018  Biagio Festa

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
#include <algorithms/Array/Pairs.hpp>
#include <vector>

namespace algorithms {

int Pairs(std::vector<int> iNums, int iTarget) {
  const int kSize = iNums.size();  // O(1)

  std::sort(iNums.begin(), iNums.end());  // O(NlogN)

  int counter = 0;                              // O(1)
  for (int i = 0; i < kSize; ++i) {             // O(N)
    const int targetPair = iNums[i] - iTarget;  // O(1)
    if (std::binary_search(
            iNums.cbegin(), iNums.cend(), targetPair)) {  // O(logN)
      ++counter;                                          // O(1)
    }
  }

  return counter;  // O(1)
}

}  // namespace algorithms
