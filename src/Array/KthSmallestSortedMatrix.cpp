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
#include <algorithms/Array/KthSmallestSortedMatrix.hpp>
#include <cassert>
#include <functional>
#include <queue>
#include <tuple>
#include <vector>

namespace algorithms {

int KthSmallestSortedMatrix(const std::vector<std::vector<int>>& matrix,
                            int k) {
  using HeapElement = std::tuple<int, std::size_t, std::size_t>;
  using Heap = std::priority_queue<HeapElement,
                                   std::vector<HeapElement>,
                                   std::greater<HeapElement>>;

  const std::size_t size = matrix.size();
  assert(k > 0);
  assert(static_cast<std::size_t>(k) <= size * size);
  Heap heap;

  for (std::size_t i = 0; i < size; ++i) {  // O(N)
    heap.emplace(matrix[i][0], i, 0);       // O(logN)
  }

  int ans;
  do {                                      // O(K)
    const auto [value, i, j] = heap.top();  // O(1)
    heap.pop();                             // O(logN)
    if (j + 1 < size) {
      heap.emplace(matrix[i][j + 1], i, j + 1);  // O(logN)
    }
    ans = value;
  } while (--k);

  return ans;
}

}  // namespace algorithms
