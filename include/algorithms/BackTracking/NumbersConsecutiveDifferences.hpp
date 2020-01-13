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
#ifndef ALGORITHMS__BACKTRACKING__NUMBERSCONSECUTIVEDIFFERENCES__HPP
#define ALGORITHMS__BACKTRACKING__NUMBERSCONSECUTIVEDIFFERENCES__HPP
#include <vector>

namespace algorithms {

/*! \brief Return all non-negative integers of length N such that the absolute
 *  difference between every two consecutive digits is K.
 *  Note that every number in the answer must not have leading zeros except for
 *  the number 0 itself. For example, 01 has one leading zero and is invalid,
 *  but 0 is valid.
 *  You may return the answer in any order.
 *  \note 1 <= N <= 9
 *  \note 0 <= K <= 9
 *
 *  \note  Complexity  -->  Time: O(2^N)  Space: O(N)
 *  \note
 * https://leetcode.com/problems/numbers-with-same-consecutive-differences/
 */
std::vector<int> NumbersConsecutiveDifferences(const int N, const int K);

}  // namespace algorithms

#endif  // ALGORITHMS__BACKTRACKING__NUMBERSCONSECUTIVEDIFFERENCES__HPP
