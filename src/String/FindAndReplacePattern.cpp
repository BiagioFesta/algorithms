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
#include <algorithm>
#include <algorithms/String/FindAndReplacePattern.hpp>
#include <array>
#include <cstring>
#include <string>
#include <vector>

namespace algorithms {

std::vector<std::string> FindAndReplacePattern(
    const std::vector<std::string>& iWords,
    const std::string& iPattern) {
  constexpr std::size_t kSizeTable = 1 << 8;

  std::vector<std::string> aMatchedWords;

  std::array<char, kSizeTable> aLeft2RightTable;
  std::array<char, kSizeTable> aRight2LeftTable;

  std::copy_if(
      iWords.cbegin(),
      iWords.cend(),
      std::back_inserter(aMatchedWords),
      [&iPattern,
       &aLeft2RightTable,
       &aRight2LeftTable,
       kSizePattern = iPattern.size()](const std::string& iWord) {
        const auto kSizeWord = iWord.size();
        if (kSizePattern != kSizeWord) return false;

        std::memset(aLeft2RightTable.data(), 0, aLeft2RightTable.size());
        std::memset(aRight2LeftTable.data(), 0, aRight2LeftTable.size());

        for (std::size_t i = 0u; i < kSizeWord; ++i) {
          const char w = iWord[i];
          const char p = iPattern[i];
          char& aRefLeftTable = aLeft2RightTable[w];
          char& aRefRightTable = aRight2LeftTable[p];

          if (aRefLeftTable && aRefLeftTable != p) {
            return false;
          } else {
            aRefLeftTable = p;
          }

          if (aRefRightTable && aRefRightTable != w) {
            return false;
          } else {
            aRefRightTable = w;
          }
        }

        return true;
      });

  return aMatchedWords;
}

}  // namespace algorithms
