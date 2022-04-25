/*
  Copyright (C) 2022  Biagio Festa

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
#include <algorithms/Array/GlobalLocalInversions.hpp>
#include <cassert>
#include <cstdlib>
#include <numeric>
#include <vector>

namespace {

bool isValidVector(const std::vector<int>& iVector) {
  std::vector<int> aNaturalSequence(iVector.size());
  std::iota(aNaturalSequence.begin(), aNaturalSequence.end(), 0);

  return std::is_permutation(iVector.cbegin(), iVector.cend(), aNaturalSequence.cbegin());
}

}  // anonymous namespace

namespace algorithms {

bool GlobalLocalInversions(const std::vector<int>& iVector) {
  assert(isValidVector(iVector));

  const int kSize = static_cast<int>(iVector.size());
  for (int i = 0; i < kSize; ++i) {
    assert(iVector[i] >= 0 && iVector[i] < kSize);

    const int diff = std::abs(i - iVector[i]);
    if (diff > 1) return false;
  }
  return true;
}

}  // namespace algorithms
