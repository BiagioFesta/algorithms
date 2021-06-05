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
#include <algorithms/String/RepeatedDNASequences.hpp>
#include <string>
#include <string_view>
#include <unordered_map>
#include <vector>

namespace algorithms {

std::vector<std::string> RepeatedDNASequences(const std::string& s) {
  constexpr std::size_t kSeqSize = 10;

  std::unordered_map<std::string_view, int> visited;
  std::vector<std::string> ans;
  std::string_view sv = s;

  for (std::size_t i = kSeqSize - 1; i < sv.size(); ++i) {  // O(N)
    const std::string_view seq = sv.substr(i + 1 - kSeqSize, kSeqSize);
    if ((++visited[seq]) == 2) {                 // O(1)
      ans.emplace_back(seq.data(), seq.size());  // O(1) amortz
    }
  }
  return ans;
}

}  // namespace algorithms
