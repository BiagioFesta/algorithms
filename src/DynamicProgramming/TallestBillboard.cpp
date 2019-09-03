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
#include <algorithms/DynamicProgramming/TallestBillboard.hpp>
#include <cassert>
#include <limits>
#include <unordered_map>
#include <utility>
#include <vector>

namespace {

using HashTable = std::unordered_map<std::size_t, int>;

int TallestBillboardImpl(const std::vector<int>& rods,
                         const std::size_t i,
                         const int d,
                         HashTable* hashTable) {
  static constexpr std::size_t kMaxI = 20;
  static constexpr int kInvalid = std::numeric_limits<int>::min();
  assert(d >= 0);
  assert(i <= kMaxI);

  if (i == rods.size()) {
    return d == 0 ? 0 : kInvalid;
  }

  const auto hash = static_cast<std::size_t>(d) * kMaxI + i;

  if (const auto finder = hashTable->find(hash); finder != hashTable->cend()) {
    return finder->second;
  }

  int ans = TallestBillboardImpl(rods, i + 1, d, hashTable);
  ans =
      std::max(ans, TallestBillboardImpl(rods, i + 1, d + rods[i], hashTable));
  ans = std::max(
      ans,
      TallestBillboardImpl(rods, i + 1, std::abs(d - rods[i]), hashTable) +
          (d - rods[i] >= 0 ? rods[i] : d));

  hashTable->emplace(hash, ans);
  return ans;
}

}  // anonymous namespace

namespace algorithms {

int TallestBillboard(const std::vector<int>& rods) {
  ::HashTable hashTable;
  return ::TallestBillboardImpl(rods, 0, 0, &hashTable);
}

}  // namespace algorithms
