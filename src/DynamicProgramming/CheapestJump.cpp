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
#include <algorithms/DynamicProgramming/CheapestJump.hpp>
#include <cassert>
#include <utility>
#include <vector>

namespace algorithms {

std::vector<int> CheapestJump(const std::vector<int>& iVector, const int iMaxJump) {
  assert(iMaxJump >= 0);
  assert(!iVector.empty());

  const int kSize = iVector.size();

  std::vector<std::pair<int, int>> aTableSolutions(kSize, {0, -1});

  for (int i = kSize - 2; i >= 0; --i) {
    auto& [aCostFromI, aIndexFromI] = aTableSolutions[i];

    const int kUpperBound = std::min(i + iMaxJump + 1, kSize);
    for (int k = i + 1; k < kUpperBound; ++k) {
      const int aKValue = iVector[k];

      if (aKValue >= 0) {
        const int aSolutionK = aKValue + aTableSolutions[k].first;
        if (aIndexFromI == -1 || aSolutionK < aCostFromI) {
          aIndexFromI = k;
          aCostFromI = aSolutionK;
        }
      }
    }
  }

  std::vector<int> aPath;
  aPath.reserve(kSize);

  int aIndex = 0;
  while (aTableSolutions[aIndex].second != -1) {
    aPath.push_back(aIndex + 1);
    aIndex = aTableSolutions[aIndex].second;
  }
  aPath.push_back(aIndex + 1);

  if (aPath.back() != kSize) {
    aPath.clear();
  }

  return aPath;
}

}  // namespace algorithms
