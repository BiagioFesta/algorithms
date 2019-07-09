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
#include <algorithms/DynamicProgramming/OnesAndZeroes.hpp>
#include <string>
#include <vector>

namespace {

using CacheTable = std::vector<std::vector<std::vector<int>>>;

int OnesAndZeroesImpl(const std::vector<std::string>& strs,
                      const std::size_t i,
                      const int p,
                      const int q,
                      CacheTable* cacheTable) {
  if (i >= strs.size() || p < 0 || q < 0) {
    return 0;
  }

  int& value = (*cacheTable)[i][p][q];
  if (value == -1) {
    value = OnesAndZeroesImpl(strs, i + 1, p, q, cacheTable);

    if (const auto newZeroes =
            p - std::count(strs[i].cbegin(), strs[i].cend(), '0');
        newZeroes >= 0) {
      if (const auto newOnes =
              q - std::count(strs[i].cbegin(), strs[i].cend(), '1');
          newOnes >= 0) {
        value = std::max(
            value,
            1 + OnesAndZeroesImpl(strs, i + 1, newZeroes, newOnes, cacheTable));
      }
    }
  }
  return value;
}

}  // anonymous namespace

namespace algorithms {

int OnesAndZeroes(const std::vector<std::string>& strs,
                  const int m,
                  const int n) {
  CacheTable cacheTable(
      strs.size(),
      std::vector<std::vector<int>>(m + 1, std::vector<int>(n + 1, -1)));
  return ::OnesAndZeroesImpl(strs, 0, m, n, &cacheTable);
}

}  // namespace algorithms
