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
#ifndef ALGORITHMS__BACKTRACKING__HPP
#define ALGORITHMS__BACKTRACKING__HPP
#include <vector>

namespace algorithms {

/*! \brief Given a set of candidate numbers (candidates) (without duplicates)
 *  and a target number (target), find all unique combinations in candidates
 *  where the candidate numbers sums to target.
 *
 *  The same repeated number may be chosen from candidates unlimited number of
 *  times.
 *
 *  \note All numbers (including target) will be positive integers.
 *  \note The solution set must not contain duplicate combinations.
 */
std::vector<std::vector<int>> combinationSum(
    const std::vector<int>& iCandidates,
    const int iTarget);

/*! \brief It finds all possible combinations of K numbers that add up to a
 *  number N, given that only numbers from 1 to 9 can be used and each
 *  combination should be a unique set of numbers (cannot pick the same number
 *  in the same combination).
 *  \note All numbers will be positive integers (K and N).
 *  \note The solution set must not contain duplicate combinations.
 *  \complexity         Time:  O(9^K)     Space: O(K)
 *  \url https://leetcode.com/problems/combination-sum-iii/description/
 */
std::vector<std::vector<int>> combinationSum3(const int K, const int N);

}  // namespace algorithms

#endif  // ALGORITHMS__BACKTRACKING__HPP
