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
#include <algorithms/String/SwapAdjacentLR.hpp>
#include <cassert>
#include <string>

namespace algorithms {

bool SwapAdjacentLR(const std::string& start, const std::string& end) {
  const std::size_t size = start.size();
  assert(size == end.size());

  int r = 0, l = 0;

  for (std::size_t i = 0; i < size; ++i) {
    const char s = start[i];
    const char e = end[i];
    if (s != e) {
      if (s == 'R' && e == 'X' && l == 0) {
        ++r;
      } else if (s == 'X' && e == 'R' && r > 0) {
        --r;
      } else if (s == 'X' && e == 'L' && r == 0) {
        ++l;
      } else if (s == 'L' && e == 'X' && l > 0) {
        --l;
      } else {
        return false;
      }
    }
  }

  return r == 0 && l == 0;
}

}  // namespace algorithms
