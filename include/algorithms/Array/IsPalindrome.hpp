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
#ifndef ALGORITHMS__ARRAY__IS_PALINDROME__HPP
#define ALGORITHMS__ARRAY__IS_PALINDROME__HPP

namespace algorithms {

/*! \brief Determine whether an integer is a palindrome. An integer is a
 *  palindrome when it reads the same backward as forward.
 *  \note  Complexity  -> Time: O(N)   Space: O(1)   where N: number of digits
 */
bool IsPalindrome(int iNumber);

}  // namespace algorithms

#endif  // ALGORITHMS__ARRAY__IS_PALINDROME__HPP
