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
#include <algorithms/DynamicProgramming/SherlockAndCost.hpp>
#include <array>
#include <vector>

namespace algorithms {

int SherlockAndCost(const std::vector<int>& iUpperBounds) {
  std::array<int, 2> L = {0, 0};
  std::array<int, 2> H = {0, 0};

  for (std::size_t i = 0u; i < iUpperBounds.size(); ++i) {
    L[1] = i == 0 ? 0 : std::max(L[0], H[0] + iUpperBounds[i - 1] - 1);
    H[1] = i == 0 ? 0 : std::max(H[0] + std::abs(iUpperBounds[i] - iUpperBounds[i - 1]), L[0] + iUpperBounds[i] - 1);
    L[0] = L[1];
    H[0] = H[1];
  }

  return std::max(L[1], H[1]);
}

}  // namespace algorithms
