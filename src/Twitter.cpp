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
#include "Twitter.hpp"
#include <algorithm>
#include <cassert>
#include <set>
#include <stdexcept>
#include <string>

namespace algorithms {

void Twitter::postTweet(const UserId_t userId, const TweetId_t tweetId) {
  _user2tweets[userId].emplace_back(tweetId, _tweetCounter++);
}

std::vector<Twitter::TweetId_t> Twitter::getNewsFeed(const UserId_t userId) {
  constexpr std::size_t kFeedsSize = 10;

  std::vector<TweetId_t> feeds;
  feeds.reserve(kFeedsSize);

  const auto& followees = _user2followee[userId];

  std::vector<RefTweetList_t> aCandidateFeeds;
  aCandidateFeeds.reserve(1 + followees.size());

  aCandidateFeeds.emplace_back(_user2tweets[userId]);
  for (const auto& aFollowee : followees) {  // O(|F|)
    aCandidateFeeds.emplace_back(_user2tweets[aFollowee]);
  }

  bool candidatesCompleted = false;
  while ((feeds.size() < kFeedsSize) && (!candidatesCompleted)) {  // O(10)
    const auto aMostRecent = std::max_element(aCandidateFeeds.begin(),
                                              aCandidateFeeds.end());  // O(|F|)
    assert(aMostRecent != aCandidateFeeds.end());

    if (aMostRecent->isIndexValid()) {
      feeds.push_back(aMostRecent->getTweetOnIndex().first);
      aMostRecent->advanceIndex();
    } else {
      candidatesCompleted = true;
    }
  }

  return feeds;
}

void Twitter::follow(const UserId_t followerId, const UserId_t followeeId) {
  if (followeeId != followerId) {
    _user2followee[followerId].insert(followeeId);
  }
}

void Twitter::unfollow(const UserId_t followerId, const UserId_t followeeId) {
  _user2followee[followerId].erase(followeeId);
}

const Twitter::ListTweets_t& Twitter::getTweetsListOfUser(
    const UserId_t userId) {
  return _user2tweets[userId];
}

const std::set<Twitter::UserId_t>& Twitter::getFollowees(
    const UserId_t userId) {
  return _user2followee[userId];
}

Twitter::RefTweetList_t::RefTweetList_t(const ListTweets_t& iRefListTweet)
    : _refListTweet(iRefListTweet), _index(iRefListTweet.size()) {}

bool Twitter::RefTweetList_t::isIndexValid() const noexcept {
  return _index != 0ull;
}

const Twitter::MetaTweet_t& Twitter::RefTweetList_t::getTweetOnIndex() const {
  assert(isIndexValid());
  return _refListTweet[_index - 1];
}

void Twitter::RefTweetList_t::advanceIndex() noexcept {
  if (isIndexValid()) {
    --_index;
  }
}

bool Twitter::RefTweetList_t::operator<(const RefTweetList_t& oth) const {
  if (!oth.isIndexValid()) return false;
  if (!isIndexValid()) return true;

  return getTweetOnIndex().second < oth.getTweetOnIndex().second;
}

}  // namespace algorithms
