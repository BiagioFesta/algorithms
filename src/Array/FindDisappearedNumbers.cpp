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
#include <algorithms/Array/FindDisappearedNumbers.hpp>
#include <cassert>
#include <vector>

namespace algorithms {

std::vector<int> FindDisappearedNumbers(const std::vector<int>& iVector) {
  const int kSize = static_cast<int>(iVector.size());

  std::vector<bool> table(kSize, false);
  for (const int n : iVector) {
    assert(n >= 1 && n <= kSize);
    table[n - 1] = true;
  }

  std::vector<int> missing;
  missing.reserve(kSize);

  for (int i = 0; i < kSize; ++i) {
    if (table[i] == false) {
      missing.push_back(i + 1);
    }
  }

  return missing;
}

}  // namespace algorithms
