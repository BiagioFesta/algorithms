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
#ifndef ALGORITHMS__ARRAY__FILTERRESTAURANTS__HPP
#define ALGORITHMS__ARRAY__FILTERRESTAURANTS__HPP
#include <vector>

namespace algorithms {

/*! \brief Given the array restaurants where  restaurants[i] = [idi, ratingi,
 *  veganFriendlyi, pricei, distancei]. You have to filter the restaurants using
 *  three filters.
 *  The veganFriendly filter will be either true (meaning you should only
 *  include restaurants with veganFriendlyi set to true) or false (meaning you
 *  can include any restaurant). In addition, you have the filters maxPrice and
 *  maxDistance which are the maximum value for price and distance of
 *  restaurants you should consider respectively.
 *  Return the array of restaurant IDs after filtering, ordered by rating from
 *  highest to lowest. For restaurants with the same rating, order them by id
 *  from highest to lowest. For simplicity veganFriendlyi and veganFriendly take
 *  value 1 when it is true, and 0 when it is false.
 *
 *  \note  Complexity  -->  Time: O(NlogN)    Space:(N)
 *  \note
 *  https://leetcode.com/problems/filter-restaurants-by-vegan-friendly-price-and-distance/
 */
std::vector<int> FilterRestaurants(const std::vector<std::vector<int>>& restaurants,
                                   int veganFriendly,
                                   int maxPrice,
                                   int maxDistance);

}  // namespace algorithms

#endif  // ALGORITHMS__ARRAY__FILTERRESTAURANTS__HPP
