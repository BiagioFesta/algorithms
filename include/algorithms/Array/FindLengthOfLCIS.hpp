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
#ifndef ALGORITHMS__ARRAY__FIND_LENGTH_OF_LCIS__HPP
#define ALGORITHMS__ARRAY__FIND_LENGTH_OF_LCIS__HPP
#include <vector>

namespace algorithms {

/*! \brief Given an unsorted array of integers, it finds the length of longest
 *  continuous increasing subsequence (subarray).
 *  \Complexity    Time:  O(N)
 *  \url
 * https://leetcode.com/problems/longest-continuous-increasing-subsequence/description/
 */
int FindLengthOfLCIS(const std::vector<int>& iVector);

}  // namespace algorithms

#endif  // ALGORITHMS__ARRAY__FIND_LENGTH_OF_LCIS__HPP
