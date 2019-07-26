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
  constexpr std::size_t kSizeTable = 1 << 8;

  const int kSizeS = s.size();
  const int kSizeP = p.size();
  std::array<int, kSizeTable> needs{};
  std::vector<int> result;
  int l = 0, r = 0, missing = kSizeP;

  for (const char c : p) {  // O(P)
    ++needs[c];
  }

  while (r < kSizeS) {  // O(S)
    if (--needs[s[r++]] >= 0) {
      --missing;
    }
    if (!missing) {
      result.push_back(l);
    }
    if (r - l == kSizeP && ++needs[s[l++]] > 0) {
      ++missing;
    }
  }

  return result;
}

}  // namespace algorithms
