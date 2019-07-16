/*
  Copyright (C) 2019  Biagio Festa

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
#ifndef ALGORITHMS__ARRAY__ADVANTAGESHUFFLE__HPP
#define ALGORITHMS__ARRAY__ADVANTAGESHUFFLE__HPP
#include <vector>

namespace algorithms {

/*! \brief Given two arrays A and B of equal size, the advantage of A with
 *  respect to B is the number of indices i for which A[i] > B[i].
 *  Return any permutation of A that maximizes its advantage with respect to B.
 *
 *  \note  Complexity  -->  Time: O(NlogN)   Space: O(N)
 *  \note https://leetcode.com/problems/advantage-shuffle/
 */
std::vector<int> AdvantageShuffle(const std::vector<int>& A,
                                  const std::vector<int>& B);

}  // namespace algorithms

#endif  // ALGORITHMS__ARRAY__ADVANTAGESHUFFLE__HPP
