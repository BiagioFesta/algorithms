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
#include <algorithms/Array/FindKLargest.hpp>
#include <cassert>
#include <vector>

namespace {

int FindKLargestImpl(int* nums, const std::size_t size, const int k) {
  assert(size > 0);

  const auto pindex =
      std::partition(nums + 1, nums + size, [pvalue = *nums](const int n) noexcept { return n > pvalue; }) - nums - 1;
  std::iter_swap(nums, nums + pindex);

  if (k - 1 == pindex) {
    return nums[pindex];
  } else if (k - 1 < pindex) {
    return FindKLargestImpl(nums, pindex, k);
  }
  return FindKLargestImpl(nums + pindex + 1, size - pindex - 1, k - pindex - 1);
}

}  // anonymous namespace

namespace algorithms {

int FindKLargest(std::vector<int> nums, const int k) {
  assert(k > 0);
  assert(static_cast<std::size_t>(k) <= nums.size());
  assert(!nums.empty());

  // Quickselect algorithm
  return ::FindKLargestImpl(nums.data(), nums.size(), k);
}

}  // namespace algorithms
