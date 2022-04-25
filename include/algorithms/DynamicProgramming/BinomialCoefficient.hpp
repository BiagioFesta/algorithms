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
#ifndef ALGORITHMS__DYNAMIC_PROGRAMMING__BINOMIAL_COEFFICIENT__HPP
#define ALGORITHMS__DYNAMIC_PROGRAMMING__BINOMIAL_COEFFICIENT__HPP

namespace algorithms {

/*! \brief It computes the binomial coefficient (n, k)
 *  \note  Complexity -> Time: O(k)    Space: O(1)
 *  \note https://en.wikipedia.org/wiki/Binomial_coefficient
 */
int BinomialCoefficient(const int n, const int k);

}  // namespace algorithms

#endif  // ALGORITHMS__DYNAMIC_PROGRAMMING__BINOMIAL_COEFFICIENT__HPP
