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
#include <algorithms/String/StrStr.hpp>
#include <string>

namespace algorithms {

int StrStr(const std::string& iStr, const std::string& iFinder) {
  const int kSizeFinder = iFinder.size();
  if (kSizeFinder == 0) return 0;
  const int kSizeStr = iStr.size();

  int j;
  for (int i = 0; i < kSizeStr; ++i) {
    j = 0;
    while ((j < kSizeFinder) && (i + j < kSizeStr) && (iStr[i + j] == iFinder[j])) {
      ++j;
    }
    if (j == kSizeFinder) return i;
  }

  return -1;
}

}  // namespace algorithms
