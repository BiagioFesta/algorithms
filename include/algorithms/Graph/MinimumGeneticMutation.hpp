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
#ifndef ALGORITHMS__GRAPH__MINIMUMGENETICMUTATION__HPP
#define ALGORITHMS__GRAPH__MINIMUMGENETICMUTATION__HPP
#include <string>
#include <vector>

namespace algorithms {

/*! \brief A gene string can be represented by an 8-character long string, with
 *  choices from "A", "C", "G", "T".
 *  Suppose we need to investigate about a mutation (mutation from "start" to
 *  "end"), where ONE mutation is defined as ONE single character changed in the
 *  gene string.
 *  For example, "AACCGGTT" -> "AACCGGTA" is 1 mutation.
 *  Also, there is a given gene "bank", which records all the valid gene
 *  mutations. A gene must be in the bank to make it a valid gene string.
 *  Now, given 3 things - start, end, bank, your task is to determine what is
 *  the minimum number of mutations needed to mutate from "start" to "end". If
 *  there is no such a mutation, return -1.
 *  Note:
 *    1. Starting point is assumed to be valid, so it might not be included in
 *       the bank.
 *    2. If multiple mutations are needed, all mutations during in the sequence
 *       must be valid.
 *    3. You may assume start and end string is not the same.
 *
 *  \note  Complexity  -->  Time: O(N)    Space:O(N)  where N size of bank
 *  \note https://leetcode.com/problems/minimum-genetic-mutation/
 */
int MinimumGeneticMutation(const std::string& start, const std::string& end, const std::vector<std::string>& bank);

}  // namespace algorithms

#endif  // ALGORITHMS__GRAPH__MINIMUMGENETICMUTATION__HPP
