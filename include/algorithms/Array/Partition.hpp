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
#ifndef ALGORITHMS__ARRAY__PARTITION__HPP
#define ALGORITHMS__ARRAY__PARTITION__HPP
#include <functional>
#include <vector>

namespace algorithms {

/*! \brief Reorders the numbers in the vector in such a way that
 *  all numbers for which the predicate 'iFn' returns true precede the elements
 *  for which predicate 'iFn' returns false. Relative order of the elements is
 *  not preserved (not stable).
 *  \note   Complexity  ->    Time: O(N)      Space: O(1)
 */
void Partition(std::vector<int>* ioVector, std::function<bool(int)> iFn);

}  // namespace algorithms

#endif  // ALGORITHMS__ARRAY__PARTITION__HPP
