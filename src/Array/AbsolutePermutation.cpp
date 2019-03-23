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
#include <algorithms/Array/AbsolutePermutation.hpp>
#include <vector>

namespace algorithms {

std::vector<int> AbsolutePermutation(const int n, const int k) {
  std::vector<bool> usedTable(n, false);
  std::vector<int> absPerm;
  absPerm.resize(n);

  for (int i = 0; i < n; ++i) {
    const int aNumber = i + 1;
    if (const int aNegValue = aNumber - k;
        aNegValue > 0 && usedTable[aNegValue - 1] == false) {
      absPerm[i] = aNegValue;
      usedTable[aNegValue - 1] = true;
    } else if (const int aPosValue = aNumber + k;
               aPosValue <= n && usedTable[aPosValue - 1] == false) {
      absPerm[i] = aPosValue;
      usedTable[aPosValue - 1] = true;
    } else {
      return {-1};
    }
  }

  return absPerm;
}

}  // namespace algorithms
