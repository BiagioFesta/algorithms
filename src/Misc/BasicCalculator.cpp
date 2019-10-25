/*
  Copyright (C) 2019  Biagio Festa

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
#include <algorithms/Misc/BasicCalculator.hpp>
#include <stack>
#include <string>
#include <utility>

namespace algorithms {

int BasicCalculator(const std::string& s) {
  const std::size_t size = s.size();

  std::stack<std::pair<bool, int>> stack;
  char c;
  int num;
  bool sign = false;

  stack.emplace(false, 0);
  for (std::size_t i = 0; i < size; ++i) {
    c = s[i];
    if (c >= '0') {
      num = static_cast<int>(c - '0');
      while (s[i + 1] >= '0') {
        num = num * 10 + static_cast<int>(s[++i] - '0');
      }
      stack.top().second += sign ? -num : num;
    } else if (c == '-') {
      sign = true;
    } else if (c == '+') {
      sign = false;
    } else if (c == '(') {
      stack.emplace(sign, 0);
      sign = false;
    } else if (c == ')') {
      const auto [s, t] = stack.top();
      stack.pop();
      stack.top().second += s ? -t : t;
    }
  }

  return stack.top().second;
}

}  // namespace algorithms
