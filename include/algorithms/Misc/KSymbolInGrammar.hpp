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
#ifndef ALGORITHMS__MISC__K_SYMBOL_IN_GRAMMAR__HPP
#define ALGORITHMS__MISC__K_SYMBOL_IN_GRAMMAR__HPP

namespace algorithms {

/*! \brief On the first row, we write a 0. Now in every subsequent row, we look
 *         at the previous row and replace each occurrence of 0 with 01, and
 *         each occurrence of 1 with 10.
 *         Given row N and index K, return the K-th indexed symbol in row N.
 *         (The values of K are 1-indexed.) (1 indexed).
 *
 *  \note    Complexity  ->  Time: O(N)   Space: O(1)
 *  \note https://leetcode.com/problems/k-th-symbol-in-grammar/
 */
int KSymbolInGrammar(const int N, const int K);

}  // namespace algorithms

#endif  // ALGORITHMS__MISC__K_SYMBOL_IN_GRAMMAR__HPP
