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
#include <algorithms/DynamicProgramming/TwoKeysKeyboard.hpp>
#include <cassert>
#include <limits>
#include <vector>

namespace algorithms {

int TwoKeysKeyboard(const int n) {
  const int kHalfN = n / 2;
  const int kNumCols = kHalfN + 1;
  std::vector<int> dp((n + 1) * kNumCols, 0);

  for (int p = 0; p < n - 1; ++p) {       // O(N)
    for (int q = 0; q < kNumCols; ++q) {  // O(N)
      const int i = n - p - 1;
      const int j = kHalfN - q;
      assert(i >= 0 && i < n);
      assert(j >= 0 && j < kNumCols);

      auto& sol = dp[i * kNumCols + j];
      sol = std::numeric_limits<int>::max();
      if (i > j && i < kNumCols) {
        sol = dp[i * kNumCols + i];
      }
      if (j > 0 && i + j <= n) {
        sol = std::min(sol, dp[(i + j) * kNumCols + j]);
      }
      if (sol != std::numeric_limits<int>::max()) {
        ++sol;
      }
    }
  }

  return dp[kNumCols];
}

}  // namespace algorithms
