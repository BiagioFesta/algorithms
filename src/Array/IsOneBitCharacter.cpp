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
#include <algorithms/Array/IsOneBitCharacter.hpp>
#include <vector>

namespace algorithms {

bool IsOneBitCharacter(const std::vector<int>& iBits) {
  const int kSize = iBits.size();
  if (kSize == 1) return true;

  const int kSizeMinusOne = kSize - 1;

  int i = 0;
  while (i < kSizeMinusOne) {
    i += iBits[i] == 1 ? 2 : 1;
  }

  return i == kSizeMinusOne;
}

}  // namespace algorithms
