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
#ifndef ALGORITHMS__ARRAY__DECKINCREASINGREVEAL__HPP
#define ALGORITHMS__ARRAY__DECKINCREASINGREVEAL__HPP
#include <vector>

namespace algorithms {

/*! \brief In a deck of cards, every card has a unique integer.  You can order
 *  the deck in any order you want.
 *  Initially, all the cards start face down (unrevealed) in one deck.
 *  Now, you do the following steps repeatedly, until all cards are revealed:
 *     1. Take the top card of the deck, reveal it, and take it out of the deck.
 *     2. If there are still cards in the deck, put the next top card of the
 *        deck at the bottom of the deck.
 *     3. If there are still unrevealed cards, go back to step 1.  Otherwise,
 *        stop.
 *  Return an ordering of the deck that would reveal the cards in increasing
 *  order.
 *  The first entry in the answer is considered to be the top of the deck.
 *
 *  \note  Complexity  -->   Time: O(N^2)   Space: O(N)
 *  \note https://leetcode.com/problems/reveal-cards-in-increasing-order/
 */
std::vector<int> DeckIncreasingReveal(std::vector<int> deck);

}  // namespace algorithms

#endif  // ALGORITHMS__ARRAY__DECKINCREASINGREVEAL__HPP
