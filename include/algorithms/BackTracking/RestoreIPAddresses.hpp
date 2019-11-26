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
#ifndef ALGORITHMS__BACKTRACKING__RESTOREIPADDRESSES__HPP
#define ALGORITHMS__BACKTRACKING__RESTOREIPADDRESSES__HPP
#include <string>
#include <vector>

namespace algorithms {

/*! \brief Given a string containing only digits, restore it by returning all
 *  possible valid IP address combinations.
 *
 *  \note  Complexity  -->  Time: O(1)  Space: O(1)  Because IP format is fixed.
 *  \note https://leetcode.com/problems/restore-ip-addresses/
 */
std::vector<std::string> RestoreIPAddresses(const std::string& s);

}  // namespace algorithms

#endif  // ALGORITHMS__BACKTRACKING__RESTOREIPADDRESSES__HPP
