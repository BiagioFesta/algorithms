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
#include <algorithms/DynamicProgramming/MaxProfit.hpp>
#include <vector>

namespace algorithms {

int MaxProfit(const std::vector<int>& iPrices) {
  const std::size_t kSize = iPrices.size();
  if (kSize == 0) return 0;

  std::vector<int> aMaxRevenue(kSize);

  int aCurrentMin = iPrices[0];
  for (std::size_t i = 1; i < kSize; ++i) {
    const int iCurrentPrice = iPrices[i];
    aMaxRevenue[i] = std::max(aMaxRevenue[i - 1], iCurrentPrice - aCurrentMin);
    aCurrentMin = std::min(aCurrentMin, iCurrentPrice);
  }

  int aMaxProfit = aMaxRevenue.back();
  int aCurrentMax = iPrices.back();
  for (std::size_t i = kSize; i > 0; --i) {
    const int iCurrentPrice = iPrices[i - 1];
    aMaxProfit =
        std::max(aMaxProfit, aCurrentMax - iCurrentPrice + aMaxRevenue[i - 1]);
    aCurrentMax = std::max(aCurrentMax, iCurrentPrice);
  }

  return aMaxProfit;
}

}  // namespace algorithms
