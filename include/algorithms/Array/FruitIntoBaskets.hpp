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
#ifndef ALGORITHMS__ARRAY__FRUIT_INTO_BASKETS__HPP
#define ALGORITHMS__ARRAY__FRUIT_INTO_BASKETS__HPP
#include <vector>

namespace algorithms {

/*! \brief In a row of trees, the i-th tree produces fruit with type tree[i].
 *  You start at any tree of your choice, then repeatedly perform the following
 *  steps:
 *       1) Add one piece of fruit from this tree to your baskets.
 *          If you cannot, stop.
 *       2) Move to the next tree to the right of the current tree.
 *          If there is no tree to the right, stop.
 *  Note that you do not have any choice after the initial choice of starting
 *  tree: you must perform step 1, then step 2, then back to step 1, then step
 *  2, and so on until you stop.
 *  You have two baskets, and each basket can carry any quantity of fruit, but
 *  you want each basket to only carry one type of fruit each.
 *  What is the total amount of fruit you can collect with this procedure?
 *
 *  \note  Complexity  ->   Time: O(N)   Space: O(1)
 *  \note https://leetcode.com/problems/fruit-into-baskets/
 */
int FruitIntoBaskets(const std::vector<int>& tree);

}  // namespace algorithms

#endif  // ALGORITHMS__ARRAY__FRUIT_INTO_BASKETS__HPP
