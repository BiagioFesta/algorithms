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
#ifndef ALGORITHMS__ARRAY__PLUS_ONE__HPP
#define ALGORITHMS__ARRAY__PLUS_ONE__HPP
#include <vector>

namespace algorithms {

/*! \brief Given a non-negative number represented as an array of digits, It add
 *  1 to the number ( increment the number represented by the digits ).
 *  \note The digits are stored such that the most significant digit is at the
 *  head of the list.
 *  \note   Complexity  ->   Time: O(N)   Space: O(N)
 *  \note https://leetcode.com/problems/plus-one/description/
 */
std::vector<int> PlusOne(const std::vector<int>& iDigits);

}  // namespace algorithms

#endif  // ALGORITHMS__ARRAY__PLUS_ONE__HPP
