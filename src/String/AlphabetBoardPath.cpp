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
#include <algorithms/String/AlphabetBoardPath.hpp>
#include <string>
#include <tuple>

namespace algorithms {

std::string AlphabetBoardPath(const std::string& target) {
  constexpr int kTableWidth = 5;

  std::string result;
  int x = 0, y = 0;

  for (const auto t : target) {
    const int index = t - 'a';
    const int xTar = index % kTableWidth;
    const int yTar = index / kTableWidth;
    const int xDelta = xTar - x;
    const int yDelta = yTar - y;
    if (yDelta < 0) {
      result.append(-yDelta, 'U');  // O(1) delta is bounded by Width
    }
    if (xDelta < 0) {
      result.append(-xDelta, 'L');  // O(1) delta is bounded by Width
    }
    if (yDelta > 0) {
      result.append(yDelta, 'D');  // O(1) delta is bounded by Width
    }
    if (xDelta > 0) {
      result.append(xDelta, 'R');  // O(1) delta is bounded by Width
    }
    result.append(1, '!');
    x = xTar;
    y = yTar;
  }
  return result;
}

}  // namespace algorithms
