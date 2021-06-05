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
#include <algorithms/Array/IncreasingTripletSubsequence.hpp>
#include <limits>
#include <vector>

namespace algorithms {

bool IncreasingTripletSubsequence(const std::vector<int>& nums) {
  int a, b;

  a = b = std::numeric_limits<int>::max();
  for (const int n : nums) {
    if (n <= a) {
      a = n;
    } else if (n <= b) {
      b = n;
    } else {
      return true;
    }
  }
  return false;
}

}  // namespace algorithms
