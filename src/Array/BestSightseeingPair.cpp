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
#include <algorithms/Array/BestSightseeingPair.hpp>
#include <cassert>
#include <limits>
#include <vector>

namespace algorithms {

int BestSightseeingPair(const std::vector<int>& data) {
  const int kSize = static_cast<int>(data.size());
  assert(kSize > 1);

  int result = std::numeric_limits<int>::min();
  int bestPrev = std::numeric_limits<int>::min();

  for (int i = 0; i < kSize; ++i) {
    result = std::max(result, data[i] - i + bestPrev);
    bestPrev = std::max(bestPrev, data[i] + i);
  }

  return result;
}

}  // namespace algorithms
