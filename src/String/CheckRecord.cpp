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
#include <algorithms/String/CheckRecord.hpp>
#include <cassert>
#include <string>

namespace algorithms {

bool CheckRecord(const std::string& iString) {
  constexpr int kMaxLateConsegutiveAllowed = 2;
  const std::size_t kSize = iString.size();

  int aAbsences = 0;
  int aCongLate = 0;

  for (std::size_t i = 0; i < kSize; ++i) {
    const char c = iString[i];
    assert(c == 'A' || c == 'L' || c == 'P');

    if (c == 'A') {
      aCongLate = 0;
      ++aAbsences;
      if (aAbsences > 1) {
        return false;
      }
    } else if (c == 'L') {
      ++aCongLate;
      if (aCongLate > kMaxLateConsegutiveAllowed) {
        return false;
      }
    } else {
      aCongLate = 0;
    }
  }

  return true;
}

}  // namespace algorithms
