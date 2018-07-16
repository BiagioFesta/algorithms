/*
          Copyright (C) 2018  Biagio Festa

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
#include "AlgArrays.hpp"
#include <cassert>
#include <limits>
#include <vector>

namespace algorithms {

bool isAlmostNonDecreasing(const int* iArray, const int iSize) {
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

int minSizeSubArraySum(const int* iArray, const int iSize, int s) {
  assert(s > 0);
  int min = std::numeric_limits<int>::max();
  int sum = 0;
  int i = 0;
  int j = 0;

  for (; j < iSize; ++j) {
    sum += iArray[j];
    if (sum >= s) {
      min = std::min(min, j + 1 - i);
    }

    while (i < j && sum - iArray[i] >= s) {
      sum -= iArray[i];
      ++i;
      min = std::min(min, j + 1 - i);
    }
  }

  return min == std::numeric_limits<int>::max() ? 0 : min;
}

std::vector<int> findDisappearedNumbers(const std::vector<int>& iVector) {
  std::vector<bool> table(iVector.size(), false);
  for (const int n : iVector) {
    assert(n <= iVector.size());
    assert(n >= 1);

    table[n - 1] = true;
  }

  std::vector<int> missing;
  missing.reserve(iVector.size());
  for (int i = 0; i < iVector.size(); ++i) {
    if (table[i] == false) missing.push_back(i + 1);
  }

  return missing;
}

int findLengthOfLCIS(const std::vector<int>& iVector) {
  if (iVector.empty()) return 0;

  int counter = 1;
  int max = 1;
  for (int i = 1; i < iVector.size(); ++i) {
    if (iVector[i - 1] < iVector[i]) {
      ++counter;
    } else {
      max = std::max(max, counter);
      counter = 1;
    }
  }

  return std::max(max, counter);
}

}  // namespace algorithms
