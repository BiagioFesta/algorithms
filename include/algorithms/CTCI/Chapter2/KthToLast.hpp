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
#ifndef ALGORITHMS__CTCI__CHAPTER_2__KTH_TO_LAST__HPP
#define ALGORITHMS__CTCI__CHAPTER_2__KTH_TO_LAST__HPP
#include <forward_list>

namespace algorithms {

/*! \brief Implement an algorithm to find the kth to last element of a singly
 *  linked list.
 *  \note The behaviour is undefined if `k` is negative.
 *  \note The behaviour is undegined if `k` is greater or equal the size of the
 *  list.
 *  \note  Complexity  ->   Time: O(N)    Space: O(1)
 */
int KthToLast(const std::forward_list<int>& iList, int k);

}  // namespace algorithms

#endif  // ALGORITHMS__CTCI__CHAPTER_2__KTH_TO_LAST__HPP
