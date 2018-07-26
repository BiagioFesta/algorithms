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
#include <algorithm>
#include <cassert>
#include <limits>
#include <set>
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
    assert(n <= static_cast<int>(iVector.size()));
    assert(n >= 1);

    table[n - 1] = true;
  }

  std::vector<int> missing;
  missing.reserve(iVector.size());
  for (int i = 0; i < static_cast<int>(iVector.size()); ++i) {
    if (table[i] == false) missing.push_back(i + 1);
  }

  return missing;
}

int findLengthOfLCIS(const std::vector<int>& iVector) {
  if (iVector.empty()) return 0;

  int counter = 1;
  int max = 1;
  for (int i = 1; i < static_cast<int>(iVector.size()); ++i) {
    if (iVector[i - 1] < iVector[i]) {
      ++counter;
    } else {
      max = std::max(max, counter);
      counter = 1;
    }
  }

  return std::max(max, counter);
}

int firstMissingPositive(std::vector<int>* iVector) {
  const int n = iVector->size();

  for (int i = 0; i < n;) {
    int& value_i = (*iVector)[i];
    if (value_i > 0 && value_i <= n) {
      int& value_j = (*iVector)[value_i - 1];
      if (value_i != value_j) {
        std::swap(value_i, value_j);
      } else {
        ++i;
      }
    } else {
      ++i;
    }
  }

  for (int i = 0; i < n; ++i) {
    if ((*iVector)[i] != i + 1) {
      return i + 1;
    }
  }

  return n + 1;
}

std::vector<int> climbingLeaderboard(const std::vector<int>& iLeaderBoard,
                                     const std::vector<int>& iAliceScores) {
  const std::set<int> aLeaderBoardTree(iLeaderBoard.cbegin(),
                                       iLeaderBoard.cend());
  const std::vector<int> aLeaderBoardPurged(aLeaderBoardTree.cbegin(),
                                            aLeaderBoardTree.cend());
  const int aPosTotal = aLeaderBoardPurged.size();

  std::vector<int> aPositions;
  aPositions.reserve(iAliceScores.size());

  for (const int aGameScore : iAliceScores) {
    const auto aBoundIt = std::upper_bound(
        aLeaderBoardPurged.cbegin(), aLeaderBoardPurged.cend(), aGameScore);
    const auto aPos =
        aPosTotal + 1 - std::distance(aLeaderBoardPurged.cbegin(), aBoundIt);
    aPositions.push_back(aPos);
  }
  return aPositions;
}

}  // namespace algorithms
