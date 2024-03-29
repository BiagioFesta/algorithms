/*
  Copyright (C) 2022  Biagio Festa

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
#include <algorithms/DynamicProgramming/IntegerBreak.hpp>
#include <cassert>
#include <vector>

namespace algorithms {

int IntegerBreak(const int n) {
  assert(n >= 2 && n <= 58);

  std::vector<int> aTable(n + 1);
  aTable[1] = 1;

  for (int i = 2; i <= n; ++i) {
    for (int k = 1; k < i; ++k) {
      aTable[i] = std::max(aTable[i], k * std::max(aTable[i - k], i - k));
    }
  }

  return aTable[n];
}

}  // namespace algorithms
