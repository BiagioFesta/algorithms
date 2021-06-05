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
#include <algorithms/Array/IsPermutation.hpp>
#include <unordered_map>
#include <vector>

namespace algorithms {

bool IsPermutation(const std::vector<int>& iVectA, const std::vector<int>& iVectB) {
  if (iVectA.size() != iVectB.size()) return false;

  std::unordered_map<int, int> aOccTable;
  for (const int aNumber : iVectA) {
    aOccTable[aNumber] += 1;
  }

  for (const int aNumber : iVectB) {
    const int aOccRemain = --aOccTable[aNumber];
    if (aOccRemain < 0) {
      return false;
    }
    if (aOccRemain == 0) {
      aOccTable.erase(aNumber);
    }
  }

  return aOccTable.empty();
}

}  // namespace algorithms
