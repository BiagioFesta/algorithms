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
#include <algorithms/Array/InsertInterval.hpp>
#include <vector>

namespace algorithms {

std::vector<std::vector<int>> InsertInterval(
    const std::vector<std::vector<int>>& intervals,
    const std::vector<int>& newInterval) {
  std::vector<std::vector<int>> res(intervals);

  auto [first, last] = std::equal_range(
      res.begin(), res.end(), newInterval, [](const auto& i1, const auto& i2) {
        return i1[1] < i2[0];
      });  // O(logN)

  if (first == last) {
    res.insert(first, newInterval);  // O(1) Amortized!
  } else {
    --last;
    (*last)[0] = std::min(newInterval[0], (*first)[0]);  // O(1)
    (*last)[1] = std::max(newInterval[1], (*last)[1]);   // O(1)
    res.erase(first, last);                              // O(N)
  }

  return res;
}

}  // namespace algorithms
