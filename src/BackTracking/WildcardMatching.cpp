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
#include <algorithms/BackTracking/WildcardMatching.hpp>
#include <string>

namespace algorithms {

bool WildcardMatching(const std::string& s, const std::string& p) {
  const char* sd = s.c_str();
  const char* pd = p.c_str();
  const char* sm = nullptr;
  const char* pm = nullptr;

  while (*sd) {
    if ((*pd == '?') || (*pd == *sd)) {
      ++sd;
      ++pd;
    } else if (*pd == '*') {
      sm = sd;
      pm = pd++;
    } else if (sm) {
      sd = sm + 1;
      pd = pm;
    } else {
      return false;
    }
  }

  while (*pd == '*') ++pd;

  return !(*pd);
}

}  // namespace algorithms
