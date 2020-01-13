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
#ifndef ALGORITHMS__ARRAY__FIND_132_PATTERN__HPP
#define ALGORITHMS__ARRAY__FIND_132_PATTERN__HPP
#include <vector>

namespace algorithms {

/*! \brief Given a sequence of n integers a1, a2, ..., an, a `132 pattern` is a
 *  subsequence ai, aj, ak such that i < j < k and ai < ak < aj.
 *  Design an algorithm that takes a list of n numbers as input and checks
 *  whether there is a 132 pattern in the list.
 *  \note  Complexity ->  Time: O(N)     Space: O(N)
 *  \note https://leetcode.com/problems/132-pattern/description/
 */
bool Find132pattern(const std::vector<int>& iVector);

}  // namespace algorithms

#endif  // ALGORITHMS__ARRAY__FIND_132_PATTERN__HPP
