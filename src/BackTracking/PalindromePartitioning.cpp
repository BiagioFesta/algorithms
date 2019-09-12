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
#include <algorithms/BackTracking/PalindromePartitioning.hpp>
#include <cassert>
#include <stack>
#include <string>
#include <utility>
#include <vector>

namespace {

bool IsPalidrome(const std::string& str) noexcept {
  const auto middle = str.size() / 2;
  const auto pend = str.size() - 1;
  for (std::size_t i = 0; i < middle; ++i) {
    if (str[i] != str[pend - i]) return false;
  }
  return true;
}

}  // anonymous namespace

namespace algorithms {

std::vector<std::vector<std::string>> PalindromePartitioning(
    const std::string& s) {
  using State = std::vector<std::string>;
  std::vector<std::vector<std::string>> ans;

  std::stack<State> dfs;
  dfs.emplace(1, s);

  while (!dfs.empty()) {
    auto current = std::move(dfs.top());
    dfs.pop();

    assert(!current.empty());
    if (::IsPalidrome(current.back())) {
      ans.push_back(current);
    }

    const auto lastPartition = std::move(current.back());
    current.pop_back();
    for (std::size_t i = 0; i < lastPartition.size() - 1; ++i) {
      auto p1 = lastPartition.substr(0, i + 1);
      auto p2 = lastPartition.substr(i + 1);
      if (::IsPalidrome(p1)) {
        dfs.push(current);
        dfs.top().push_back(std::move(p1));
        dfs.top().push_back(std::move(p2));
      }
    }
  }

  return ans;
}

}  // namespace algorithms
