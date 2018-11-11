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
#ifndef ALGORITHMS__DYNAMIC_PROGRAMMING__HPP
#define ALGORITHMS__DYNAMIC_PROGRAMMING__HPP
#include <string>
#include <vector>

namespace algorithms {

/*! \brief It computes the binomial coefficient (n, k)
 *  \complexity Time O(k) Space O(k)
 */
int binomialCoefficient(const int n, const int k);

/*! \brief It computes the n-th fibonacci number.
 *  \note n must to be greater or equal zero.
 *  \complexity Time O(n)  Space O(1)
 */
int fibonacci(const int n);

/*! \brief Given a M x N grid filled with non-negative numbers, it finds a path
 *  from top left to bottom right which minimizes the sum of all numbers along
 *  its path.
 *  \note It assumes you can only move either down or right at any point in
 *  time.
 *  \note M and N must be positive (> 0).
 *  \complexity Time (M x N)    Space (M x N)
 */
int minPathSum(const int* const iMatrix, const int M, const int N);

/*! \brief It returns the longest common subsequence among two strings.
 *  \complexity  Time: (N x M)   Space : (N x M)
 */
int longestCommonSubsequence(const std::string& iStr1,
                             const std::string& iStr2);

/*! \brief The algorithm has to create an array A such that:
 *              1 <= A[i] <= iUpperBounds[i]
 *  For each possible array A, the algorithm will return the "best A".
 *  The "best A" is that the sum of the absolute difference of consecutive pairs
 *  is maximized.
 *   I.e.     S = sum_i |A[i] - A[i - 1]|
 *  \return S
 *  \complexity  Time O(N)    Space O(1)
 */
int sherlockAndCost(const std::vector<int>& iUpperBounds);

/*! \brief Given a number as a string, no leading zeros, it determines the sum
 *  of all integer values of substrings of the string.
 *  \note As the number may become large, return the value modulo (10^9 + 7).
 &  \complexity   Time O(N)    Space  O(1)
 */
int substringsSum(const std::string& iStr);

/*! \brief You are given following four keys on a keyboard:
 *    1. print A (print a single character A)
 *    2. Ctrl-A (Select All)
 *    3. Ctrl-C (Copy selected content)
 *    4. Ctrl-V (Append the selected content right next to already printed
 *       content).
 *
 *  Pressing any of the above keys is considered a single keystroke. You need to
 *  find out the maximum number of A's you can print using N such keystrokes.
 *  \Complexity    Time: O(N^2)         Space: O(N)
 */
int keystroke(const int N);

/*! \brief Say you have an array for which the i-th element is the price of a
 *  given stock on day i.
 *  Design an algorithm to find the maximum profit. You may complete at most two
 *  transactions.
 *  \note You may not engage in multiple transactions at the same time (i.e.,
 *  you must sell the stock before you buy again).
 *  \url
 *  https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/
 *  \Complexity:    Time: O(N)      Space: O(N)
 */
int maxProfit(const std::vector<int>& iPrices);

/*! \brief In the video game Fallout 4, the quest "Road to Freedom" requires
 *  players to reach a metal dial called the "Freedom Trail Ring", and use the
 *  dial to spell a specific keyword in order to open the door.
 *
 *  Given a string ring, which represents the code engraved on the outer ring
 *  and another string key, which represents the keyword needs to be spelled.
 *  You need to find the minimum number of steps in order to spell all the
 *  characters in the keyword.
 *
 *  Initially, the first character of the ring is aligned at 12:00 direction.
 *  You need to spell all the characters in the string key one by one by
 *  rotating the ring clockwise or anticlockwise to make each character of the
 *  string key aligned at 12:00 direction and then by pressing the center
 *  button.
 *
 *  At the stage of rotating the ring to spell the key character key[i]:
 *     1. You can rotate the ring clockwise or anticlockwise one place, which
 *        counts as 1 step. The final purpose of the rotation is to align one of
 *        the string ring's characters at the 12:00 direction, where this
 *        character must equal to the character key[i].
 *     2. If the character key[i] has been aligned at the 12:00 direction, you
 *        need to press the center button to spell, which also counts as 1 step.
 *        After the pressing, you could begin to spell the next character in the
 *        key (next stage), otherwise, you've finished all the spelling.
 *  \note It's guaranteed that string key could always be spelled by rotating
 *   the string ring.
 *
 *  \Complexity    Time: O(K x R^2)     Space:  O(K x R)
 *      where `K` is size of iKey    and `R` is size of iRing
 *
 *  \url https://leetcode.com/problems/freedom-trail/description/
 */
int findRotateSteps(const std::string_view iRing, const std::string_view iKey);

}  // namespace algorithms

#endif  // ALGORITHMS__DYNAMIC_PROGRAMMING__HPP
