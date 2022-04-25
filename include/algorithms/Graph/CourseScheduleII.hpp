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
#ifndef ALGORITHMS__GRAPH__COURSE_SCHEDULE_II__HPP
#define ALGORITHMS__GRAPH__COURSE_SCHEDULE_II__HPP
#include <vector>

namespace algorithms {

/*! \brief There are a total of n courses you have to take, labeled from 0 to
 *  n-1.
 *  Some courses may have prerequisites, for example to take course 0 you have
 *  to first take course 1, which is expressed as a pair: [0,1]
 *  Given the total number of courses and a list of prerequisite pairs, return
 *  the ordering of courses you should take to finish all courses.
 *  There may be multiple correct orders, you just need to return one of them.
 *  If it is impossible to finish all courses, return an empty array.
 *
 *  \note  Complexity  ->  Time: O(|V| + |E|)   Space: O(|V|)
 *  \note https://leetcode.com/problems/course-schedule-ii/
 */
std::vector<int> CourseScheduleII(const int numCourses, const std::vector<std::vector<int>>& prerequisites);

}  // namespace algorithms

#endif  // ALGORITHMS__GRAPH__COURSE_SCHEDULE_II__HPP
