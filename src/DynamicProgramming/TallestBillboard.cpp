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
#include <algorithms/DynamicProgramming/TallestBillboard.hpp>
#include <cassert>
#include <cmath>
#include <numeric>
#include <vector>

namespace algorithms {

int TallestBillboard(const std::vector<int>& rods) {
  static constexpr int kInvalid = std::numeric_limits<int>::min();
  const int n = rods.size();
  if (n < 2) {
    return 0;
  }
  const int sum = std::accumulate(rods.cbegin(), rods.cend(), 0);  // O(N)
  assert(sum <= 5000);

  std::vector<int> tableA(sum + 1, kInvalid);
  std::vector<int> tableB(sum + 1, kInvalid);

  tableA[0] = 0;
  tableA[rods.back()] = rods.back();

  for (int i = n - 2; i >= 0; --i) {  // O(N)
    const int rod = rods[i];
    for (int d = 0; d <= sum - rod; ++d) {  // O(S)
      auto& ans = tableB[d];
      ans = tableA[d];
      ans = std::max(ans, tableA[d + rod]);
      ans = std::max(ans, tableA[std::abs(d - rod)] + std::min(d, rod));
    }
    tableA.swap(tableB);
  }

  return tableA.front();
}

}  // namespace algorithms
