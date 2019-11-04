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
#include <algorithms/Array/DailyTemperatures.hpp>
#include <stack>
#include <utility>
#include <vector>

namespace algorithms {

std::vector<int> DailyTemperatures(const std::vector<int>& temps) {
  const std::size_t size = temps.size();

  std::size_t i = 0;
  std::vector<int> ans(size, 0);
  std::stack<std::pair<int, int>> stack;

  while (i < size) {  // O(N)
    while (!stack.empty() && stack.top().first < temps[i]) {
      ans[stack.top().second] = i - stack.top().second;
      stack.pop();
    }
    stack.emplace(temps[i], i);
    ++i;
  }

  return ans;
}

}  // namespace algorithms
