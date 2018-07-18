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
#include <locale>
#include <string>

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
    isOdd[*iStr] ^= 0X1;
    ++iStr;
  }

  return std::count(isOdd, isOdd + kTableSize, true) <= 1;
}

bool oneWay(const std::string& iStr1, const std::string& iStr2) {
  bool aEdit = false;

  if (int diff = iStr1.size() - iStr2.size(); std::abs(diff) > 1) {
    return false;
  }

  int i = 0;
  int j = 0;

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
        if (bytesWritten + interBuffer.size() <= iSizeBuffer) {
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

  for (int j = 0; j < iString.size(); ++j) {
    const char c = iString[j];
    int& posOfc = posChar[c];

    if ((posOfc < 0) || (posOfc < j - aCurrent)) {
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

}  // namespace algorithms
