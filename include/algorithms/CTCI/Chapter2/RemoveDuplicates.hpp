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
#ifndef ALGORITHMS__CTCI__CHAPTER_2__NO_DUPLICATES__HPP
#define ALGORITHMS__CTCI__CHAPTER_2__NO_DUPLICATES__HPP
#include <list>

namespace algorithms {

/*! \brief Write code to remove duplicates from an unsorted linked list.
 *  \note   Complexity  -> Time: O(N)    Space: O(N)
 */
void RemoveDuplicates(std::list<int>* ioList);

/*! \brief Write code to remove duplicates from an unsorted linked list.
 *  \note   Complexity  -> Time: O(N^2)    Space: O(1)
 */
void RemoveDuplicatesSpaceOptimized(std::list<int>* ioList);

}  // namespace algorithms

#endif  // ALGORITHMS__CTCI__CHAPTER_2__NO_DUPLICATES__HPP
