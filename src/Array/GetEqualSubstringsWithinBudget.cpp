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
#include <algorithms/Array/GetEqualSubstringsWithinBudget.hpp>
#include <cassert>
#include <cmath>
#include <string>

namespace algorithms {

int GetEqualSubstringsWithinBudget(const std::string& s,
                                   const std::string& t,
                                   const int maxCost) {
  const std::size_t size = s.size();
  assert(size == t.size());

  std::size_t i = 0, j = 0;
  int max = 0, cc = 0;

  while (j < size) {
    const int cost = std::abs(static_cast<int>(s[j]) - static_cast<int>(t[j]));
    if (cc + cost <= maxCost) {
      cc += cost;
      max = std::max(max, static_cast<int>(j - i + 1));
      ++j;
    } else {
      if (j == i) {
        ++j;
      } else {
        cc -= std::abs(static_cast<int>(s[i]) - static_cast<int>(t[i]));
      }
      ++i;
    }
  }

  return max;
}

}  // namespace algorithms
