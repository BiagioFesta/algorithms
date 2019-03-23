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
#include <algorithms/Array/Find132Pattern.hpp>
#include <limits>
#include <stack>
#include <vector>

namespace algorithms {

bool Find132pattern(const std::vector<int>& iVector) {
  std::stack<int> aStack;
  int aS0 = std::numeric_limits<int>::min();

  for (auto it = iVector.crbegin(); it != iVector.crend(); ++it) {
    const int aNumber = *it;
    if (aNumber < aS0) return true;

    while (!aStack.empty() && aStack.top() < aNumber) {
      aS0 = aStack.top();
      aStack.pop();
    }
    aStack.push(aNumber);
  }

  return false;
}

}  // namespace algorithms
