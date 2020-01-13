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
#include <algorithms/Array/Subsets.hpp>
#include <cassert>
#include <vector>

namespace algorithms {

std::vector<std::vector<int>> Subsets(const std::vector<int>& nums) {
  constexpr std::size_t kNumBitMask = sizeof(std::size_t) * 8;
  assert(nums.size() < kNumBitMask - 1);
  const std::size_t powerSetSize = 1ull << nums.size();

  std::vector<std::vector<int>> ans(powerSetSize);

  for (std::size_t i = 0; i < powerSetSize; ++i) {  // O(2 ^ N)
    ans[i].reserve(kNumBitMask);
    for (std::size_t j = 0; j < kNumBitMask; ++j) {  // O(1)
      if (i & (0x1ull << j)) {
        ans[i].push_back(nums[j]);
      }
    }
  }

  return ans;
}

}  // namespace algorithms
