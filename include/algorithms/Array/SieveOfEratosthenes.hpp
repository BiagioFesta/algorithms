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
#ifndef ALGORITHMS__ARRAY__SIEVE_OF_ERATOSTHENES__HPP
#define ALGORITHMS__ARRAY__SIEVE_OF_ERATOSTHENES__HPP
#include <vector>

namespace algorithms {

/*! \brief The sieve of Eratosthenes is a simple, ancient algorithm for finding
 *  all prime numbers up to any given limit (iN).
 *  \note   Complexity   ->    Time: O(N x loglogN)     Space: O(N)
 *  \note https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
 */
std::vector<int> SieveOfEratosthenes(const int iN);

}  // namespace algorithms

#endif  // ALGORITHMS__ARRAY__SIEVE_OF_ERATOSTHENES__HPP
