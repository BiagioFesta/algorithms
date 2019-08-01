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
#include <algorithms/Array/MaximumAbsoluteValueExpression.hpp>
#include <array>
#include <cassert>
#include <cmath>
#include <cstring>
#include <limits>
#include <vector>

namespace algorithms {

/* Note that:
 *   |A| + |B| = max(A+B, A-B, -A+B, -A-B)
 *
 *   then   |ai - aj| + |bi - bj| + |i - j|
 *              Aij        Bij        Cij
 *
 *   |A| + |B| + |C|  =  max(A+B+C, A-B+C, A+B-C, ...)
 *
 *   For each i,j becomes:
 *     (i, j) = |Aij| + |Bij| + |Cij|
 *            = max(Aij + Bij + Cij, ...)
 *            = max(ai -aj + bi - bj + i -j, ...)
 *            = max(ai + bi +i - aj - bj -j, ...)
 *
 *  Note now we can split in two:
 *      ai + bi + i   ->  c1
 *     -aj - bj - j   ->  c2
 */
int MaximumAbsoluteValueExpression(const std::vector<int>& arr1,
                                   const std::vector<int>& arr2) {
  assert(arr1.size() == arr2.size());
  const int kSize = arr1.size();
  int c1 = std::numeric_limits<int>::min();
  int c2 = std::numeric_limits<int>::min();
  int c3 = std::numeric_limits<int>::min();
  int c4 = std::numeric_limits<int>::min();
  int c5 = std::numeric_limits<int>::min();
  int c6 = std::numeric_limits<int>::min();
  int c7 = std::numeric_limits<int>::min();
  int c8 = std::numeric_limits<int>::min();

  for (int i = 0; i < kSize; ++i) {
    c1 = std::max(c1, arr1[i] + arr2[i] + i);
    c2 = std::max(c2, -arr1[i] + arr2[i] + i);
    c3 = std::max(c3, arr1[i] - arr2[i] + i);
    c4 = std::max(c4, arr1[i] + arr2[i] - i);
    c5 = std::max(c5, -arr1[i] - arr2[i] + i);
    c6 = std::max(c6, arr1[i] - arr2[i] - i);
    c7 = std::max(c7, -arr1[i] + arr2[i] - i);
    c8 = std::max(c8, -arr1[i] - arr2[i] - i);
  }

  return std::max(std::max(c1 + c8, c2 + c6), std::max(c3 + c7, c4 + c5));
}

}  // namespace algorithms
