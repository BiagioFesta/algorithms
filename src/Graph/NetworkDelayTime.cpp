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
#include <algorithms/Graph/NetworkDelayTime.hpp>
#include <cassert>
#include <limits>
#include <stack>
#include <vector>

namespace {

using NextHopMap = std::vector<std::vector<std::pair<int, int>>>;

NextHopMap ComputeNextHopMap(const std::vector<std::vector<int>>& times,
                             const int N) {
  NextHopMap nextHopMap(N + 1);
  for (const auto& edge : times) {
    assert(edge.size() == 3ull);
    assert(edge[0] <= N);
    assert(edge[1] <= N);
    nextHopMap[edge[0]].emplace_back(edge[1], edge[2]);
  }
  return nextHopMap;
}

}  // anonymous namespace

namespace algorithms {

int NetworkDelayTime(const std::vector<std::vector<int>>& times,
                     const int N,
                     const int K) {
  constexpr auto kMaxInt = std::numeric_limits<int>::max();
  const auto nextHopMap = ::ComputeNextHopMap(times, N);
  std::vector<int> delays(N + 1, kMaxInt);

  std::stack<int> dfs;
  dfs.push(K);
  delays[K] = 0;

  while (!dfs.empty()) {
    const int current = dfs.top();
    dfs.pop();

    for (const auto [next, time] : nextHopMap[current]) {
      const auto delay = delays[current] + time;
      if (delay < delays[next]) {
        delays[next] = delay;
        dfs.push(next);
      }
    }
  }

  int ans = -1;
  for (int i = 1; i <= N; ++i) {
    if (delays[i] == kMaxInt) {
      return -1;
    }
    ans = std::max(ans, delays[i]);
  }

  return ans;
}

}  // namespace algorithms
