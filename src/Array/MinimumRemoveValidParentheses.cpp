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
#include <algorithm>
#include <algorithms/Array/MinimumRemoveValidParentheses.hpp>
#include <string>
#include <vector>

namespace algorithms {

std::string MinimumRemoveValidParentheses(const std::string& str) {
  static constexpr char kSpecialChar = '*';
  std::string ans = str;

  std::for_each(ans.begin(), ans.end(), [counter = 0](char& c) mutable {
    if (c == '(') {
      ++counter;
    } else if (c == ')') {
      if (counter == 0) {
        c = kSpecialChar;
      } else {
        --counter;
      }
    }
  });

  std::for_each(ans.rbegin(), ans.rend(), [counter = 0](char& c) mutable {
    if (c == ')') {
      ++counter;
    } else if (c == '(') {
      if (counter == 0) {
        c = kSpecialChar;
      } else {
        --counter;
      }
    }
  });

  ans.erase(std::remove(ans.begin(), ans.end(), kSpecialChar), ans.end());

  return ans;
}

}  // namespace algorithms
