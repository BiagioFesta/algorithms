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
#ifndef ALGORITHMS__ARRAY__ABSOLUTE_PERMUTATION__HPP
#define ALGORITHMS__ARRAY__ABSOLUTE_PERMUTATION__HPP
#include <vector>

namespace algorithms {

/*! \brief We define 'P' to be a permutation of the first 'n'  natural numbers
 *  in the range [1, n].
 *  P is considered to be an absolute permutation if:
 *         | P[i] - i | = k
 *  holds true for every i \in [1, n].
 *  \return given 'n' and 'k', it returns the lexicographically smallest
 *  absolute permutation P. If no absolute permutation exists, it returns a
 *  vecotr of {-1}.
 *  \note  Complexity -> Time: O(N)    Space: O(N)
 *  \note https://www.hackerrank.com/challenges/absolute-permutation/problem
 */
std::vector<int> AbsolutePermutation(const int n, const int k);

}  // namespace algorithms

#endif  // ALGORITHMS__ARRAY__ABSOLUTE_PERMUTATION__HPP
