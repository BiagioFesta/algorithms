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
#include <algorithm>
#include <algorithms/Array/PlusOne.hpp>
#include <cassert>
#include <vector>

namespace algorithms {

std::vector<int> PlusOne(const std::vector<int>& iDigits) {
  const int kSize = iDigits.size();

  std::vector<int> aPlusOne;
  aPlusOne.reserve(kSize + 1);

  bool aCarry = true;
  int aDigit;

  for (int i = 0; i < kSize; ++i) {
    aDigit = iDigits[kSize - i - 1];
    assert(aDigit >= 0 && aDigit <= 9);

    if (aCarry) {
      ++aDigit;
      aCarry = false;
    }

    if (aDigit > 9) {
      aDigit = 0;
      aCarry = true;
    }

    aPlusOne.push_back(aDigit);
  }

  if (aCarry) {
    aPlusOne.push_back(1);
  }

  std::reverse(aPlusOne.begin(), aPlusOne.end());

  const auto aNonZeroIt = std::find_if(
      aPlusOne.cbegin(), aPlusOne.cend(), [](const int n) { return n != 0; });
  if (aNonZeroIt != aPlusOne.cbegin()) {
    aPlusOne.erase(aPlusOne.begin(), aNonZeroIt);
  }

  return aPlusOne;
}

}  // namespace algorithms
