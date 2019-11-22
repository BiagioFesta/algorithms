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
#include <algorithm>
#include <algorithms/DynamicProgramming/BuySellStockWithCooldown.hpp>
#include <cassert>
#include <vector>

namespace algorithms {

int BuySellStockWithCooldown(const std::vector<int>& prices) {
  const auto kSize = prices.size();
  if (kSize == 0) {
    return 0;
  }

  std::vector<std::pair<int, int>> dp(kSize);

  for (std::size_t i = kSize; i > 0; --i) {
    assert(prices[i - 1] >= 0);

    auto& [wo, w] = dp[i - 1];
    w = prices[i - 1];

    if (i < kSize) {
      wo = dp[i].first;
      wo = std::max(wo, dp[i].second - w);
      if (i + 1 < kSize) {
        w += dp[i + 1].first;
      }
      w = std::max(w, dp[i].second);
    }
  }

  return dp[0].first;
}

}  // namespace algorithms
