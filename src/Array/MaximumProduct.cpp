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
#include <algorithms/Array/MaximumProduct.hpp>
#include <cassert>
#include <functional>
#include <numeric>
#include <vector>

namespace algorithms {

int MaximumProduct(const std::vector<int>& iVector) {
  constexpr std::size_t kMaxSizeMin = 2;
  constexpr std::size_t kMaxSizeMax = 3;
  assert(iVector.size() > 0);

  if (iVector.size() <= 3) {
    return std::accumulate(iVector.cbegin(), iVector.cend(), 1, std::multiplies<int>{});
  }

  std::vector<int> aLower;
  aLower.reserve(kMaxSizeMin);
  std::vector<int> aUpper;
  aUpper.reserve(kMaxSizeMax);

  for (const int aNum : iVector) {
    aLower.push_back(aNum);
    std::sort(aLower.begin(), aLower.end(), std::less<int>{});
    if (aLower.size() > kMaxSizeMin) {
      aLower.pop_back();
    }

    aUpper.push_back(aNum);
    std::sort(aUpper.begin(), aUpper.end(), std::greater<int>{});
    if (aUpper.size() > kMaxSizeMax) {
      aUpper.pop_back();
    }
  }
  assert(aLower.size() == kMaxSizeMin);
  assert(aUpper.size() == kMaxSizeMax);

  const int aCase1 = aLower[0] * aLower[1] * aUpper[0];
  const int aCase2 = aUpper[0] * aUpper[1] * aUpper[2];

  return std::max(aCase1, aCase2);
}

}  // namespace algorithms
