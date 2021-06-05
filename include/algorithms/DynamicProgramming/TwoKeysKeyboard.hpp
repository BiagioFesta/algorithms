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
#ifndef ALGORITHMS__DYNAMICPROGRAMMING__TWOKEYSKEYBOARD__HPP
#define ALGORITHMS__DYNAMICPROGRAMMING__TWOKEYSKEYBOARD__HPP

namespace algorithms {

/*! \brief Initially on a notepad only one character 'A' is present. You can
 *  perform two operations on this notepad for each step:
 *    1. Copy All: You can copy all the characters present on the notepad
         (partial copy is not allowed).
 *    2. Paste: You can paste the characters which are copied last time.
 *  Given a number n. You have to get exactly n 'A' on the notepad by performing
 *  the minimum number of steps permitted. Output the minimum number of steps to
 *  get n 'A'.
 *
 *  \note  Complexity  -->  Time: O(N^2)  Space: O(N^2)
 *  \note https://leetcode.com/problems/2-keys-keyboard/
 */
int TwoKeysKeyboard(const int n);

}  // namespace algorithms

#endif  // ALGORITHMS__DYNAMICPROGRAMMING__TWOKEYSKEYBOARD__HPP
