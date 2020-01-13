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
#include <algorithms/Array/Partition.hpp>
#include <functional>
#include <utility>
#include <vector>

namespace algorithms {

void Partition(std::vector<int>* ioVector, std::function<bool(int)> iFn) {
  const std::size_t kSize = ioVector->size();

  std::size_t i = 0;

  for (std::size_t j = 0; j < kSize; ++j) {
    if (iFn((*ioVector)[j]) == true) {
      if (i != j) {
        std::swap((*ioVector)[i], (*ioVector)[j]);
      }
      ++i;
    }
  }
}

}  // namespace algorithms
