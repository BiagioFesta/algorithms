/*
  Copyright (C) 2021  Biagio Festa

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
#include <algorithms/String/OneWay.hpp>
#include <string>

namespace algorithms {

bool OneWay(const std::string& iStr1, const std::string& iStr2) {
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

}  // namespace algorithms
