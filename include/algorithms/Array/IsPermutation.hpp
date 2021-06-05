/*
  Copyright (C) 2021  Biagio Festa

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
#ifndef ALGORITHMS__ARRAY__IS_PERMUTATION__HPP
#define ALGORITHMS__ARRAY__IS_PERMUTATION__HPP
#include <vector>

namespace algorithms {

/*! \brief It checks whether the two inputs are one the permutation of the
 *  other.
 *  \note   Complexity ->  Time: O(N)         Space: O(N)  assuming N == M
 */
bool IsPermutation(const std::vector<int>& iVectA, const std::vector<int>& iVectB);

}  // namespace algorithms

#endif  // ALGORITHMS__ARRAY__IS_PERMUTATION__HPP
