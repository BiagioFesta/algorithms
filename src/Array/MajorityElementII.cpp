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
#include <algorithms/Array/MajorityElementII.hpp>
#include <vector>

namespace algorithms {

std::vector<int> MajorityElementII(const std::vector<int>& nums) {
  std::pair<int, int> counterA = {0, 0};
  std::pair<int, int> counterB = {0, 0};
  for (const int num : nums) {
    if (num == counterA.first) {
      ++counterA.second;
    } else if (num == counterB.first) {
      ++counterB.second;
    } else if (counterA.second == 0) {
      counterA.first = num;
      counterA.second = 1;
    } else if (counterB.second == 0) {
      counterB.first = num;
      counterB.second = 1;
    } else {
      --counterA.second;
      --counterB.second;
    }
  }

  int checkA = 0;
  int checkB = 0;
  for (const int num : nums) {
    if (counterA.second && counterA.first == num) {
      ++checkA;
    }
    if (counterB.second && counterB.first == num) {
      ++checkB;
    }
  }

  std::vector<int> result;
  result.reserve(2);

  const int lb = nums.size() / 3;
  if (checkA > lb) {
    result.push_back(counterA.first);
  }
  if (checkB > lb) {
    result.push_back(counterB.first);
  }

  return result;
}

}  // namespace algorithms
