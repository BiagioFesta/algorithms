/*
  Copyright (C) 2021  Biagio Festa

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
#include <algorithms/Array/SortColors.hpp>
#include <cassert>
#include <utility>
#include <vector>

namespace algorithms {

void SortColors(std::vector<int>* nums) {
  const std::size_t kSize = nums->size();
  std::size_t p = 0, q = 0;

  for (std::size_t i = 0; i < kSize; ++i) {
    int& num = (*nums)[i];
    assert(num == 0 || num == 1 || num == 2);

    if (num == 0) {
      std::swap((*nums)[p++], num);
      if (q < p) {
        ++q;
      } else {
        std::swap((*nums)[q++], num);
      }
    } else if (num == 1) {
      std::swap((*nums)[q++], num);
    }
  }
}

}  // namespace algorithms
