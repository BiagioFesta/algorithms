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
#ifndef ALGORITHMS__ARRAY__GETEQUALSUBSTRINGSWITHINBUDGET__HPP
#define ALGORITHMS__ARRAY__GETEQUALSUBSTRINGSWITHINBUDGET__HPP
#include <string>

namespace algorithms {

/*! \brief You are given two strings s and t of the same length. You want to
 *  change s to t. Changing the i-th character of s to i-th character of t costs
 *  |s[i] - t[i]| that is, the absolute difference between the ASCII values of
 *  the characters.
 *  You are also given an integer maxCost.
 *  Return the maximum length of a substring of s that can be changed to be the
 *  same as the corresponding substring of twith a cost less than or equal to
 *  maxCost.
 *  If there is no substring from s that can be changed to its corresponding
 *  substring from t, return 0.
 *
 *  \note  Complexity  ->  Time: O(N)  Space: O(1)
 *  \note  https://leetcode.com/problems/get-equal-substrings-within-budget/
 */
int GetEqualSubstringsWithinBudget(const std::string& s, const std::string& t, const int maxCost);

}  // namespace algorithms

#endif  // ALGORITHMS__ARRAY__GETEQUALSUBSTRINGSWITHINBUDGET__HPP
