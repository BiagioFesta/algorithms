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
#include <algorithms/Array/CountSmallerAfterSelf.hpp>
#include <algorithms/BinaryIndexedTree/BinaryIndexedTree.hpp>
#include <utility>
#include <vector>

namespace algorithms {

std::vector<int> CountSmallerAfterSelf(const std::vector<int>& nums) {
  const std::size_t size = nums.size();

  std::vector<std::pair<int, std::size_t>> metaSort;
  metaSort.reserve(size);
  for (std::size_t i = 0; i < size; ++i) {  // O(N)
    metaSort.emplace_back(nums[i], i);      // O(1)
  }
  std::sort(metaSort.begin(), metaSort.end());  // O(NlogN)

  std::vector<std::size_t> imap(size);
  for (std::size_t i = 0; i < size; ++i) {  // O(N)
    imap[metaSort[i].second] = i;           // O(1)
  }

  BinaryIndexedTree<> bit(size);
  std::vector<int> ans(size);
  std::size_t ri;

  for (std::size_t i = 0; i < size; ++i) {  // O(N)
    ri = size - i - 1;
    ans[ri] = bit.sum(imap[ri]);  // O(logN)
    bit.update(imap[ri], 1);      // O(logN)
  }

  return ans;
}

}  // namespace algorithms
