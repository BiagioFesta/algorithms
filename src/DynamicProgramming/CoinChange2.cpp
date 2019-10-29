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
#include <algorithms/DynamicProgramming/CoinChange2.hpp>
#include <vector>

namespace algorithms {

int CoinChange2(const int amount, const std::vector<int>& coins) {
  if (coins.empty()) return amount == 0;

  const int N = coins.size();
  const int M = amount + 1;

  std::vector<int> dp(N * M);

  for (int i = 0; i < N; ++i) {
    dp[i * M] = 1;
  }

  for (int i = 0; i < N; ++i) {
    for (int j = 1; j < M; ++j) {
      if (int diff = j - coins[i]; diff >= 0) {
        dp[i * M + j] += dp[i * M + diff];
      }
      if (i > 0) {
        dp[i * M + j] += dp[(i - 1) * M + j];
      }
    }
  }

  return dp.back();
}

}  // namespace algorithms
