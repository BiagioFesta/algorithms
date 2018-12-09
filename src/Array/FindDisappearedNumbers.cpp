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
#include <algorithms/Array/FindDisappearedNumbers.hpp>
#include <cassert>
#include <vector>

namespace algorithms {

std::vector<int> FindDisappearedNumbers(const std::vector<int>& iVector) {
  std::vector<bool> table(iVector.size(), false);
  for (const int n : iVector) {
    assert(n <= static_cast<int>(iVector.size()));
    assert(n >= 1);

    table[n - 1] = true;
  }

  std::vector<int> missing;
  missing.reserve(iVector.size());
  for (int i = 0; i < static_cast<int>(iVector.size()); ++i) {
    if (table[i] == false) missing.push_back(i + 1);
  }

  return missing;
}

}  // namespace algorithms
