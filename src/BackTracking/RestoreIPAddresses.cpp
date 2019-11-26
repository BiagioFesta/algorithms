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
#include <algorithms/BackTracking/RestoreIPAddresses.hpp>
#include <cassert>
#include <stack>
#include <string>
#include <string_view>
#include <utility>
#include <vector>

namespace algorithms {

/*
     255.255.255.255
      3 + 3 + 3 + 3   = 12 char

     1 . 1 . 1 . 1 = 4 char

     0 1 2     3 4 5     6 7 8     9 10 11
     --------------------------------------
     2 5 5  .  2 5 5  .  2 5 5  .  2 5 5

 */
std::vector<std::string> RestoreIPAddresses(const std::string& s) {
  struct State {
    std::string_view str_;
    std::vector<std::string_view> fields_;

    State(const std::string& s) : str_{s.data(), s.size()} {}
    State(std::string_view sv, std::vector<std::string_view> fields)
        : str_{sv}, fields_{std::move(fields)} {}
  };

  std::stack<State> dfs;
  dfs.emplace(s);

  std::vector<std::string> ips;
  while (!dfs.empty()) {
    auto [str, fields] = std::move(dfs.top());
    dfs.pop();

    if (str.empty() && fields.size() == 4) {
      std::string ip;
      for (std::size_t i = 0; i < 4; ++i) {
        ip += fields[i];
        if (i < 3) {
          ip += '.';
        }
      }
      ips.push_back(std::move(ip));
    } else if (fields.size() < 4) {
      for (std::size_t i = 0; i < 3; ++i) {
        if (i < str.size()) {
          const auto field = str.substr(0, i + 1);
          const int num = std::stoi(std::string(field.data(), field.size()));
          if (num < 256) {
            fields.emplace_back(field);
            dfs.emplace(str.substr(i + 1), fields);
            fields.pop_back();
            if (num == 0) {
              break;
            }
          }
        }
      }
    }
  }
  return ips;
}

}  // namespace algorithms
