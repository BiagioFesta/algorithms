/*
  Copyright (C) 2019  Biagio Festa

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
#ifndef ALGORITHMS__DYNAMIC_PROGRAMMING__KEYSTROKE__HPP
#define ALGORITHMS__DYNAMIC_PROGRAMMING__KEYSTROKE__HPP

namespace algorithms {

/*! \brief You are given following four keys on a keyboard:
 *    1. print A (print a single character A)
 *    2. Ctrl-A (Select All)
 *    3. Ctrl-C (Copy selected content)
 *    4. Ctrl-V (Append the selected content right next to already printed
 *       content).
 *
 *  Pressing any of the above keys is considered a single keystroke. You need to
 *  find out the maximum number of A's you can print using N such keystrokes.
 *  \note  Complexity ->  Time: O(N^2)     Space: O(N)
 *  \note
 * https://www.geeksforgeeks.org/how-to-print-maximum-number-of-a-using-given-four-keys/
 */
int Keystroke(const int N);

}  // namespace algorithms

#endif  // ALGORITHMS__DYNAMIC_PROGRAMMING__KEYSTROKE__HPP
