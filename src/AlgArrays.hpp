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
#include <functional>
#include <string>
#include <vector>

namespace algorithms {

/*! \brief It checks if the array could become non-decreasing by modifying at
 *  most 1 element.
 *  \Complexity     Time: O(N)        Space: O(1)
 *  \url https://leetcode.com/problems/non-decreasing-array/description/
 */
bool isAlmostNonDecreasing(const int* iArray, const int iSize);

/*! \brief Given an array of n positive integers and a positive integer s, it
 *  finds the minimal length of a contiguous subarray of which the sum ≥ s. If
 *  there isn't one, it returns 0 instead.
 *  \url https://leetcode.com/problems/minimum-size-subarray-sum/description/
 */
int minSizeSubArraySum(const int* iArray, const int iSize, int s);

/*! \brief Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array),
 *  some elements appear twice and others appear once.
 *  It finds all the elements of [1, n] inclusive that do not appear in this
 *  array.
 *  \url
 * https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/description/
 */
std::vector<int> findDisappearedNumbers(const std::vector<int>& iVector);

/*! \brief Given an unsorted array of integers, it finds the length of longest
 *  continuous increasing subsequence (subarray).
 *  \Complexity O(n)
 *  \url
 * https://leetcode.com/problems/longest-continuous-increasing-subsequence/description/
 */
int findLengthOfLCIS(const std::vector<int>& iVector);

/*! \brief Given an unsorted integer array, find the smallest missing positive
 *  integer.
 *  \Complexity Time: O(n)      Space: O(1) - it exploits the input.
 *  \url https://leetcode.com/problems/first-missing-positive/description/
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
 *  \url https://www.hackerrank.com/challenges/climbing-the-leaderboard/problem
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
 *  \url https://www.hackerrank.com/challenges/larrys-array/problem
 */
bool larrysArray(const std::vector<int>& iVector);

/*! \brief We define 'P' to be a permutation of the first 'n'  natural numbers
 *  in the range [1, n].
 *  P is considered to be an absolute permutation if:
 *         | P[i] - i | = k
 *  holds true for every i \in [1, n].
 *  \return given 'n' and 'k', it returns the lexicographically smallest
 *  absolute permutation P. If no absolute permutation exists, it returns a
 *  vecotr of {-1}.
 *  Complexity  Time: O(N)    Space: O(N)
 *  \url https://www.hackerrank.com/challenges/absolute-permutation/problem
 */
std::vector<int> absolutePermutation(const int n, const int k);

/*! \brief Given a non-negative number represented as an array of digits, It add
 *  1 to the number ( increment the number represented by the digits ).
 *  \note The digits are stored such that the most significant digit is at the
 *  head of the list.
 *  \Complexity     Time: O(N)   Space O(N)
 *  \url https://leetcode.com/problems/plus-one/description/
 */
std::vector<int> addOneToNumber(const std::vector<int>& iDigits);

/*! \brief Given a list of non negative integers, it arranges them such that
 *  they form the largest number.
 *    Eg:
 *        [3, 30, 34, 5, 9]   ==>   "9534330"
 *  \Complexity   Time: O(NlogN)     Space O(N)
 *  \url https://leetcode.com/problems/largest-number/description/
 */
std::string largestNumber(std::vector<int> iNumbers);

/*! \brief Given an array A of integers, it finds the maximum of j - i subjected
 *  to the constraint of A[i] <= A[j].
 *  \return the maximum the solution. -1 if vector is empty.
 *  \Complexity   Time: O(NlogN)     Space: O(N)
 *  \url https://leetcode.com/problems/maximum-gap/description/
 */
int maximumGap(const std::vector<int>& iVector);

/*! \brief We have two special characters. The first character can be
 *  represented by one bit 0. The second character can be represented by two
 *  bits (10 or 11).
 *  Now given a string represented by several bits.
 *  It returns whether the last character must be a one-bit character or not.
 *  The given string will always end with a zero.
 *  \Complexity   Time: O(N)     Space: O(1)
 *  \url https://leetcode.com/problems/1-bit-and-2-bit-characters/description/
 */
bool isOneBitCharacter(const std::vector<int>& iBits);

/*! \brief Given a binary array, it finds the maximum length of a contiguous
 *  subarray with equal number of 0 and 1.
 *  \note It returns 0 in case no solution.
 *  \Complexity     Time: O(N)    Space: O(N)
 *  \url https://leetcode.com/problems/contiguous-array/description/
 */
int findMaxLength(const std::vector<int>& iBits);

/*! \brief You will be given an array of integers and a target value. It
 *  determines the number of pairs of array elements that have a difference
 *  equal to a target value.
 *  \return The number of pairs.
 *  \Complexity    Time: O(NlogN)    Space: O(N)
 *  \url https://www.hackerrank.com/challenges/pairs/problem
 */
int pairs(std::vector<int> iNums, int iTarget);

/*! \brief Given an array of integers and an integer k, it finds out whether
 *  there are two distinct indices i and j in the array such that iNums[i] =
 *  iNums[j] and the absolute difference between i and j is at most k.
 *  \Complexity   Time: O(N)        Space: O(N)
 *  \url https://leetcode.com/problems/contains-duplicate-ii/description/
 */
bool containsNearbyDuplicate(const std::vector<int>& iNums, const int k);

/*! \brief It checks whether the two inputs are one the permutation of the
 *  other.
 *  \Complexity     Time: O(N)         Space: O(N)  assuming N == M
 */
bool isPermutation(const std::vector<int>& iVectA,
                   const std::vector<int>& iVectB);

/*! \brief Your algorithms have become so good at predicting the market that you
 *  now know what the share price of Wooden Orange Toothpicks Inc. (WOT) will be
 *  for the next number of days.
 *  Each day, you can either buy one share of WOT, sell any number of shares of
 *  WOT that you own, or not make any transaction at all. What is the maximum
 *  profit you can obtain with an optimum trading strategy?
 *  \Complexity    Time: O(N)      Space: O(1)
 *  \url https://www.hackerrank.com/challenges/stockmax/problem
 */
int stockMax(const std::vector<int>& iPrices);

/*! \brief Determine whether an integer is a palindrome. An integer is a
 *  palindrome when it reads the same backward as forward.
 *  \Complexity   Time: O(N)   Space: O(1)   where N: number of digits
 */
bool isPalindrome(int iNumber);

/*! \brief Given an array nums of n integers, are there elements a, b, c in nums
 *  such that a + b + c = 0? Find all unique triplets in the array which gives
 *  the sum of zero.
 *  \note The solution set must not contain duplicate triplets.
 *  \Complexity      Time: O(N^2)    Space: O(1)
 *  \url https://leetcode.com/problems/3sum/description/
 */
std::vector<std::vector<int>> threeSum(std::vector<int>* iNumbers);

/*! \brief Reorders the numbers in the vector in such a way that
 *  all numbers for which the predicate 'iFn' returns true precede the elements
 *  for which predicate 'iFn' returns false. Relative order of the elements is
 *  not preserved (not stable).
 *  \Complexity      Time: O(N)      Space: O(1)
 */
void partition(std::vector<int>* ioVector, std::function<bool(int)> iFn);

/*! \brief Given a sequence of n integers a1, a2, ..., an, a `132 pattern` is a
 *  subsequence ai, aj, ak such that i < j < k and ai < ak < aj.
 *  Design an algorithm that takes a list of n numbers as input and checks
 *  whether there is a 132 pattern in the list.
 *  \Complexity          Time: O(N)     Space: O(N)
 *  \url https://leetcode.com/problems/132-pattern/description/
 */
bool find132pattern(const std::vector<int>& iVector);

/*! \brief It computes the greatest common divisor (GCD) of two numbers.
 *  \url https://en.wikipedia.org/wiki/Euclidean_algorithm
 */
int euclideanAlgorithmGCD(int iNumberA, int iNumberB);

/*! \brief The sieve of Eratosthenes is a simple, ancient algorithm for finding
 *  all prime numbers up to any given limit (iN).
 *  \Complexity      Time: O(N x loglogN)     Space: O(N)
 *  \url https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
 */
std::vector<int> sieveOfEratosthenes(const int iN);

/*! \brief Radix sort is a non-comparative integer sorting algorithm.
 *  \Complexity   Time: O(N)       Space: O(N)
 *  \url https://en.wikipedia.org/wiki/Radix_sort
 */
void radixSort(std::vector<unsigned int>* ioVector);

/*! \brief Given an integer array, find three numbers whose product is maximum
 *  and output the maximum product.
 *  \note The behaviour is undefined is the array is empty.
 *  \Complexity      Time: O(N)       Space: O(1)
 *  \url https://leetcode.com/problems/maximum-product-of-three-numbers/
 */
int maximumProduct(const std::vector<int>& iVector);

/*! \brief Given an array, rotate the array to the right by k steps.
 *  \url https://leetcode.com/problems/rotate-array/
 *  \Complexity        Time: O(N)     Space: O(1)
 *  \note This implementation of the algorithm is less restrictive than the
 *  original assignment. The number of steps to rotate can even be negative
 *  allowing left rotations. Moreover, this solution does not use additional
 *  space.
 */
void rotateRight(std::vector<int>* ioVector, int k);

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
int hIndex(std::vector<int>* iCitations);

}  // namespace algorithms

#endif  // ALGORITHMS__ALG_ARRAYS__HPP
