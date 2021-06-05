/*
  Copyright (C) 2021  Biagio Festa

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
#include <algorithms/String/MinimumWindowSubstring.hpp>
#include <limits>
#include <string>

namespace {

/*! \brief Checks all values in the array are equal or less than zero.
 *  \note  Complexity  -->  Time: O(Size)
 */
template <std::size_t Size>
constexpr bool NoNeeded(int table[Size]) noexcept {
  return std::all_of(table, table + Size, [](const int value) noexcept { return value <= 0; });
}

}  // anonymous namespace

namespace algorithms {

std::string MinimumWindowSubstring(const std::string& s, const std::string& t) {
  constexpr std::size_t kTableSize = 1 << 8;
  int table[kTableSize]{};
  for (const char c : t) {
    ++table[static_cast<std::size_t>(c)];
  }

  const int lj = static_cast<int>(s.size()) - 1;
  int i = 0, j = -1;
  int imin = 0, jmin = -1;

  while (true) {
    while (j < lj && !::NoNeeded<kTableSize>(table)) {
      --table[static_cast<std::size_t>(s[++j])];
    }
    if (!::NoNeeded<kTableSize>(table)) {
      return jmin < 0 ? "" : s.substr(imin, jmin + 1 - imin);
    }
    do {
      if ((jmin < 0) || (j + 1 - i < jmin + 1 - imin)) {
        imin = i;
        jmin = j;
      }
      ++table[static_cast<std::size_t>(s[i++])];
    } while (::NoNeeded<kTableSize>(table));
  }
}

}  // namespace algorithms
