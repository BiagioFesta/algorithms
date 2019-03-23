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
#ifndef ALGORITHMS__STRING__CHECK_RECORD__HPP
#define ALGORITHMS__STRING__CHECK_RECORD__HPP
#include <string>

namespace algorithms {

/*! \brief You are given a string representing an attendance record for a
 *  student. The record only contains the following three characters:
 *                 'A' : Absent.
 *                 'L' : Late.
 *                 'P' : Present.
 *  A student could be rewarded if his attendance record doesn't contain more
 *  than one 'A' (absent) or more than two continuous 'L' (late).
 *
 *  You need to return whether the student could be rewarded according to his
 *  attendance record.
 *
 *  \note   Complexity ->    Time: O(N)        Space: O(1)
 *  \note https://leetcode.com/problems/student-attendance-record-i/description/
 */
bool CheckRecord(const std::string& iString);

}  // namespace algorithms

#endif  // ALGORITHMS__STRING__CHECK_RECORD__HPP
