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
#ifndef ALGORITHMS__ARRAY__LARGEST_NUMBER__HPP
#define ALGORITHMS__ARRAY__LARGEST_NUMBER__HPP
#include <string>
#include <vector>

namespace algorithms {

/*! \brief Given a list of non negative integers, it arranges them such that
 *  they form the largest number.
 *    Eg:
 *        [3, 30, 34, 5, 9]   ==>   "9534330"
 *  \note   Complexity -> Time: O(NlogN)     Space O(N)
 *  \note https://leetcode.com/problems/largest-number/description/
 */
std::string LargestNumber(std::vector<int> iNumbers);

}  // namespace algorithms

#endif  // ALGORITHMS__ARRAY__LARGEST_NUMBER__HPP
