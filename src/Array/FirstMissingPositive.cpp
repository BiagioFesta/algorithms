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
#include <algorithms/Array/FirstMissingPositive.hpp>
#include <utility>
#include <vector>

namespace algorithms {

int FirstMissingPositive(std::vector<int>* iVector) {
  const int n = iVector->size();

  for (int i = 0; i < n;) {
    int& value_i = (*iVector)[i];
    if (value_i > 0 && value_i <= n) {
      int& value_j = (*iVector)[value_i - 1];
      if (value_i != value_j) {
        std::swap(value_i, value_j);
      } else {
        ++i;
      }
    } else {
      ++i;
    }
  }

  for (int i = 0; i < n; ++i) {
    if ((*iVector)[i] != i + 1) {
      return i + 1;
    }
  }

  return n + 1;
}

}  // namespace algorithms
