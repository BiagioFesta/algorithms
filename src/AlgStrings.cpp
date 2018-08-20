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
#include "AlgStrings.hpp"
#include <algorithm>
#include <cassert>
#include <cmath>
#include <locale>
#include <map>
#include <string>
#include <utility>
#include <vector>

namespace algorithms {

bool isPermutation(const char* iStr1, const char* iStr2) {
  constexpr int kLenTable = 2 << 8;

  int aTable[kLenTable];
  int aLen1 = 0;
  int aLen2 = 0;

  std::memset(aTable, 0, kLenTable * sizeof(int));

  while (*iStr1 != '\0') {
    aTable[static_cast<int>(*iStr1)] += 1;
    ++iStr1;
    ++aLen1;
  }

  while (*iStr2 != '\0') {
    int& aOccurrence = aTable[static_cast<int>(*iStr2)];
    if (aOccurrence == 0) return false;
    --aOccurrence;
    ++iStr2;
    ++aLen2;
  }

  if (aLen1 != aLen2) return false;

  return true;
}

void URLify(char* iStr, int iLenString) {
  constexpr char kReplacer[] = "%20";
  constexpr int kNoShift = sizeof(kReplacer) - 2;
  constexpr char kToReplace = ' ';

  for (int i = 0; i < iLenString; ++i) {
    if (iStr[i] == kToReplace) {
      // Shift for space
      for (int j = iLenString - 1; j > i; --j) {
        iStr[j + kNoShift] = iStr[j];
      }
      iLenString += kNoShift;

      std::memcpy(iStr + i, kReplacer, sizeof(kReplacer) - 1);
    }
  }
}

bool palindromePermutation(const char* iStr) {
  static constexpr int kTableSize = 2 << 8;

  bool isOdd[kTableSize];
  std::memset(isOdd, 0, kTableSize);

  while (*iStr != '\0') {
    isOdd[static_cast<int>(*iStr)] ^= 0X1;
    ++iStr;
  }

  return std::count(isOdd, isOdd + kTableSize, true) <= 1;
}

bool oneWay(const std::string& iStr1, const std::string& iStr2) {
  bool aEdit = false;

  if (int diff = iStr1.size() - iStr2.size(); std::abs(diff) > 1) {
    return false;
  }

  std::size_t i = 0u;
  std::size_t j = 0u;

  while (i < iStr1.size() && j < iStr2.size()) {
    if (iStr1[i] != iStr2[j]) {
      if (aEdit == true) return false;

      aEdit = true;
      if (iStr1.size() > iStr2.size()) {
        ++i;
      } else if (iStr2.size() > iStr1.size()) {
        ++j;
      } else {
        ++i;
        ++j;
      }
    } else {
      ++i;
      ++j;
    }
  }

  return true;
}

bool stringCompression(const char* iStr, char* oBuffer, const int iSizeBuffer) {
  int bytesWritten = 0;
  int numSame = 0;
  std::string interBuffer;

  while (*iStr != '\0') {
    if (bytesWritten + 1 >= iSizeBuffer) return false;

    if (*iStr == *(iStr + 1)) {
      ++numSame;
    } else {
      if (numSame) {
        interBuffer.clear();
        interBuffer += std::to_string(numSame + 1);
        interBuffer += *iStr;
        if (bytesWritten + static_cast<int>(interBuffer.size()) <=
            iSizeBuffer) {
          std::memcpy(oBuffer, interBuffer.data(), interBuffer.size());
          oBuffer += interBuffer.size();
          bytesWritten += interBuffer.size();
        } else {
          return false;
        }
        numSame = 0;
      } else {
        *oBuffer = *iStr;
        ++oBuffer;
        ++bytesWritten;
      }
    }

    ++iStr;
  }
  *oBuffer = '\0';

  return true;
}

int maxLenSubWithoutRep(const std::string& iString) {
  static constexpr int kNoChars = 1 << (sizeof(char) * 8);

  int posChar[kNoChars];
  std::memset(posChar, -1, sizeof(int) * kNoChars);

  int aMax = 0;
  int aCurrent = 0;

  for (std::size_t j = 0u; j < iString.size(); ++j) {
    const char c = iString[j];
    int& posOfc = posChar[static_cast<int>(c)];

    if ((posOfc < 0) || (static_cast<unsigned>(posOfc) < j - aCurrent)) {
      ++aCurrent;
    } else {
      aCurrent = j - posOfc;
    }

    posOfc = j;
    aMax = std::max(aCurrent, aMax);
  }

  return aMax;
}

int lenLastWord(const char* iStr) {
  bool space = false;
  int len = 0;

  for (int i = 0;; ++i) {
    const char c = iStr[i];
    if (c == '\0') return len;
    if (c == ' ') {
      space = true;
    } else {
      len = space == true ? 1 : len + 1;
      space = false;
    }
  }
}

int countSegment(const char* iStr) {
  std::locale aLocale;
  int count = 0;
  bool startSeg = false;

  while (*iStr != '\0') {
    const bool isSpace = std::isspace(*iStr, aLocale);

    if (isSpace && startSeg) {
      startSeg = false;
    } else if (!isSpace && !startSeg) {
      startSeg = true;
      ++count;
    }

    ++iStr;
  }

  return count;
}

void letterCasePermutation(const std::string& iStr,
                           std::vector<std::string>* oPermutations) {
  static const std::locale sLocale;
  static const auto permChar = [](const char c) {
    return std::islower(c, sLocale) ? std::toupper(c, sLocale)
                                    : std::tolower(c, sLocale);
  };

  oPermutations->clear();
  oPermutations->push_back(iStr);

  for (std::size_t i = 0u; i < iStr.size(); ++i) {
    if (std::isalpha(iStr[i], sLocale)) {
      const int s = oPermutations->size();
      for (int j = 0; j < s; ++j) {
        std::string newPerm = (*oPermutations)[j];
        newPerm[i] = permChar(newPerm[i]);
        oPermutations->push_back(std::move(newPerm));
      }
    }
  }
}

int steadyGene(const std::string& gene) {
  std::map<char, int> occ;
  const int size = gene.size();
  assert(size % 4 == 0);
  const int maxOcc = size / 4;

  int lb = -1;
  for (int i = 0; i < size && lb < 0; ++i) {
    const char c = gene[i];
    int& frequency = occ[c];
    if (frequency >= maxOcc) {
      lb = i;
    } else {
      ++frequency;
    }
  }

  if (lb == -1) return 0;

  int ub = -1;
  for (int j = size - 1; j >= 0 && ub < 0; --j) {
    const char c = gene[j];
    int& frequency = occ[c];
    if (frequency >= maxOcc) {
      ub = j;
    } else {
      ++frequency;
    }
  }

  int min = ub - lb + 1;
  for (int i = lb - 1; i >= 0; --i) {
    const char c = gene[i];
    int& frequency = occ[c];
    --frequency;

    while (occ[gene[ub]] < maxOcc) {
      ++occ[gene[ub]];
      --ub;
    }

    min = std::min(min, ub - i + 1);
  }

  return min;
}

std::string encryptionStr(const std::string& iString) {
  std::string aTrailedString;
  aTrailedString.reserve(iString.size());
  std::copy_if(iString.cbegin(),
               iString.cend(),
               std::back_inserter(aTrailedString),
               [](const char c) { return not std::isspace(c, std::locale()); });
  const int aNewLen = aTrailedString.size();
  const double aSqrt = std::sqrt(static_cast<double>(aNewLen));

  const int aFloor = static_cast<int>(std::floor(aSqrt));
  const int aCeil = static_cast<int>(std::ceil(aSqrt));

  int nRows = aCeil;
  int nCols = aCeil;
  if (aFloor * aFloor >= aNewLen) {
    nRows = aFloor;
    nCols = aFloor;
  } else if (aFloor * aCeil >= aNewLen) {
    nRows = aFloor;
  }
  assert(nRows * nCols >= aNewLen);

  std::string aRtn;
  aRtn.reserve(aNewLen);

  for (int j = 0; j < nCols; ++j) {
    for (int i = 0; i < nRows; ++i) {
      const int aIndex = i * nCols + j;
      if (aIndex < aNewLen) {
        aRtn.push_back(aTrailedString[aIndex]);
      }
    }
    aRtn.push_back(' ');
  }
  aRtn.pop_back();

  return aRtn;
}

std::string biggerIsGreater(std::string iString) {
  static const char* kNoAnswer = "no answer";

  const int kSize = iString.size();
  int aPivot = kSize - 1;
  while (aPivot > 0 && iString[aPivot - 1] >= iString[aPivot]) --aPivot;
  --aPivot;
  if (aPivot < 0) return kNoAnswer;

  int aSwap = kSize - 1;
  while (iString[aSwap] <= iString[aPivot]) --aSwap;

  std::swap(iString[aPivot], iString[aSwap]);
  std::reverse(iString.begin() + aPivot + 1, iString.end());
  return iString;
}

int findLongestWord(const std::string& iString,
                    const std::vector<std::string>& iStringDict) {
  const int kSizeStr = iString.size();      // N
  const int kSizeDic = iStringDict.size();  // M

  int indexMax = -1;
  int i, j, max;

  for (int m = 0; m < kSizeDic; ++m) {  // O(M)
    const auto& aMatcher = iStringDict[m];
    const int kSizeMatch = aMatcher.size();

    i = 0;
    j = 0;

    while (i < kSizeStr && j < kSizeMatch) {  // O(N + M)
      if (iString[i] == aMatcher[j]) ++j;
      ++i;
    }

    if (j == kSizeMatch) {
      if (indexMax < 0) {
        indexMax = m;
        max = kSizeMatch;
      } else if (kSizeMatch == max) {
        indexMax = aMatcher < iStringDict[indexMax] ? m : indexMax;  // O(N + M)
      } else if (max < kSizeMatch) {
        indexMax = m;
        max = kSizeMatch;
      }
    }
  }

  return indexMax;
}

bool detectCapitalUse(const std::string& iString) {
  const std::locale kLocale;
  const int kSize = iString.size();
  assert(kSize > 0);
  const int kCounterCapital =
      std::count_if(iString.cbegin(), iString.cend(), [&kLocale](const char c) {
        return std::isupper(c, kLocale);
      });

  if ((kCounterCapital == 0) || (kCounterCapital == kSize) ||
      (kCounterCapital == 1 && std::isupper(iString[0], kLocale))) {
    return true;
  }

  return false;
}

char findTheDifference(const std::string& iStringS,
                       const std::string& iStringT) {
  static constexpr int kSizeASCII = 1 << 8;

  int freqCounter[kSizeASCII]{};
  for (const char c : iStringS) {
    ++freqCounter[static_cast<int>(c)];
  }

  for (const char c : iStringT) {
    if (--freqCounter[static_cast<int>(c)] < 0) return c;
  }

  return static_cast<char>(0);
}

int strStr(const std::string& iStr, const std::string& iFinder) {
  const int kSizeFinder = iFinder.size();
  if (kSizeFinder == 0) return 0;
  const int kSizeStr = iStr.size();

  int j;
  for (int i = 0; i < kSizeStr; ++i) {
    j = 0;
    while ((j < kSizeFinder) && (i + j < kSizeStr) &&
           (iStr[i + j] == iFinder[j])) {
      ++j;
    }
    if (j == kSizeFinder) return i;
  }

  return -1;
}

}  // namespace algorithms
