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
#include <algorithms/String/LetterCasePermutation.hpp>
#include <locale>
#include <string>
#include <vector>

namespace algorithms {

void LetterCasePermutation(const std::string& iStr,
                           std::vector<std::string>* oPermutations) {
  static const std::locale sLocale;
  static const auto permChar = [](const char c) {
    return std::islower(c, sLocale) ? std::toupper(c, sLocale)
                                    : std::tolower(c, sLocale);
  };

  oPermutations->clear();
  oPermutations->push_back(iStr);

  for (std::size_t i = 0u; i < iStr.size(); ++i) {
    if (std::isalpha(iStr[i], sLocale)) {
      const int s = oPermutations->size();
      for (int j = 0; j < s; ++j) {
        std::string newPerm = (*oPermutations)[j];
        newPerm[i] = permChar(newPerm[i]);
        oPermutations->push_back(std::move(newPerm));
      }
    }
  }
}

}  // namespace algorithms
