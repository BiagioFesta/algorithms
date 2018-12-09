/*
  Copyright (C) 2018  Biagio Festa

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
#include <algorithms/DynamicProgramming/FindRotateSteps.hpp>
#include <cassert>
#include <limits>
#include <string_view>
#include <vector>

namespace algorithms {

std::size_t FindRotateSteps(const std::string_view iRing,
                            const std::string_view iKey) {
  constexpr auto kMaxIndex = std::numeric_limits<std::size_t>::max();
  const auto kK = iKey.size();
  const auto kR = iRing.size();

  const auto kFnDistance = [kR](const std::size_t i,
                                const std::size_t j) noexcept {
    const auto aAbs = i < j ? j - i : i - j;
    return std::min(aAbs, kR - aAbs);
  };

  std::vector<std::size_t> aSolutions((kK + 1) * kR);

  for (auto c = iKey.crbegin(); c != iKey.crend(); ++c) {  // O(K)
    const auto i = kK - std::distance(iKey.crbegin(), c) - 1;

    for (std::size_t j = 0; j < kR; ++j) {  // O(R)
      std::size_t aMin = kMaxIndex;

      for (std::size_t q = 0; q < kR; ++q) {  // O(R)
        if (iRing[q] == iKey[i]) {
          const auto aRecur = aSolutions[(i + 1) * kR + q];
          const auto aDist = kFnDistance(j, q);
          aMin = std::min(aMin, aRecur + 1 + aDist);
        }
      }
      assert(aMin != kMaxIndex);

      aSolutions[i * kR + j] = aMin;
    }
  }

  return aSolutions[0];
}

}  // namespace algorithms
