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
#include <algorithms/Array/ContainsNearbyDuplicate.hpp>
#include <unordered_set>
#include <vector>

namespace algorithms {

bool ContainsNearbyDuplicate(const std::vector<int>& iNums, const int k) {
  const int kSize = iNums.size();
  if (kSize == 0 || kSize == 1 || k == 0) return false;

  std::unordered_set<int> hashTable;
  hashTable.insert(iNums[0]);

  int i = 0;
  int j = 1;
  while (j < kSize) {  // O(N)
    const int jValue = iNums[j];
    if (hashTable.count(jValue)) return true;  // O(1)
    hashTable.insert(jValue);                  // O(1)
    ++j;
    if (j - i > k) {
      hashTable.erase(iNums[i]);  // O(1)
      ++i;
    }
  }

  return false;
}

}  // namespace algorithms
