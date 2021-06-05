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
#include <algorithms/Array/AdvantageShuffle.hpp>
#include <cassert>
#include <set>
#include <vector>

namespace algorithms {

std::vector<int> AdvantageShuffle(const std::vector<int>& A, const std::vector<int>& B) {
  assert(A.size() == B.size());

  std::multiset<int> sortedA(A.cbegin(), A.cend());  // O(NlogN)

  std::vector<int> result;
  result.reserve(A.size());

  for (const int n : B) {              // O(N)
    auto lb = sortedA.upper_bound(n);  // O(logN)
    if (lb == sortedA.end()) {
      lb = sortedA.begin();
    }
    result.push_back(*lb);  // O(1)
    sortedA.erase(lb);      // O(logN)
  }

  return result;
}

}  // namespace algorithms
