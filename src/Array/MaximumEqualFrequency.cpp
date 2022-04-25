/*
  Copyright (C) 2022  Biagio Festa

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
#include <algorithms/Array/MaximumEqualFrequency.hpp>
#include <cmath>
#include <iterator>
#include <unordered_map>

namespace algorithms {

int MaximumEqualFrequency(const std::vector<int>& nums) {
  std::unordered_map<int, std::size_t> freq;
  for (const int n : nums) {
    freq[n] += 1;
  }

  int ws = nums.size();
  std::unordered_map<int, int> ufreq;

  while (1 < ws) {
    ufreq.clear();
    for (const auto& [_, f] : freq) {
      ufreq[f] += 1;
    }

    if (ufreq.size() == 1 && (ufreq.cbegin()->second == 1 || ufreq.cbegin()->first == 1)) {
      return ws;
    }

    if (ufreq.size() == 2) {
      const auto& first = ufreq.cbegin();
      const auto& second = std::next(ufreq.cbegin());

      if (first->second == 1 && (first->first == 1 || first->first - 1 == second->first)) {
        return ws;
      }
      if (second->second == 1 && (second->first == 1 || second->first - 1 == first->first)) {
        return ws;
      }
    }

    --freq[nums[--ws]];
    if (freq[nums[ws]] == 0) {
      freq.erase(nums[ws]);
    }
  }

  return 1;
}

}  // namespace algorithms
