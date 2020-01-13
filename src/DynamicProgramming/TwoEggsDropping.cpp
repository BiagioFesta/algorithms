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
#include <algorithms/DynamicProgramming/TwoEggsDropping.hpp>
#include <cassert>
#include <limits>
#include <utility>
#include <vector>

namespace algorithms {

std::pair<int, int> TwoEggsDropping(const int iNumFloors) {
  assert(iNumFloors >= 0);

  std::vector<int> aTable(iNumFloors + 1);

  int aKMin = -1;
  int aMinValue;

  for (int i = iNumFloors - 1; i >= 0; --i) {
    aKMin = -1;
    aMinValue = std::numeric_limits<int>::max();

    for (int k = i; k < iNumFloors; ++k) {
      const int aKSolution = std::max(k - i, aTable[k + 1]);
      if (aKSolution < aMinValue) {
        aMinValue = aKSolution;
        aKMin = k;
      }
    }
    assert(aKMin != -1);

    aTable[i] = aMinValue + 1;
  }

  return std::make_pair(aTable[0], aKMin);
}

}  // namespace algorithms
