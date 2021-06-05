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
#ifndef ALGORITHMS__MISC__BROKENCALCULATOR__HPP
#define ALGORITHMS__MISC__BROKENCALCULATOR__HPP

namespace algorithms {

/*! \brief On a broken calculator that has a number showing on its display, we
 *  can perform two operations:
 *       - Double: Multiply the number on the display by 2, or;
 *       - Decrement: Subtract 1 from the number on the display.
 *  Initially, the calculator is displaying the number X.
 *  Return the minimum number of operations needed to display the number Y.
 *
 *  \note https://leetcode.com/problems/broken-calculator/
 */
int BrokenCalculator(int x, int y) noexcept;

}  // namespace algorithms

#endif  // ALGORITHMS__MISC__BROKENCALCULATOR__HPP
