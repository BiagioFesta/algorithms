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
#include <algorithms/DynamicProgramming/TargetSum.hpp>
#include <cassert>
#include <numeric>
#include <vector>

namespace {

constexpr std::size_t kMaxSum = 1000;
constexpr std::size_t kMaxLen = 20;
constexpr std::size_t kCol = (::kMaxSum + 1) * 2;

void ValidateInput(const std::vector<int>& nums) {
  assert(nums.size() <= ::kMaxLen);
  assert(std::none_of(
      nums.cbegin(), nums.cend(), [](const int num) noexcept {
        return num < 0;
      }));
  assert(std::accumulate(nums.cbegin(), nums.cend(), 0ull) <= ::kMaxSum);
}

int TargetSumImpl(const std::vector<int>& nums,
                  const std::size_t i,
                  const int S,
                  std::vector<int>* caches) {
  if (static_cast<std::size_t>(std::abs(S)) > ::kMaxSum) {
    return 0;
  }

  if (i >= nums.size()) {
    return S == 0 ? 1 : 0;
  }

  const std::size_t index = i * ::kCol + kMaxSum + S;
  assert(index < caches->size());
  int& result = (*caches)[index];
  if (result < 0) {
    result = ::TargetSumImpl(nums, i + 1, S + nums[i], caches) +
             ::TargetSumImpl(nums, i + 1, S - nums[i], caches);
  }
  return result;
}

}  // anonymous namespace

namespace algorithms {

int TargetSum(const std::vector<int>& nums, const int S) {
  ::ValidateInput(nums);

  std::vector<int> caches(::kMaxLen * ::kCol, -1);
  return ::TargetSumImpl(nums, 0, S, &caches);
}

}  // namespace algorithms
