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
#include <algorithms/BackTracking/BeautifulArrangement.hpp>
#include <cassert>
#include <numeric>
#include <utility>
#include <vector>

namespace {

template <typename T>
constexpr bool Divisible(T a, T b) noexcept {
  while (a >= b) a -= b;
  return a == 0;
}

int BeautifulArrangementImpl(const std::size_t poolSize, std::vector<std::size_t>* poolNums) {
  const auto N = poolNums->size();
  const auto ith = N - poolSize + 1;
  if (poolSize == 0) {
    return 1;
  }
  const auto newPoolSize = poolSize - 1;

  int numSolutions = 0;
  for (std::size_t k = 0; k < poolSize; ++k) {
    if (Divisible((*poolNums)[k], ith) || Divisible(ith, (*poolNums)[k])) {
      std::swap((*poolNums)[k], (*poolNums)[newPoolSize]);
      numSolutions += BeautifulArrangementImpl(newPoolSize, poolNums);
      std::swap((*poolNums)[newPoolSize], (*poolNums)[k]);
    }
  }
  return numSolutions;
}

}  // anonymous namespace

namespace algorithms {

int BeautifulArrangement(const int N) {
  assert(N > 0);
  std::vector<std::size_t> poolNums(N);
  std::iota(poolNums.begin(), poolNums.end(), 1);
  return ::BeautifulArrangementImpl(N, &poolNums);
}

}  // namespace algorithms
