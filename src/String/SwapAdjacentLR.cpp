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
#include <algorithms/String/SwapAdjacentLR.hpp>
#include <cassert>
#include <string>

namespace algorithms {

bool SwapAdjacentLR(const std::string& start, const std::string& end) {
  enum Diffs {
    R_DIFF = static_cast<int>('R') - static_cast<int>('X'),
    L_DIFF = static_cast<int>('X') - static_cast<int>('L'),
  };

  const std::size_t size = start.size();
  assert(size == end.size());

  int r = 0, l = 0;

  for (std::size_t i = 0; i < size; ++i) {
    const int diff = static_cast<int>(start[i]) - static_cast<int>(end[i]);
    switch (diff) {
      case R_DIFF:
        ++r;
        break;
      case -R_DIFF:
        --r;
        if (r < 0) return false;
        break;
      case L_DIFF:
        ++l;
        break;
      case -L_DIFF:
        --l;
        if (l < 0) return false;
        break;
      default:
        if (diff) return false;
    }
  }

  return r == 0 && l == 0;
}

}  // namespace algorithms
