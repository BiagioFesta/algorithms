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
#include <algorithms/Misc/NextGreaterElementIII.hpp>
#include <cassert>
#include <iterator>
#include <string>

namespace algorithms {

int NextGreaterElementIII(const int n) {
  assert(n >= 0);
  auto s = std::to_string(n);
  auto min = s.rbegin();
  auto pivot = std::next(min);

  while ((pivot != s.rend()) && (*pivot >= *std::prev(pivot))) ++pivot;  // O(N)
  if (pivot == s.rend()) return -1;
  while (*min <= *pivot) ++min;  // O(N)
  std::iter_swap(pivot, min);
  std::reverse(s.rbegin(), pivot);  // O(N)

  try {
    return std::stoi(s);
  } catch (const std::out_of_range&) {
    return -1;
  }
}

}  // namespace algorithms
