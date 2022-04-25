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
#include <algorithms/Misc/BrokenCalculator.hpp>
#include <cassert>

namespace algorithms {

int BrokenCalculator(int x, int y) noexcept {
  assert(x > 0);
  assert(y > 0);

  int ans = 0;
  while (true) {
    if (x - y >= 0) return ans + x - y;
    if (y & 0x1) {
      ++ans;
      ++y;
    }
    ++ans;
    y >>= 1;
  }
}

}  // namespace algorithms
