/*
  Copyright (C) 2021  Biagio Festa

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
#ifndef ALGORITHMS__ARRAY__DETECTPATTERNREPEATED__HPP
#define ALGORITHMS__ARRAY__DETECTPATTERNREPEATED__HPP
#include <vector>

namespace algorithms {

/*! \brief Given an array of positive integers arr,  find a pattern of length m
 *  that is repeated k or more times.
 *  A pattern is a subarray (consecutive sub-sequence) that consists of one or
 *  more values, repeated multiple times consecutively without overlapping. A
 *  pattern is defined by its length and the number of repetitions.
 *  Return true if there exists a pattern of length m that is repeated k or more
 *  times, otherwise return false.
 *
 *  \note   Complexity  -->  Time: O(N x m)     Space: O(1)
 *  \note
 * https://leetcode.com/problems/detect-pattern-of-length-m-repeated-k-or-more-times/
 */
bool DetectPatternRepeated(const std::vector<int>& v, const int m, const int k);

}  // namespace algorithms

#endif  // ALGORITHMS__ARRAY__DETECTPATTERNREPEATED__HPP
