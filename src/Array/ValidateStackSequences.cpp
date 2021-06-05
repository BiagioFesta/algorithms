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
#include <algorithms/Array/ValidateStackSequences.hpp>
#include <cassert>
#include <stack>
#include <vector>

namespace {

/*! \brief Checks all values are distinct.
 *  \note This is supposed to be a debug function. The runtime complexity is not
 *        optimal!
 */
bool AllValuesAreDistinct(const std::vector<int>& v) {
  return std::all_of(v.cbegin(), v.cend(), [&v](const int e) { return std::count(v.cbegin(), v.cend(), e) == 1; });
}

}  // anonymous namespace

namespace algorithms {

bool ValidateStackSequences(const std::vector<int>& pushed, const std::vector<int>& popped) {
  assert(::AllValuesAreDistinct(pushed) && ::AllValuesAreDistinct(popped));

  if (pushed.size() != popped.size()) {
    return false;
  }

  const std::size_t ps = pushed.size();
  const std::size_t qs = popped.size();
  std::size_t p = 0, q = 0;
  std::stack<int> s;

  while (q < qs) {
    if (!s.empty() && s.top() == popped[q]) {
      s.pop();
      ++q;
    } else if (p < ps) {
      s.push(pushed[p++]);
    } else {
      q = qs;
    }
  }

  return s.empty();
}

}  // namespace algorithms
