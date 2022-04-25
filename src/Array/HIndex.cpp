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
#include <algorithms/Array/HIndex.hpp>
#include <cassert>
#include <vector>

namespace algorithms {

int HIndex(std::vector<int>* iCitations) {
  assert(std::all_of(iCitations->cbegin(), iCitations->cend(), [](const int num) { return num >= 0; }));

  std::sort(iCitations->begin(), iCitations->end());

  int aIndexH = iCitations->size();

  while (aIndexH) {
    const auto ub = std::upper_bound(iCitations->cbegin(), iCitations->cend(), aIndexH);
    const auto lb = std::lower_bound(iCitations->cbegin(), iCitations->cend(), aIndexH);
    const auto maxH = std::distance(lb, iCitations->cend());
    const auto minH = std::min(maxH, std::distance(ub, iCitations->cend()));

    if (minH <= aIndexH && aIndexH <= maxH) return aIndexH;
    --aIndexH;
  }

  return aIndexH;
}

int HIndexLinear(const std::vector<int>& iCitations) {
  const int kSize = iCitations.size();

  std::vector<int> freq(kSize + 1);
  for (int cit : iCitations) {
    assert(cit >= 0);
    cit = std::min(kSize, cit);
    ++freq[cit];
  }

  int aCounter = 0;
  for (int i = kSize; i > 0; --i) {
    aCounter += freq[i];

    if (i <= aCounter) {
      return i;
    }
  }

  return 0;
}

}  // namespace algorithms
