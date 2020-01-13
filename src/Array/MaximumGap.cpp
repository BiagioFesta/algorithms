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
#include <algorithms/Array/MaximumGap.hpp>
#include <algorithm>
#include <utility>
#include <vector>

namespace algorithms {

int MaximumGap(const std::vector<int>& iVector) {
  using ValueType = int;
  using IndexType = int;

  const int kSize = iVector.size();
  if (kSize == 0) return -1;

  std::vector<std::pair<ValueType, IndexType>> metaVector;
  metaVector.reserve(kSize);
  for (int i = 0; i < kSize; ++i) {
    metaVector.push_back(std::make_pair(iVector[i], i));
  }

  std::sort(metaVector.begin(), metaVector.end());

  int maxIndex = metaVector[kSize - 1].second;
  int max = 0;

  for (int i = kSize - 2; i >= 0; --i) {
    const IndexType indexI = metaVector[i].second;
    max = std::max(max, maxIndex - indexI);
    maxIndex = std::max(maxIndex, indexI);
  }

  return max;
}

}  // namespace algorithms
