/*
  Copyright (C) 2018  Biagio Festa

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
#include <algorithms/DynamicProgramming/SubstringsSum.hpp>
#include <string>

namespace algorithms {

int SubstringsSum(const std::string& iStr) {
  static const int kMod = 1000000007;
  if (iStr.empty()) return 0;

  long long prev = iStr[0] - '0';
  long long current;
  long long sum = iStr[0] - '0';
  for (std::size_t i = 1; i < iStr.size(); ++i) {
    current = ((10 * prev) % kMod + (i + 1) * (iStr[i] - '0')) % kMod;
    sum = (sum + current) % kMod;
    prev = current;
  }

  return static_cast<int>(sum);
}

}  // namespace algorithms
