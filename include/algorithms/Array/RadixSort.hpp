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
#ifndef ALGORITHMS__ARRAY__RADIX_SORT__HPP
#define ALGORITHMS__ARRAY__RADIX_SORT__HPP
#include <vector>

namespace algorithms {

/*! \brief Radix sort is a non-comparative integer sorting algorithm.
 *  \note   Complexity ->  Time: O(N)       Space: O(N)
 *  \note https://en.wikipedia.org/wiki/Radix_sort
 */
void RadixSort(std::vector<unsigned int>* ioVector);

}  // namespace algorithms

#endif  // ALGORITHMS__ARRAY__RADIX_SORT__HPP
