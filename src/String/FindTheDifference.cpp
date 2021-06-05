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
#include <algorithms/String/FindTheDifference.hpp>
#include <string>

namespace algorithms {

char FindTheDifference(const std::string& iStringS, const std::string& iStringT) {
  static constexpr int kSizeASCII = 1 << 8;

  int freqCounter[kSizeASCII]{};
  for (const char c : iStringS) {
    ++freqCounter[static_cast<int>(c)];
  }

  for (const char c : iStringT) {
    if (--freqCounter[static_cast<int>(c)] < 0) return c;
  }

  return static_cast<char>(0);
}

}  // namespace algorithms
