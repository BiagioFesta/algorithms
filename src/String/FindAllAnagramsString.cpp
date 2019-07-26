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
#include <algorithms/String/FindAllAnagramsString.hpp>
#include <array>
#include <cassert>
#include <cstring>
#include <string>
#include <vector>

namespace algorithms {

std::vector<int> FindAllAnagramsString(const std::string& s,
                                       const std::string& p) {
  using Counter = int;
  constexpr std::size_t kSizeTable = 1 << 8;
  constexpr std::size_t kMemorySize = sizeof(Counter) * kSizeTable;

  static const std::array<char, kMemorySize> sZeroes{};

  std::vector<int> result;

  const int kSizeS = s.size();
  const int kSizeP = p.size();
  const int kSizeDelta = kSizeS - kSizeP;
  if (kSizeDelta < 0) {
    return result;
  }

  std::array<Counter, kSizeTable> deltaFreq{};

  for (int i = 0; i < kSizeP; ++i) {        // O(P)
    --(deltaFreq[static_cast<int>(p[i])]);  // O(1)
    ++(deltaFreq[static_cast<int>(s[i])]);  // O(1)
  }

  int i;
  for (i = 0; i < kSizeDelta; ++i) {  // O(S)
    if (std::memcmp(deltaFreq.data(), sZeroes.data(), kMemorySize) == 0) {
      result.push_back(i);
    }

    --(deltaFreq[static_cast<int>(s[i])]);
    ++(deltaFreq[static_cast<int>(s[i + kSizeP])]);
  }
  if (std::memcmp(deltaFreq.data(), sZeroes.data(), kMemorySize) == 0) {
    result.push_back(i);
  }

  return result;
}

}  // namespace algorithms
