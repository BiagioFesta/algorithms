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
#include <algorithms/Graph/MinimumGeneticMutation.hpp>
#include <cassert>
#include <queue>
#include <string>
#include <vector>

namespace {

constexpr std::size_t kGeneSize = 8;

int GeneDistance(const char* gene, const char* geneRef) noexcept {
  int diffs = 0;
  for (std::size_t i = 0; i < kGeneSize; ++i) {
    if (gene[i] != geneRef[i]) {
      ++diffs;
    }
  }
  return diffs;
}

}  // anonymous namespace

namespace algorithms {

int MinimumGeneticMutation(const std::string& start, const std::string& end, const std::vector<std::string>& bank) {
  assert(start.size() == ::kGeneSize);
  assert(end.size() == ::kGeneSize);

  std::queue<std::pair<const char*, int>> bfs;
  bfs.emplace(start.data(), 0);

  std::vector<std::pair<bool, const char*>> visited;
  visited.reserve(bank.size());
  for (const auto& b : bank) {
    assert(b.size() == ::kGeneSize);
    visited.emplace_back(false, b.data());
  }

  while (!bfs.empty()) {
    const auto [str, depth] = bfs.front();
    bfs.pop();

    if (::GeneDistance(str, end.data()) == 0) {
      return depth;
    }

    for (auto& b : visited) {
      if (!b.first && ::GeneDistance(str, b.second) == 1) {
        bfs.emplace(b.second, depth + 1);
        b.first = true;
      }
    }
  }
  return -1;
}

}  // namespace algorithms
