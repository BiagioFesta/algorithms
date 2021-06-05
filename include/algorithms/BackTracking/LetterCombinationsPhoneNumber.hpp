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
#ifndef ALGORITHMS__BACKTRACKING__LETTERCOMBINATIONSPHONENUMBER__HPP
#define ALGORITHMS__BACKTRACKING__LETTERCOMBINATIONSPHONENUMBER__HPP
#include <string>
#include <vector>

namespace algorithms {

/*! \brief Given a string containing digits from 2-9 inclusive, return all
 *  possible letter combinations that the number could represent.
 *  A mapping of digit to letters (just like on the telephone buttons) is given
 *  below. Note that 1 does not map to any letters.
 *
 *       [1:      ]  [2: abc ]  [3: def ]
 *       [4: ghi  ]  [5: jkl ]  [6: mno ]
 *       [7: pqrs ]  [8: tuv ]  [9: wxyz]
 *
 *  \note  Complexity  ->  Time: O(2^N)   Space: O(2^N)
 *  \note https://leetcode.com/problems/letter-combinations-of-a-phone-number/
 */
std::vector<std::string> LetterCombinationsPhoneNumber(const std::string& digits);

}  // namespace algorithms

#endif  // ALGORITHMS__BACKTRACKING__LETTERCOMBINATIONSPHONENUMBER__HPP
