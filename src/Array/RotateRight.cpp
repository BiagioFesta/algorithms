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
#include <algorithms/Array/EuclideanAlgorithmGCD.hpp>
#include <algorithms/Array/RotateRight.hpp>
#include <cstdint>
#include <utility>
#include <vector>

namespace algorithms {

void RotateRight(std::vector<int>* ioVector, int k) {
  const std::int64_t kSize = ioVector->size();  // we assume size < INT64_MAX
  if (kSize > 0) {
    k %= kSize;
    if (k < 0) {
      k = kSize + k;
    }

    const int numPartitions = EuclideanAlgorithmGCD(kSize, k);
    const int numPermutations = kSize / numPartitions;

    int value, idx;
    for (int i = 0; i < numPartitions; ++i) {
      value = (*ioVector)[i];
      idx = i;

      for (int j = 0; j < numPermutations; ++j) {
        idx = (idx + k) % kSize;
        std::swap(value, (*ioVector)[idx]);
      }  // for j
    }    // for i
  }      // if kSize > 0
}

}  // namespace algorithms
