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

}  // namespace algorithms

#endif  // ALGORITHMS__DYNAMIC_PROGRAMMING__HPP
