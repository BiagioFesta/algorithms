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
#ifndef ALGORITHMS__ARRAY__MAXIMUMEQUALFREQUENCY__HPP
#define ALGORITHMS__ARRAY__MAXIMUMEQUALFREQUENCY__HPP
#include <vector>

namespace algorithms {

/*! \brief Given an array nums of positive integers, return the longest possible length of an array prefix of nums, such
 *  that it is possible to remove exactly one element from this prefix so that every number that has appeared in it will
 *  have the same number of occurrences.
 *
 *  If after removing one element there are no remaining elements, it's still considered that every appeared number has
 *  the same number of ocurrences (0).
 *
 *  \note https://leetcode.com/problems/maximum-equal-frequency/
 */
int MaximumEqualFrequency(const std::vector<int>& nums);

}  // namespace algorithms

#endif  // ALGORITHMS__ARRAY__MAXIMUMEQUALFREQUENCY__HPP
