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
#include <algorithms/DynamicProgramming/PartitionEqualSubSum.hpp>
#include <cassert>
#include <numeric>
#include <vector>

namespace algorithms {

bool PartitionEqualSubSum(const std::vector<int>& nums) {
  constexpr int kMaxValue = 100;
  constexpr int kMaxSize = 200;

  const auto kSum = std::accumulate(nums.cbegin(), nums.cend(), 0);
  if (kSum & 0x1 || kSum == 0) {
    return false;
  }
  const int kSize = nums.size();
  assert(kSize <= kMaxSize);
  const int kHalfSum = kSum >> 1;
  const int kM = kHalfSum + 1;
  const int kN = kSize + 1;

  // N x M
  std::vector<bool> table(kN * kM, false);
  table[kSize * kM + kHalfSum] = true;

  for (int i = kSize - 1; i >= 0; --i) {
    assert(nums[i] <= kMaxValue);
    for (int j = 0; j < kM; ++j) {
      table[i * kM + j] = table[(i + 1) * kM + j] || (j + nums[i] < kM ? table[(i + 1) * kM + j + nums[i]] : false);
    }
  }

  return table[0];
}

}  // namespace algorithms
