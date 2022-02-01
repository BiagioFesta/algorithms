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
#ifndef ALGORITHMS__ARRAY__SMALLESTDIVISORTHRESHOLD__HPP
#define ALGORITHMS__ARRAY__SMALLESTDIVISORTHRESHOLD__HPP
#include <vector>

namespace algorithms {

/*! \brief Given an array of integers nums and an integer threshold, we will choose a positive integer divisor, divide
 *  all the array by it, and sum the division's result. Find the smallest divisor such that the result mentioned above
 *  is less than or equal to threshold.
 *
 *  Each result of the division is rounded to the nearest integer greater than or equal to that element.
 *  (For example:  7/3 = 3 and 10/2 = 5).
 *
 *  The test cases are generated so that there will be an answer.
 *
 *  \note Complexity  ->  Time: O(logM)   Space: O(1)   where `M` is max element in `nums`.
 *  \note https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/
 */
int SmallestDivisorThreshold(const std::vector<int>& nums, const int threshold);

}  // namespace algorithms

#endif  // ALGORITHMS__ARRAY__SMALLESTDIVISORTHRESHOLD__HPP
