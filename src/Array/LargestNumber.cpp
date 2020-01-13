/*
  Copyright (C) 2020  Biagio Festa

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
#include <algorithms/Array/LargestNumber.hpp>
#include <string>
#include <vector>

namespace algorithms {

std::string LargestNumber(std::vector<int> iNumbers) {
  std::sort(iNumbers.begin(), iNumbers.end(), [](const int x, const int y) {
    static std::string sComposition;

    sComposition.clear();
    sComposition += std::to_string(x);
    sComposition += std::to_string(y);
    const int xy = std::stoi(sComposition);

    sComposition.clear();
    sComposition += std::to_string(y);
    sComposition += std::to_string(x);
    const int yx = std::stoi(sComposition);

    return xy > yx;
  });

  const auto aFirstNonZero = std::find_if(
      iNumbers.begin(), iNumbers.end() - 1, [](const int n) { return n != 0; });
  if (aFirstNonZero != iNumbers.begin()) {
    iNumbers.erase(iNumbers.begin(), aFirstNonZero);
  }

  std::string aRtn;
  for (const int n : iNumbers) {
    aRtn += std::to_string(n);
  }

  return aRtn;
}

}  // namespace algorithms
