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
#ifndef ALGORITHMS__BACKTRACKING__WORD_SEARCH__HPP
#define ALGORITHMS__BACKTRACKING__WORD_SEARCH__HPP
#include <string>
#include <vector>

namespace algorithms {

/*! \brief Given a 2D board and a word, find if the word exists in the grid.
 *  The word can be constructed from letters of sequentially adjacent cell,
 *  where "adjacent" cells are those horizontally or vertically neighboring.
 *  \note The same letter cell may not be used more than once.
 *
 *  \note https://leetcode.com/problems/word-search/
 */
bool WordSearch(const std::vector<std::vector<char>>& iBoard, const std::string& iWord);

}  // namespace algorithms

#endif  // ALGORITHMS__BACKTRACKING__WORD_SEARCH__HPP
