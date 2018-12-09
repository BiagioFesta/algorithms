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
#include <algorithms/String/FindLongestWord.hpp>
#include <string>
#include <vector>

namespace algorithms {

int FindLongestWord(const std::string& iString,
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

}  // namespace algorithms
