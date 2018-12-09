/*
  Copyright (C) 2018  Biagio Festa

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
#ifndef ALGORITHMS__ARRAY__H_INDEX__HPP
#define ALGORITHMS__ARRAY__H_INDEX__HPP
#include <vector>

namespace algorithms {

/*! \brief Given an array of citations (each citation is a non-negative integer)
 *  of a researcher, write a function to compute the researcher's h-index.
 *
 *  According to the definition of h-index on Wikipedia: "A scientist has
 *  index h if h of his/her N papers have at least h citations each, and the
 *  other N − h papers have no more than h citations each."
 *
 *  \Complexity       Time: O(NlogN)     Space: O(1)
 *  \url https://leetcode.com/problems/h-index/
 */
int HIndex(std::vector<int>* iCitations);

/*! \brief Given an array of citations (each citation is a non-negative integer)
 *  of a researcher, write a function to compute the researcher's h-index.
 *
 *  According to the definition of h-index on Wikipedia: "A scientist has
 *  index h if h of his/her N papers have at least h citations each, and the
 *  other N − h papers have no more than h citations each."
 *
 *  \see hIndex
 *  \Complexity       Time: O(N)     Space: O(N)
 *  \url https://leetcode.com/problems/h-index/
 */
int HIndexLinear(const std::vector<int>& iCitations);

}  // namespace algorithms

#endif  // ALGORITHMS__ARRAY__H_INDEX__HPP
