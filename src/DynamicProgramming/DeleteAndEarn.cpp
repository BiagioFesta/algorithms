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
#include <algorithms/DynamicProgramming/DeleteAndEarn.hpp>
#include <array>
#include <cassert>
#include <vector>

namespace algorithms {

int DeleteAndEarn(const std::vector<int>& nums) {
  constexpr std::size_t kUbValue = 10001;

  std::array<int, kUbValue> freq{};
  for (const auto n : nums) {
    assert(n > 0);
    assert(static_cast<std::size_t>(n) < kUbValue);
    ++freq[n];
  }

  std::vector<int> dp(kUbValue);
  dp[1] = freq[1];
  for (std::size_t i = 2; i < kUbValue; ++i) {
    dp[i] = std::max(dp[i - 1], dp[i - 2] + ((int)i * freq[i]));
  }

  return dp.back();
}

}  // namespace algorithms
