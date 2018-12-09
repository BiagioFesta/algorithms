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
#ifndef ALGORITHMS__DYNAMIC_PROGRAMMING__FIND_ROTATE_STEPS__HPP
#define ALGORITHMS__DYNAMIC_PROGRAMMING__FIND_ROTATE_STEPS__HPP
#include <string_view>

namespace algorithms {

/*! \brief In the video game Fallout 4, the quest "Road to Freedom" requires
 *  players to reach a metal dial called the "Freedom Trail Ring", and use the
 *  dial to spell a specific keyword in order to open the door.
 *
 *  Given a string ring, which represents the code engraved on the outer ring
 *  and another string key, which represents the keyword needs to be spelled.
 *  You need to find the minimum number of steps in order to spell all the
 *  characters in the keyword.
 *
 *  Initially, the first character of the ring is aligned at 12:00 direction.
 *  You need to spell all the characters in the string key one by one by
 *  rotating the ring clockwise or anticlockwise to make each character of the
 *  string key aligned at 12:00 direction and then by pressing the center
 *  button.
 *
 *  At the stage of rotating the ring to spell the key character key[i]:
 *     1. You can rotate the ring clockwise or anticlockwise one place, which
 *        counts as 1 step. The final purpose of the rotation is to align one of
 *        the string ring's characters at the 12:00 direction, where this
 *        character must equal to the character key[i].
 *     2. If the character key[i] has been aligned at the 12:00 direction, you
 *        need to press the center button to spell, which also counts as 1 step.
 *        After the pressing, you could begin to spell the next character in the
 *        key (next stage), otherwise, you've finished all the spelling.
 *  \note It's guaranteed that string key could always be spelled by rotating
 *   the string ring.
 *
 *  \note  Complexity ->    Time: O(K x R^2)     Space:  O(K x R)
 *      where `K` is size of iKey    and `R` is size of iRing
 *
 *  \note https://leetcode.com/problems/freedom-trail/description/
 */
std::size_t FindRotateSteps(const std::string_view iRing,
                            const std::string_view iKey);

}  // namespace algorithms

#endif  // ALGORITHMS__DYNAMIC_PROGRAMMING__FIND_ROTATE_STEPS__HPP
