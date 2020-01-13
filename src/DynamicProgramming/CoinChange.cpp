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
#include <algorithms/DynamicProgramming/CoinChange.hpp>
#include <cassert>
#include <limits>
#include <vector>

namespace algorithms {

int CoinChange(const std::vector<int>& coins, const int amount) {
  constexpr int kEmpty = std::numeric_limits<int>::max();
  assert(amount >= 0);

  std::vector<int> dp(amount + 1, kEmpty);
  dp[0] = 0;

  for (const int c : coins) {            // O(N)
    for (int i = c; i <= amount; ++i) {  // O(K)
      if (dp[i - c] != kEmpty) {
        dp[i] = std::min(dp[i], dp[i - c] + 1);
      }
    }
  }

  return dp.back() != kEmpty ? dp.back() : -1;
}

}  // namespace algorithms
