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
#include <algorithm>
#include <algorithms/DynamicProgramming/MinPathSum.hpp>
#include <cassert>
#include <limits>
#include <vector>

namespace algorithms {

int MinPathSum(const int* const iMatrix, const int M, const int N) {
  static constexpr int kMaxInt = std::numeric_limits<int>::max();
  const int Q = M * N;
  assert(Q > 0);

  std::vector<int> aSolutions(Q);
  aSolutions[Q - 1] = iMatrix[Q - 1];

  for (int i = 1; i < Q; ++i) {
    const int index = Q - 1 - i;
    const int costDown =
        i < N ? kMaxInt : aSolutions[index + N] + iMatrix[index];
    const int costRight =
        i % N == 0 ? kMaxInt : aSolutions[index + 1] + iMatrix[index];
    aSolutions[index] = std::min(costDown, costRight);
  }

  return aSolutions[0];
}

}  // namespace algorithms
