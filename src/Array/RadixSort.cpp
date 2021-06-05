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
#include <algorithms/Array/RadixSort.hpp>
#include <array>
#include <cassert>
#include <utility>
#include <vector>

namespace algorithms {

void RadixSort(std::vector<unsigned int>* ioVector) {
  constexpr std::size_t kBytesPartition = 1;
  constexpr std::size_t kBitsPartition = kBytesPartition * 8;
  constexpr std::size_t kNumPartitions = sizeof(unsigned int) / kBytesPartition;
  constexpr std::size_t kSizeBucket = 1 << kBitsPartition;
  constexpr std::size_t kBaseMask = kSizeBucket - 1;

  static_assert(sizeof(unsigned int) % kBytesPartition == 0, "Cannot Paritioning uniform");
  static_assert(kBytesPartition <= sizeof(std::size_t), "Partition size too big");

  std::array<std::size_t, kSizeBucket> aBucket;
  std::vector<unsigned int> aPartialSort;
  aPartialSort.resize(ioVector->size());

  for (std::size_t p = 0; p < kNumPartitions; ++p) {
    const std::size_t kMask = kBaseMask << (p * kBitsPartition);
    std::fill(aBucket.begin(), aBucket.end(), 0);

    for (const auto iNumber : *ioVector) {
      const std::size_t kIndex = (iNumber & kMask) >> (p * kBitsPartition);
      assert(kIndex < aBucket.size());

      ++aBucket[kIndex];
    }

    for (std::size_t i = 1; i < aBucket.size(); ++i) {
      aBucket[i] += aBucket[i - 1];
    }

    for (auto it = ioVector->crbegin(); it != ioVector->crend(); ++it) {
      const auto kValue = *it;
      const std::size_t kIndexBucket = (kValue & kMask) >> (p * kBitsPartition);
      assert(kIndexBucket < aBucket.size());

      const std::size_t kIndexVect = --aBucket[kIndexBucket];
      assert(kIndexVect < aPartialSort.size());

      aPartialSort[kIndexVect] = kValue;
    }

    std::swap(*ioVector, aPartialSort);
  }
}

}  // namespace algorithms
