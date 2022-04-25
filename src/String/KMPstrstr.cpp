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
#include <algorithms/String/KMPstrstr.hpp>
#include <string>
#include <vector>

namespace {

std::vector<std::size_t> BuildLookupTable(const std::string& pattern) {
  const auto size = pattern.size();
  std::vector<std::size_t> table(size, 0);

  for (std::size_t i = 1, k = 0; i < size; ++i) {
    while (k && pattern[k] != pattern[i]) k = table[k - 1];
    if (pattern[k] == pattern[i]) ++k;
    table[i] = k;
  }

  return table;
}

}  // anonymous namespace

namespace algorithms {

int KMPstrstr(const std::string& str, const std::string& pattern) {
  const auto N = str.size();
  const auto M = pattern.size();

  if (M == 0) return 0;

  const auto table = ::BuildLookupTable(pattern);

  for (std::size_t i = 0, k = 0; i < N; ++i) {
    while (k && pattern[k] != str[i]) k = table[k - 1];
    if (pattern[k] == str[i]) ++k;
    if (k == M) return i - k + 1;
  }

  return -1;
}

}  // namespace algorithms
