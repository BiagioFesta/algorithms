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
#include <algorithms/Array/IsPalindrome.hpp>
#include <cmath>
#include <cstdint>

namespace algorithms {

bool IsPalindrome(int iNumber) {
  if (iNumber < 0) return false;
  if (iNumber < 10) return true;

  int aNumDigit = 1;
  int aTemp = iNumber;
  while (aTemp /= 10) {
    ++aNumDigit;
  }

  const int aHalfNumberOfDigit = aNumDigit / 2;

  for (int i = 0; i < aHalfNumberOfDigit; ++i) {
    const std::int64_t aPowerRight = std::pow(10, i + 1);
    const std::int64_t aPowerLeft = std::pow(10, aNumDigit - i);

    const int aDigitRight = iNumber % aPowerRight / (aPowerRight / 10);
    const int aDigitLeft = iNumber % aPowerLeft / (aPowerLeft / 10);

    if (aDigitRight != aDigitLeft) return false;
  }

  return true;
}

}  // namespace algorithms
