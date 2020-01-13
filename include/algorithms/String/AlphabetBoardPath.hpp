/*
  Copyright (C) 2020  Biagio Festa

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
#ifndef ALGORITHMS__STRING__ALPHABETBOARDPATH__HPP
#define ALGORITHMS__STRING__ALPHABETBOARDPATH__HPP
#include <string>

namespace algorithms {

/*! \brief On an alphabet board, we start at position (0, 0), corresponding to
 *  character board[0][0].
 *  Here, board = ["abcde", "fghij", "klmno", "pqrst", "uvwxy", "z"], as shown
 *  in the diagram below.
 *
 *        -------------------
 *        |  a  b  c  d  e  |
 *        |  f  g  h  i  j  |
 *        |  k  l  m  n  o  |
 *        |  p  q  r  s  t  |
 *        |  u  v  w  x  y  |
 *        |  z  |
 *        -------
 *
 *  We may make the following moves:
 *    - 'U' moves our position up one row, if the position exists on the board;
 *    - 'D' moves our position down one row, if the position exists on the
 *          board;
 *    - 'L' moves our position left one column, if the position exists on the
 *          board;
 *    - 'R' moves our position right one column, if the position exists on the
 *          board;
 *    - '!' adds the character board[r][c] at our current position (r, c) to the
 *          answer.
 *  (Here, the only positions that exist on the board are positions with letters
 *  on them.)
 *  Return a sequence of moves that makes our answer equal to target in
 *  the minimum number of moves.  You may return any path that does so.
 *
 *  \note  Complexity  -->  Time: O(N)  Space: O(1)
 *  \note https://leetcode.com/problems/alphabet-board-path/
 */
std::string AlphabetBoardPath(const std::string& target);

}  // namespace algorithms

#endif  // ALGORITHMS__STRING__ALPHABETBOARDPATH__HPP
