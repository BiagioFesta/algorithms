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
#include <algorithms/DynamicProgramming/UniquePaths.hpp>
#include <cassert>
#include <vector>

namespace algorithms {

int UniquePaths(const int m, const int n) {
  const int mn = m * n;
  assert(mn > 0);
  std::vector<int> dp(mn, 1);
  for (int i = mn - n - 2; i >= 0; --i) {
    if ((i + 1) % n) {
      dp[i] = dp[i + n] + dp[i + 1];
    }
  }

  return dp[0];
}

}  // namespace algorithms
