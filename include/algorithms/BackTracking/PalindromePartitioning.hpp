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
#ifndef ALGORITHMS__BACKTRACKING__PALINDROMEPARTITIONING__HPP
#define ALGORITHMS__BACKTRACKING__PALINDROMEPARTITIONING__HPP
#include <string>
#include <vector>

namespace algorithms {

/*! \brief Given a string s, partition s such that every substring of the
 *  partition is a palindrome.
 *  Return all possible palindrome partitioning of s.
 *
 *  \note  Complexity  -->  Time: O(2^n)  Space: O(2^n)
 *  \note https://leetcode.com/problems/palindrome-partitioning/
 */
std::vector<std::vector<std::string>> PalindromePartitioning(const std::string& s);

}  // namespace algorithms

#endif  // ALGORITHMS__BACKTRACKING__PALINDROMEPARTITIONING__HPP
