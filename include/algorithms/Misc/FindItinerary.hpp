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
#ifndef ALGORITHMS__MISC__FIND_ITINERARY__HPP
#define ALGORITHMS__MISC__FIND_ITINERARY__HPP
#include <string>
#include <vector>

namespace algorithms {

/*! \brief Given a list of airline tickets represented by pairs of departure and
 *  arrival airports [from, to], reconstruct the itinerary in order. All of the
 *  tickets belong to a man who departs from JFK. Thus, the itinerary must begin
 *  with JFK.
 *
 *  \note   Complexity  ->  Time: O(NlogN)   Space: O(N)
 *  \note https://leetcode.com/problems/reconstruct-itinerary/
 */
std::vector<std::string> FindItinerary(const std::vector<std::vector<std::string>>& tickets);

}  // namespace algorithms

#endif  // ALGORITHMS__MISC__FIND_ITINERARY__HPP
