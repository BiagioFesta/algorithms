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
#include <algorithms/Array/MajorityElement.hpp>
#include <cassert>
#include <vector>

namespace {

bool IsThereMajorityElement(const std::vector<int>& nums) noexcept {
  const std::size_t size = nums.size();

  std::size_t counter;
  for (std::size_t i = 0; i < size; ++i) {
    counter = 0;
    for (std::size_t j = i + 1; j < size; ++j) {
      if (nums[j] == nums[i]) ++counter;
    }
    if (counter >= (size / 2)) {
      return true;
    }
  }
  return false;
}

}  // anonymous namespace

namespace algorithms {

int MajorityElement(const std::vector<int>& nums) {
  assert(::IsThereMajorityElement(nums));
  int candidate, counter = 0;

  for (const int n : nums) {
    if (counter == 0) {
      candidate = n;
    }
    counter += candidate == n ? 1 : -1;
  }

  return candidate;
}

}  // namespace algorithms
