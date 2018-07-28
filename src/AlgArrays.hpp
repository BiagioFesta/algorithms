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
#ifndef ALGORITHMS__ALG_ARRAYS__HPP
#define ALGORITHMS__ALG_ARRAYS__HPP
#include <vector>

namespace algorithms {

/*! \brief It checks if the array could become non-decreasing by modifying at
 *  most 1 element.
 */
bool isAlmostNonDecreasing(const int* iArray, const int iSize);

/*! \brief Given an array of n positive integers and a positive integer s, it
 *  finds the minimal length of a contiguous subarray of which the sum ≥ s. If
 *  there isn't one, it returns 0 instead.
 */
int minSizeSubArraySum(const int* iArray, const int iSize, int s);

/*! \brief Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array),
 *  some elements appear twice and others appear once.
 *  It finds all the elements of [1, n] inclusive that do not appear in this
 *  array.
 */
std::vector<int> findDisappearedNumbers(const std::vector<int>& iVector);

/*! \brief Given an unsorted array of integers, it finds the length of longest
 *  continuous increasing subsequence (subarray).
 *  \Complexity O(n)
 */
int findLengthOfLCIS(const std::vector<int>& iVector);

/*! \brief Given an unsorted integer array, find the smallest missing positive
 *  integer.
 *  \Complexity Time: O(n)      Space: O(1) - it exploits the input.
 */
int firstMissingPositive(std::vector<int>* iVector);

/*! \brief Alice is playing an arcade game and wants to climb to the top of the
 *  leaderboard.
 *  The game uses Dense Ranking (see wikipedia),
 *  We want to determine Alice's rank as she progresses up the leaderboard.
 *  \param [in] iLeaderBoard   The score-leaderboard of the game (other
 *                             players).
 *                                 Size: M
 *  \param [in] iAliceScores   The final score of each game of Alice.
 *                                 Size: N
 *  \return The position in the leaderboard of Alice after each game (the score
 *  obtained by Alice is identified by the param 'iAliceScores').
 *  \Complexity   Time: O(NlogM)    Space: O(M + N)
 */
std::vector<int> climbingLeaderboard(const std::vector<int>& iLeaderBoard,
                                     const std::vector<int>& iAliceScores);

/*! \brief Larry has been given a permutation of a sequence of natural numbers
 *  incrementing from  1 as an array.
 *  He must determine whether the array can be sorted using the following
 *  operation any number of times:
 *    - Choose any  consecutive indices and rotate their elements in such a way
 *      that:
 *         ABC -> BCA -> CAB -> ABC
 *  \return 'true' if the array can be sorted with rotation operation, 'false'
 *  otherise.
 *  \Complexity   Time: O(N)     Space: O(N)
 */
bool larrysArray(const std::vector<int>& iVector);

}  // namespace algorithms

#endif  // ALGORITHMS__ALG_ARRAYS__HPP
