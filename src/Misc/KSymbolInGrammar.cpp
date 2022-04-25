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
#include <algorithms/Misc/KSymbolInGrammar.hpp>
#include <cassert>
#include <cstdint>

namespace algorithms {

int KSymbolInGrammar(const int N, const int K) {
  assert(N > 0);
  assert(K > 0);
  assert(N <= 30);
  const std::uint32_t kLenOnN = 1 << (N - 1);
  assert(static_cast<std::uint32_t>(K) <= kLenOnN);

  if (N == 1) {
    return 0;
  }

  const std::uint32_t LenHalf = kLenOnN / 2;
  const int index = (K - 1) % LenHalf;
  const int symbolPrev = KSymbolInGrammar(N - 1, index + 1);
  return static_cast<std::uint32_t>(K) <= LenHalf ? symbolPrev : !symbolPrev;
}

}  // namespace algorithms
