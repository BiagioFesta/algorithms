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
#ifndef ALGORITHMS__ARRAY__VALIDATESTACKSEQUENCES__HPP
#define ALGORITHMS__ARRAY__VALIDATESTACKSEQUENCES__HPP
#include <vector>

namespace algorithms {

/*! \brief Given two sequences pushed and popped with distinct values, return
 *  true if and only if this could have been the result of a sequence of push
 *  and pop operations on an initially empty stack.
 *
 *  \note  Complexity   -->  Time: O(N)   Space: O(N)
 *  \note https://leetcode.com/problems/validate-stack-sequences/
 */
bool ValidateStackSequences(const std::vector<int>& pushed,
                            const std::vector<int>& popped);

}  // namespace algorithms

#endif  // ALGORITHMS__ARRAY__VALIDATESTACKSEQUENCES__HPP
