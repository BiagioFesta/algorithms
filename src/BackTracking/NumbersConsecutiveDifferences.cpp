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
#include <algorithms/BackTracking/NumbersConsecutiveDifferences.hpp>
#include <cassert>
#include <stack>
#include <tuple>
#include <utility>
#include <vector>

namespace algorithms {

std::vector<int> NumbersConsecutiveDifferences(const int N, const int K) {
  assert(N > 0);
  assert(N < 10);
  assert(K >= 0);
  assert(K < 10);

  std::vector<int> ans;
  if (N == 1) {
    ans.push_back(0);
  }

  std::stack<std::tuple<int, int, int>> dfs;
  for (int i = 9; i > 0; --i) {
    dfs.emplace(i, 1, i);
  }

  while (!dfs.empty()) {
    const auto [num, depth, lastDigit] = dfs.top();
    dfs.pop();
    if (depth == N) {
      ans.push_back(num);
    } else {
      if (const int newDigit = lastDigit + K; newDigit < 10) {
        dfs.emplace(num * 10 + newDigit, depth + 1, newDigit);
      }
      if (const int newDigit = lastDigit - K; newDigit >= 0 && K != 0) {
        dfs.emplace(num * 10 + newDigit, depth + 1, newDigit);
      }
    }
  }

  return ans;
}

}  // namespace algorithms
