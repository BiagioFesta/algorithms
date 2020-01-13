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
#include <algorithms/Array/ArrayDoubledPairs.hpp>
#include <cassert>
#include <map>
#include <vector>

namespace algorithms {

bool ArrayDoubledPairs(const std::vector<int>& A) {
  assert((A.size() & 0x1) == 0x0);

  std::map<int, int> freq;
  for (std::size_t i = 0; i < A.size(); ++i) {  // O(N)
    ++freq[A[i]];                               // O(logN)
  }

  for (auto& f : freq) {
    while (f.second > 0) {
      --f.second;
      const int n = f.first;

      if (((n & 0x1) == 0) && (freq[n / 2] > 0)) {
        --freq[n / 2];
      } else if (freq[n * 2] > 0) {
        --freq[n * 2];
      } else {
        return false;
      }
    }
  }  // O(NlogN)

  return true;
}

}  // namespace algorithms
