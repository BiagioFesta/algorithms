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
#include <algorithms/Array/SingleElementInSortedArray.hpp>
#include <cassert>
#include <vector>

namespace {

int SingleElementInSortedArrayImpl(const int* const data,
                                   const std::size_t size) noexcept {
  if (size == 1ull) return *data;

  int middle = size / 2;
  if (middle % 2) {
    ++middle;
  }
  return data[middle] == data[middle - 1]
             ? SingleElementInSortedArrayImpl(data, middle - 1)
             : SingleElementInSortedArrayImpl(data + middle, size - middle);
}

}  // anonymous namespace

namespace algorithms {

int SingleElementInSortedArray(const std::vector<int>& nums) {
  /*
     Note this implementation is using recursion However, the space complexity
     is anyway constant because this is a tail-recursion. The compiler is able
     to trivially transform the code in the iterative version.
   */
  assert(nums.size() % 2);
  return ::SingleElementInSortedArrayImpl(nums.data(), nums.size());
}

}  // namespace algorithms
