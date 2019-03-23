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
#include <algorithms/Array/NonDecreasingArray.hpp>

namespace algorithms {

bool NonDecreasingArray(const int* iArray, const int iSize) {
  // Complexity Time: O(N + N) = O(2N) ---> O(N)
  // It can be done in O(N) (witout x2) if iArray can be modified.
  if (iSize == 0) return true;

  bool modDone = false;
  int prevValue = iArray[0];
  bool aError = false;

  for (int i = 1; i < iSize && aError == false; ++i) {
    if (iArray[i] < prevValue) {
      if (modDone == true) {
        aError = true;
      } else {
        modDone = true;
        prevValue = iArray[i - 1];
      }
    } else {
      prevValue = iArray[i];
    }
  }

  if (aError) {
    prevValue = iArray[iSize - 1];
    modDone = false;

    for (int i = iSize - 2; i >= 0; --i) {
      if (iArray[i] > prevValue) {
        if (modDone == true) return false;
        modDone = true;
        prevValue = iArray[i + 1];
      } else {
        prevValue = iArray[i];
      }
    }
  }

  return true;
}

}  // namespace algorithms
