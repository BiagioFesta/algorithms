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
#include <algorithm>
#include <algorithms/Array/FindLengthOfLCIS.hpp>
#include <vector>

namespace algorithms {

int FindLengthOfLCIS(const std::vector<int>& iVector) {
  if (iVector.empty()) return 0;

  int counter = 1;
  int max = 1;
  for (int i = 1; i < static_cast<int>(iVector.size()); ++i) {
    if (iVector[i - 1] < iVector[i]) {
      ++counter;
    } else {
      max = std::max(max, counter);
      counter = 1;
    }
  }

  return std::max(max, counter);
}

}  // namespace algorithms
