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
#include <cassert>
#include <forward_list>

namespace algorithms {

int KthToLast(const std::forward_list<int>& iList, int k) {
  int size = 0;
  for (auto it = iList.cbegin(); it != iList.cend(); ++it) {
    ++size;
  }

  int index = size - k - 1;
  assert(index >= 0 && index <= size);

  auto iterator = iList.cbegin();
  while (index > 0) {
    --index;
    ++iterator;
  }

  return *iterator;
}

}  // namespace algorithms
