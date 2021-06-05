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
#ifndef ALGORITHMS__STRING__REPEATEDDNASEQUENCES__HPP
#define ALGORITHMS__STRING__REPEATEDDNASEQUENCES__HPP
#include <string>
#include <vector>

namespace algorithms {

/*! \brief All DNA is composed of a series of nucleotides abbreviated as
 *  A, C, G, and T, for example: "ACGAATTCCG". When studying DNA, it is
 *  sometimes useful to identify repeated sequences within the DNA.
 *  Write a function to find all the 10-letter-long sequences (substrings) that
 *  occur more than once in a DNA molecule.
 *
 *  \note  Complexity  ->  Time: O(N)  Space: O(N)
 *  \note https://leetcode.com/problems/repeated-dna-sequences/
 */
std::vector<std::string> RepeatedDNASequences(const std::string& s);

}  // namespace algorithms

#endif  // ALGORITHMS__STRING__REPEATEDDNASEQUENCES__HPP
