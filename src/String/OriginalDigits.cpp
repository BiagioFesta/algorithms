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
#include <algorithms/String/OriginalDigits.hpp>
#include <array>
#include <string>
#include <tuple>
#include <vector>

namespace algorithms {

std::string OriginalDigits(const std::string& iString) {
  static constexpr int kEnglishAlphabetSize = 26;
  static constexpr int kNumDigits = 10;
  static constexpr std::array<std::tuple<int, char, const char*>, kNumDigits>
      kDigitInfo = {std::make_tuple(6, 'x', "six"),
                    std::make_tuple(7, 's', "seven"),
                    std::make_tuple(5, 'v', "five"),
                    std::make_tuple(4, 'f', "four"),
                    std::make_tuple(8, 'g', "eight"),
                    std::make_tuple(9, 'i', "nine"),
                    std::make_tuple(3, 'h', "three"),
                    std::make_tuple(2, 'w', "two"),
                    std::make_tuple(0, 'z', "zero"),
                    std::make_tuple(1, 'o', "one")};

  std::vector<int> frequencies(kEnglishAlphabetSize, 0);
  for (const char c : iString) ++frequencies[c - 'a'];  // O(N)

  std::vector<int> counterDigit(kNumDigits, 0);
  for (const auto& digitInfo : kDigitInfo) {  // O(1)
    const char* digitStr = std::get<2>(digitInfo);
    const int numRepetitions = frequencies[std::get<1>(digitInfo) - 'a'];
    while (*digitStr != '\0') {  // O(1)
      frequencies[*digitStr - 'a'] -= numRepetitions;
      ++digitStr;
    }

    counterDigit[std::get<0>(digitInfo)] = numRepetitions;
  }

  std::string aResult;
  for (int i = 0; i < kNumDigits; ++i) {  // O(1)
    aResult += std::string(counterDigit[i], '0' + i);
  }

  return aResult;
}

}  // namespace algorithms
