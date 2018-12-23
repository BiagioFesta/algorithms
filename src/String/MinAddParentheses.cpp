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
#include <algorithms/String/MinAddParentheses.hpp>
#include <cassert>
#include <stack>
#include <string>

namespace algorithms {

int MinAddParentheses(const std::string& iString) {
  constexpr char kOpenSymbol = '(';
  constexpr char kCloseSymbol = ')';
  std::stack<bool> stack;

  for (const char c : iString) {
    assert(c == kOpenSymbol || c == kCloseSymbol);
    if (c == kOpenSymbol) {
      stack.push(false);
    } else {
      if ((!stack.empty()) && (!stack.top())) {
        stack.pop();
      } else {
        stack.push(true);
      }
    }
  }

  return static_cast<int>(stack.size());
}

}  // namespace algorithms
