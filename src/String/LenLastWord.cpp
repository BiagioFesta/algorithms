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
#include <algorithms/String/LenLastWord.hpp>

namespace algorithms {

int LenLastWord(const char* iStr) {
  bool space = false;
  int len = 0;

  for (int i = 0;; ++i) {
    const char c = iStr[i];
    if (c == '\0') return len;
    if (c == ' ') {
      space = true;
    } else {
      len = space == true ? 1 : len + 1;
      space = false;
    }
  }
}

}  // namespace algorithms
