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
#include <algorithms/String/LongestPalindrome.hpp>
#include <cassert>
#include <string>

namespace algorithms {

std::string LongestPalindrome(const std::string& iString) {
  const int kSize = iString.size();

  std::string aResult;
  int i, j;

  for (int c = 0; c < kSize; ++c) {
    i = c;
    j = c + 1;
    while (i >= 0 && j < kSize && iString[i] == iString[j]) {
      const int kLen = j + 1 - i;
      const int kResultSize = static_cast<int>(aResult.size());
      if (kLen > kResultSize) {
        aResult = iString.substr(i, kLen);
      }
      --i;
      ++j;
    }

    i = c;
    j = c;
    while (i >= 0 && j < kSize && iString[i] == iString[j]) {
      const int kLen = j + 1 - i;
      const int kResultSize = static_cast<int>(aResult.size());
      if (kLen > kResultSize) {
        aResult = iString.substr(i, kLen);
      }
      --i;
      ++j;
    }
  }

  assert(iString.empty() || !aResult.empty());
  return aResult;
}

}  // namespace algorithms
