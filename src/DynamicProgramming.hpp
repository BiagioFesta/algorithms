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

namespace algorithms {

/*! \brief It computes the binomial coefficient (n, k)
 *  \complexity Time O(k) Space O(k)
 */
int binomialCoefficient(const int n, const int k);

/*! \brief It computes the n-th fibonacci number.
 *  \note n must to be greater or equal zero.
 *  \complexity Time O(n)  Space O(n)
 */
int fibonacci(const int n);

}  // namespace algorithms

#endif  // ALGORITHMS__DYNAMIC_PROGRAMMING__HPP
