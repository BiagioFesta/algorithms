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
#include <algorithms/String/DecodeString.hpp>
#include <cassert>
#include <string>

namespace algorithms {

std::string DecodeString(const std::string& encStr) {
  std::string decStr;
  std::size_t index = 0;

  while (index < encStr.size()) {
    const char c = encStr[index];
    if (c >= '0' && c <= '9') {
      const std::size_t openBkIndex = encStr.find('[', index);
      assert(openBkIndex != std::string::npos);
      const int rep = std::stoi(encStr.substr(index, openBkIndex - index));
      index = openBkIndex + 1;
      for (std::size_t bkCount = 1; bkCount; ++index) {
        const char p = encStr[index];
        if (p == '[') {
          ++bkCount;
        } else if (p == ']') {
          --bkCount;
        }
      }
      const auto innerDecoded = DecodeString(encStr.substr(openBkIndex + 1, index - openBkIndex - 2));
      for (int i = 0; i < rep; ++i) {
        decStr += innerDecoded;
      }
    } else {
      decStr += c;
      ++index;
    }
  }

  return decStr;
}

}  // namespace algorithms
