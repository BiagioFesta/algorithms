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
#include <algorithm>
#include <algorithms/Array/ThreeSum.hpp>
#include <vector>

namespace algorithms {

std::vector<std::vector<int>> ThreeSum(std::vector<int>* iNumbers) {
  const int kSize = iNumbers->size();
  std::vector<std::vector<int>> aTriplets;

  std::sort(iNumbers->begin(), iNumbers->end());

  for (int i = 0; i < kSize; ++i) {
    const int aCurrentNumber = (*iNumbers)[i];
    int aLower = i + 1;
    int aUpper = kSize - 1;

    while (aLower < aUpper) {
      const int aLowerNumber = (*iNumbers)[aLower];
      const int aUpperNumber = (*iNumbers)[aUpper];
      const int aSum = aLowerNumber + aUpperNumber;

      if (aSum < -aCurrentNumber) {
        ++aLower;
      } else if (-aCurrentNumber < aSum) {
        --aUpper;
      } else {
        aTriplets.emplace_back(
            std::vector<int>{aCurrentNumber, aLowerNumber, aUpperNumber});

        while ((*iNumbers)[aLower] == aLowerNumber) ++aLower;
        while ((*iNumbers)[aUpper] == aUpperNumber) --aUpper;
      }
    }

    while (i < kSize - 1 && (*iNumbers)[i + 1] == aCurrentNumber) ++i;
  }

  return aTriplets;
}

}  // namespace algorithms
