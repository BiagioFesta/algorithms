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
#include <algorithms/Misc/SumSquareNumbers.hpp>
#include <cassert>
#include <cmath>

namespace algorithms {

bool SumSquareNumbers(const int c) {
  assert(c >= 0);

  unsigned p = 0, q = std::sqrt(c), tmp, uc = c;

  while (p <= q) {
    tmp = (p * p) + (q * q);
    if (tmp == uc) {
      return true;
    }
    if (tmp < uc) {
      ++p;
    } else {
      --q;
    }
  }

  return false;
}

}  // namespace algorithms
