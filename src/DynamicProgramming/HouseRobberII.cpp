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
#include <algorithms/DynamicProgramming/HouseRobberII.hpp>
#include <cassert>
#include <vector>

namespace {

int HouseRobberIIImpl(const int* nums, const std::size_t size) {
  assert(size >= 2);

  std::vector<int> dp(size);
  dp[0] = nums[0];
  dp[1] = std::max(nums[0], nums[1]);

  for (std::size_t i = 2; i < size; ++i) {  // O(N)
    for (std::size_t k = 2; k <= i; ++k) {  // O(N)
      dp[i] = std::max(dp[i], nums[k] + dp[k - 2]);
    }
  }
  return dp.back();
}

}  // anonymous namespace

namespace algorithms {

int HouseRobberII(const std::vector<int>& nums) {
  const auto size = nums.size();
  if (size == 0) return 0;
  if (size == 1) return nums[0];
  if (size == 2) return std::max(nums[0], nums[1]);

  return std::max(::HouseRobberIIImpl(nums.data(), size - 1),
                  ::HouseRobberIIImpl(nums.data() + 1, size - 1));
}

}  // namespace algorithms
