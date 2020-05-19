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
#include <algorithms/String/ValidPalindrome.hpp>
#include <cctype>
#include <string>

namespace algorithms {

bool ValidPalindrome(const std::string& str) {
  int i = 0, j = static_cast<int>(str.size()) - 1;

  while (i < j) {
    if (!std::isalnum(str[i])) {
      ++i;
    } else if (!std::isalnum(str[j])) {
      --j;
    } else if (std::tolower(str[i]) != std::tolower(str[j])) {
      return false;
    } else {
      ++i;
      --j;
    }
  }

  return true;
}

}  // namespace algorithms
