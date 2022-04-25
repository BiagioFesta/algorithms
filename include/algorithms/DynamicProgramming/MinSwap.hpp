/*
  Copyright (C) 2022  Biagio Festa

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
#ifndef ALGORITHMS__DYNAMIC_PROGRAMMING__MIN_SWAP__HPP
#define ALGORITHMS__DYNAMIC_PROGRAMMING__MIN_SWAP__HPP
#include <vector>

namespace algorithms {

/*! \brief We have two integer sequences A and B of the same non-zero length.
 *  We are allowed to swap elements A[i] and B[i].  Note that both elements are
 *  in the same index position in their respective sequences.
 *  At the end of some number of swaps, A and B are both strictly increasing
 *  \note A sequence is strictly increasing if and only if:
 *                A[0] < A[1] < A[2] < ... < A[A.length - 1].
 *  Given A and B, return the minimum number of swaps to make both sequences
 *  strictly increasing.
 *  \note It is guaranteed that the given input always makes it possible.
 *  \note A, B are arrays with the same length, and that length will be in the
 *  range [1, 1000].
 *
 *  \note   Complexity -> Time: O(N)   Space: O(N)
 *  \note The space complexity could be considered O(1) because 1000 max
 *  \note
 * https://leetcode.com/problems/minimum-swaps-to-make-sequences-increasing/
 */
int MinSwap(const std::vector<int>& A, const std::vector<int>& B);

}  // namespace algorithms

#endif  // ALGORITHMS__DYNAMIC_PROGRAMMING__MIN_SWAP__HPP
