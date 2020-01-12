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
#include <algorithms/BackTracking/BeautifulArrangement.hpp>
#include <cassert>
#include <vector>

namespace {

int BeautifulArrangementImpl(const std::size_t ith,
                             std::vector<bool>* poolNums) {
  const auto N = poolNums->size();
  if (ith == N) {
    return 1;
  }

  int numSolutions = 0;
  for (std::size_t k = 0; k < N; ++k) {
    if ((*poolNums)[k] == false) {
      if (((k + 1) % (ith + 1) == 0) || ((ith + 1) % (k + 1) == 0)) {
        (*poolNums)[k] = true;
        numSolutions += BeautifulArrangementImpl(ith + 1, poolNums);
        (*poolNums)[k] = false;
      }
    }
  }
  return numSolutions;
}

}  // anonymous namespace

namespace algorithms {

int BeautifulArrangement(const int N) {
  assert(N > 0);
  std::vector<bool> poolNums(N);
  return ::BeautifulArrangementImpl(0, &poolNums);
}

}  // namespace algorithms
