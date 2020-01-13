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
#include <algorithms/Array/DailyTemperatures.hpp>
#include <stack>
#include <vector>

namespace algorithms {

std::vector<int> DailyTemperatures(const std::vector<int>& temps) {
  const std::size_t size = temps.size();

  std::size_t i = 0;
  std::vector<int> ans(size, 0);
  std::stack<int> stack;

  while (i < size) {
    while (!stack.empty() && temps[stack.top()] < temps[i]) {
      ans[stack.top()] = i - stack.top();
      stack.pop();
    }
    stack.push(i);
    ++i;
  }

  return ans;
}

}  // namespace algorithms
