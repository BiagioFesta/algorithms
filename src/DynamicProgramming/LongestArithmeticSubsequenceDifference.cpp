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
#include <algorithm>
#include <algorithms/DynamicProgramming/LongestArithmeticSubsequenceDifference.hpp>
#include <unordered_map>
#include <vector>

namespace algorithms {

int LongestArithmeticSubsequenceDifference(const std::vector<int>& arr, const int difference) {
  std::unordered_map<int, int> hashTable;
  int ans = 0, sol;
  for (const int n : arr) {
    sol = hashTable[n - difference] + 1;
    hashTable[n] = sol;
    ans = std::max(ans, sol);
  }
  return ans;
}

}  // namespace algorithms
