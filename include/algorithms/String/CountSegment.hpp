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
#ifndef ALGORITHMS__STRING__COUNT_SEGMENT__HPP
#define ALGORITHMS__STRING__COUNT_SEGMENT__HPP

namespace algorithms {

/*! \brief It counts the number of segments in a string, where a segment is
 *  defined to be a contiguous sequence of non-space characters.
 *  \note The string must not contain any non-printable character.
 *  \note Complexity ->  Time: O(N)   Space: O(1)
 *  \note https://leetcode.com/articles/number-of-segments-in-a-string/
 */
int CountSegment(const char* iStr);

}  // namespace algorithms

#endif  // ALGORITHMS__STRING__COUNT_SEGMENT__HPP
