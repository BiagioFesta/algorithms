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
#include <algorithms/Array/FruitIntoBaskets.hpp>
#include <cassert>
#include <limits>
#include <vector>

namespace algorithms {

int FruitIntoBaskets(const std::vector<int>& tree) {
  assert(!tree.empty());

  int maxWin = 1;
  std::size_t i = 0, j = 0;
  int firstType;
  int secondType;

  while (i < tree.size() - 1) {
    j = i;
    firstType = tree[i];
    while (j < tree.size() && tree[j] == firstType) {
      ++j;
    }

    if (j < tree.size()) {
      secondType = tree[j];
      while (j < tree.size() &&
             (tree[j] == firstType || tree[j] == secondType)) {
        ++j;
      }
    }

    maxWin = std::max(maxWin, static_cast<int>(j - i));

    i = j - 1;
    if (j < tree.size()) {
      while (i > 0 && tree[i - 1] == tree[i]) --i;
    }
  }

  return maxWin;
}

}  // namespace algorithms
