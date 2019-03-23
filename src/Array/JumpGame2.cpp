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
#include <algorithms/Array/JumpGame2.hpp>
#include <cassert>
#include <vector>

namespace algorithms {

int JumpGame2(const std::vector<int>& iNumbers) {
  const int kSize = static_cast<int>(iNumbers.size());
  const int kSizeMinusOne = kSize - 1;
  int numHop = 0;
  int currentIndex = 0;

  while (currentIndex < kSizeMinusOne) {
    assert(iNumbers[currentIndex] > 0);
    const int kPossibleChoices =
        std::min(iNumbers[currentIndex], kSizeMinusOne - currentIndex);

    if (currentIndex + kPossibleChoices < kSizeMinusOne) {
      int maxValue = 0;
      int maxIndex = -1;
      for (int i = 1; i < kPossibleChoices + 1; ++i) {
        const auto kValueJump = iNumbers[currentIndex + i] + i;
        if (maxValue < kValueJump) {
          maxValue = kValueJump;
          maxIndex = i;
        }
      }
      assert(maxIndex != -1);

      currentIndex += maxIndex;
    } else {
      currentIndex = kSizeMinusOne;
    }
    ++numHop;
  }  // while

  return numHop;
}

}  // namespace algorithms
