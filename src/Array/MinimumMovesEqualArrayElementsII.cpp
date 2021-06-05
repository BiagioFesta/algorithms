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
#include <algorithms/Array/MinimumMovesEqualArrayElementsII.hpp>
#include <cassert>
#include <numeric>
#include <vector>

namespace algorithms {

int MinimumMovesEqualArrayElementsII(const std::vector<int>& nums) {
  assert(nums.size() > 0);
  const auto medianElement = nums.size() / 2;
  auto mutableNums = nums;
  std::nth_element(mutableNums.begin(), mutableNums.begin() + medianElement, mutableNums.end());
  return std::accumulate(
      nums.cbegin(), nums.cend(), 0, [median = mutableNums[medianElement]](const int ans, const int n) noexcept {
        return ans + std::abs(n - median);
      });
}

}  // namespace algorithms
