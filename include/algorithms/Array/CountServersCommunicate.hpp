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
#ifndef ALGORITHMS__ARRAY__COUNTSERVERSCOMMUNICATE__HPP
#define ALGORITHMS__ARRAY__COUNTSERVERSCOMMUNICATE__HPP
#include <vector>

namespace algorithms {

/*! \brief You are given a map of a server center, represented as a m * n
 *  integer matrix grid, where 1 means that on that cell there is a server and 0
 *  means that it is no server. Two servers are said to communicate if they are
 *  on the same row or on the same column.
 *  Return the number of servers that communicate with any other server.
 *
 *  \note  Complexity  -->  Time: O(M x N)  Space: O(M + N)
 *  \note https://leetcode.com/problems/count-servers-that-communicate/
 */
int CountServersCommunicate(const std::vector<std::vector<int>>& grid);

}  // namespace algorithms

#endif  // ALGORITHMS__ARRAY__COUNTSERVERSCOMMUNICATE__HPP
