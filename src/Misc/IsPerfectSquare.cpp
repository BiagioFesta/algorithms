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
#include <algorithms/Misc/IsPerfectSquare.hpp>

namespace algorithms {

bool IsPerfectSquare(const int num) {
  long long left = 1;
  long long right = num / 2 + 1;

  while (left <= right) {
    const auto mid = left + (right - left) / 2;
    const auto pow = mid * mid;
    if (pow == num) {
      return true;
    } else if (pow < num) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return false;
}

}  // namespace algorithms
