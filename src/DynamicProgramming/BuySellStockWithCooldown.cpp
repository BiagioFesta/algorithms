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
#include <algorithms/DynamicProgramming/BuySellStockWithCooldown.hpp>
#include <limits>
#include <vector>

namespace algorithms {

int BuySellStockWithCooldown(const std::vector<int>& prices) {
  int f = std::numeric_limits<int>::min(), g = 0, h = 0, t;

  for (const int p : prices) {
    t = std::max(f, g - p);
    g = std::max(g, h);
    h = std::max(h, f + p);
    f = t;
  }

  return h;
}

}  // namespace algorithms
