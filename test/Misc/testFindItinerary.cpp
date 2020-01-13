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
#include <gtest/gtest.h>
#include <algorithms/Misc/FindItinerary.hpp>
#include <string>
#include <utility>
#include <vector>

namespace algorithms::test {

TEST(Misc, FindItinerary) {
  using Test = std::pair<std::vector<std::vector<std::string>>,
                         std::vector<std::string>>;
  const std::vector<Test> testCases = {
      {{{"JFK", "AAA"}, {"JFK", "BBB"}, {"BBB", "JFK"}},
       {"JFK", "BBB", "JFK", "AAA"}},
      {{{"JFK", "SFO"},
        {"JFK", "ATL"},
        {"SFO", "ATL"},
        {"ATL", "JFK"},
        {"ATL", "SFO"}},
       {"JFK", "ATL", "JFK", "SFO", "ATL", "SFO"}},
      {{{"JFK", "KUL"}, {"JFK", "NRT"}, {"NRT", "JFK"}},
       {"JFK", "NRT", "JFK", "KUL"}},
      {{{"EZE", "TIA"},
        {"EZE", "AXA"},
        {"AUA", "EZE"},
        {"EZE", "JFK"},
        {"JFK", "ANU"},
        {"JFK", "ANU"},
        {"AXA", "TIA"},
        {"JFK", "AUA"},
        {"TIA", "JFK"},
        {"ANU", "EZE"},
        {"ANU", "EZE"},
        {"TIA", "AUA"}},
       {"JFK",
        "ANU",
        "EZE",
        "AXA",
        "TIA",
        "AUA",
        "EZE",
        "JFK",
        "ANU",
        "EZE",
        "TIA",
        "JFK",
        "AUA"}}};

  for (const auto& [tickets, expt] : testCases) {
    ASSERT_EQ(FindItinerary(tickets), expt);
  }
}

}  // namespace algorithms::test
