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
#ifndef ALGORITHMS__DYNAMICPROGRAMMING__PALINDROMEPARTITIONINGII__HPP
#define ALGORITHMS__DYNAMICPROGRAMMING__PALINDROMEPARTITIONINGII__HPP
#include <string>

namespace algorithms {

/*! \brief Given a string s, partition s such that every substring of the
 *  partition is a palindrome.
 *  Return the minimum cuts needed for a palindrome partitioning of s.
 *
 *  \note  Complexity  -->  Time: O(N^3)  Space: O(N^2)
 *  \note https://leetcode.com/problems/palindrome-partitioning-ii/
 */
int PalindromePartitioningII(const std::string& str);

}  // namespace algorithms

#endif  // ALGORITHMS__DYNAMICPROGRAMMING__PALINDROMEPARTITIONINGII__HPP
