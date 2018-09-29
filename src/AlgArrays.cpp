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
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
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

bool larrysArray(const std::vector<int>& iVector) {
  const int kSize = iVector.size();
  std::vector<bool> visitedTable(kSize, false);

  // Info: aCountSwap will count the number of swaps needed to sort the array
  // with Intersion Sort.
  int aCountSwap = 0;
  for (int i = 0; i < kSize; ++i) {
    int aSwapForCurrent = 0;
    int j = i;
    while (!visitedTable[iVector[j] - 1]) {
      visitedTable[iVector[j] - 1] = true;
      ++aSwapForCurrent;
      j = iVector[j] - 1;
    }
    aCountSwap += aSwapForCurrent ? aSwapForCurrent - 1 : 0;
  }
  return !(aCountSwap % 2);
}

std::vector<int> absolutePermutation(const int n, const int k) {
  std::vector<bool> usedTable(n, false);
  std::vector<int> absPerm;
  absPerm.resize(n);

  for (int i = 0; i < n; ++i) {
    const int aNumber = i + 1;
    if (const int aNegValue = aNumber - k;
        aNegValue > 0 && usedTable[aNegValue - 1] == false) {
      absPerm[i] = aNegValue;
      usedTable[aNegValue - 1] = true;
    } else if (const int aPosValue = aNumber + k;
               aPosValue <= n && usedTable[aPosValue - 1] == false) {
      absPerm[i] = aPosValue;
      usedTable[aPosValue - 1] = true;
    } else {
      return {-1};
    }
  }

  return absPerm;
}

std::vector<int> addOneToNumber(const std::vector<int>& iDigits) {
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

std::string largestNumber(std::vector<int> iNumbers) {
  std::sort(iNumbers.begin(), iNumbers.end(), [](const int x, const int y) {
    static std::string sComposition;

    sComposition.clear();
    sComposition += std::to_string(x);
    sComposition += std::to_string(y);
    const int xy = std::stoi(sComposition);

    sComposition.clear();
    sComposition += std::to_string(y);
    sComposition += std::to_string(x);
    const int yx = std::stoi(sComposition);

    return xy >= yx;
  });

  const auto aFirstNonZero = std::find_if(
      iNumbers.begin(), iNumbers.end() - 1, [](const int n) { return n != 0; });
  if (aFirstNonZero != iNumbers.begin()) {
    iNumbers.erase(iNumbers.begin(), aFirstNonZero);
  }

  std::string aRtn;
  for (const int n : iNumbers) {
    aRtn += std::to_string(n);
  }

  return aRtn;
}

int maximumGap(const std::vector<int>& iVector) {
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

bool isOneBitCharacter(const std::vector<int>& iBits) {
  const int kSize = iBits.size();
  if (kSize == 1) return true;

  const int kSizeMinusOne = kSize - 1;

  int i = 0;
  while (i < kSizeMinusOne) {
    i += iBits[i] == 1 ? 2 : 1;
  }

  return i == kSizeMinusOne;
}

int findMaxLength(const std::vector<int>& iBits) {
  const int kSize = iBits.size();

  std::unordered_map<int, int> diff2index;
  int diff = 0;
  int max = 0;

  for (int i = 0; i < kSize; ++i) {
    diff += iBits[i] ? 1 : -1;
    if (diff == 0) {
      max = i + 1;
    } else if (auto startIt = diff2index.find(diff);
               startIt != diff2index.cend()) {
      max = std::max(max, i - startIt->second);
    } else {
      diff2index[diff] = i;
    }
  }

  return max;
}

int pairs(std::vector<int> iNums, int iTarget) {
  const int kSize = iNums.size();  // O(1)

  std::sort(iNums.begin(), iNums.end());  // O(NlogN)

  int counter = 0;                              // O(1)
  for (int i = 0; i < kSize; ++i) {             // O(N)
    const int targetPair = iNums[i] - iTarget;  // O(1)
    if (std::binary_search(
            iNums.cbegin(), iNums.cend(), targetPair)) {  // O(logN)
      ++counter;                                          // O(1)
    }
  }

  return counter;  // O(1)
}

bool containsNearbyDuplicate(const std::vector<int>& iNums, const int k) {
  const int kSize = iNums.size();
  if (kSize == 0 || kSize == 1 || k == 0) return false;

  std::unordered_set<int> hashTable;
  hashTable.insert(iNums[0]);

  int i = 0;
  int j = 1;
  while (j < iNums.size()) {  // O(N)
    const int jValue = iNums[j];
    if (hashTable.count(jValue)) return true;  // O(1)
    hashTable.insert(jValue);                  // O(1)
    ++j;
    if (j - i > k) {
      hashTable.erase(iNums[i]);  // O(1)
      ++i;
    }
  }

  return false;
}

bool isPermutation(const std::vector<int>& iVectA,
                   const std::vector<int>& iVectB) {
  if (iVectA.size() != iVectB.size()) return false;

  std::unordered_map<int, int> aOccTable;
  for (const int aNumber : iVectA) {
    aOccTable[aNumber] += 1;
  }

  for (const int aNumber : iVectB) {
    const int aOccRemain = --aOccTable[aNumber];
    if (aOccRemain < 0) {
      return false;
    }
    if (aOccRemain == 0) {
      aOccTable.erase(aNumber);
    }
  }

  return aOccTable.empty();
}

int stockMax(const std::vector<int>& iPrices) {
  const int kSize = iPrices.size();
  if (kSize == 0) return 0;

  int aMaxLocal = 0;
  int aRevenue = 0;

  for (int i = kSize - 1; i >= 0; --i) {
    const int aPriceI = iPrices[i];
    assert(aPriceI > 0);

    aMaxLocal = std::max(aMaxLocal, aPriceI);
    aRevenue += aMaxLocal - aPriceI;
  }

  return aRevenue;
}

}  // namespace algorithms
