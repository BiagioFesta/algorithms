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
#include <vector>
#include <unordered_set>
#include <stack>
#include <cassert>

namespace algorithms {

bool KeysAndRooms(const std::vector<std::vector<int>>& iRooms) {
  assert(!iRooms.empty());

  std::unordered_set<int> explored;
  std::stack<int> toExplore;

  toExplore.push(0);
  while (!toExplore.empty()) {
    const int roomIndex = toExplore.top();
    toExplore.pop();
    explored.insert(roomIndex);

    assert(roomIndex >= 0);
    assert(static_cast<std::size_t>(roomIndex) < iRooms.size());
    for (const int key : iRooms[roomIndex]) {
      if (explored.count(key) == 0) {
        toExplore.push(key);
      }
    }
  }

  return explored.size() == iRooms.size();
}

}  // namespace algorithms
