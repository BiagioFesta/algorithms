/*
  Copyright (C) 2020  Biagio Festa

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
#include <algorithms/String/MaxLenSubWithoutRep.hpp>
#include <cstring>
#include <string>

namespace algorithms {

int MaxLenSubWithoutRep(const std::string& iString) {
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

}  // namespace algorithms
