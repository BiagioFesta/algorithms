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
#include <algorithm>
#include <algorithms/Array/DistantBarcodes.hpp>
#include <cassert>
#include <unordered_map>
#include <utility>
#include <vector>

namespace algorithms {

std::vector<int> DistantBarcodes(const std::vector<int>& barcodes) {
  std::unordered_map<int, int> frequencies;
  for (const int b : barcodes) {  // O(N)
    ++frequencies[b];             // O(1)
  }

  std::vector<std::pair<int, int>> heap;
  heap.reserve(frequencies.size());

  for (const auto [barcode, frequency] : frequencies) {  // O(K)
    heap.emplace_back(frequency, barcode);               // O(1)
    std::push_heap(heap.begin(), heap.end());            // O(logK)
  }

  frequencies.clear();

  std::vector<int> result;
  result.reserve(barcodes.size());

  while (heap.size() > 1) {                   // O(N)
    std::pop_heap(heap.begin(), heap.end());  // O(logK)
    auto f1 = heap.back();                    // O(1)
    heap.pop_back();                          // O(1)
    std::pop_heap(heap.begin(), heap.end());  // O(logK)
    auto f2 = heap.back();                    // O(1)
    heap.pop_back();                          // O(2)

    result.push_back(f1.second);  // O(1)
    result.push_back(f2.second);  // O(1)

    if (--f1.first) {
      heap.emplace_back(f1.first, f1.second);    // O(1)
      std::push_heap(heap.begin(), heap.end());  // O(logK)
    }

    if (--f2.first) {
      heap.emplace_back(f2.first, f2.second);    // O(1)
      std::push_heap(heap.begin(), heap.end());  // O(logK)
    }
  }

  if (heap.size() == 1) {
    assert(heap[0].first == 1);
    result.push_back(heap[0].second);
  }

  return result;
}

}  // namespace algorithms
