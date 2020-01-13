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
#include <algorithms/Twitter/Twitter.hpp>
#include <vector>

namespace algorithms::test {

class TwitterTest : public Twitter {
 public:
  static constexpr UserId_t kUserIdA = 1;
  static constexpr UserId_t kUserIdB = 2;
  static constexpr TweetId_t kTwitterA = 5;
  static constexpr TweetId_t kTwitterB = 6;
  static const std::vector<TweetId_t> kFeedsA;
  static const std::vector<TweetId_t> kFeedsBA;

  using Twitter::getFollowees;
  using Twitter::getTweetsListOfUser;
};

const std::vector<Twitter::TweetId_t> TwitterTest::kFeedsA{kTwitterA};
const std::vector<Twitter::TweetId_t> TwitterTest::kFeedsBA{kTwitterB,
                                                            kTwitterA};

TEST(Twitter, PostTweet) {
  TwitterTest aTwitter;
  ASSERT_TRUE(aTwitter.getTweetsListOfUser(TwitterTest::kUserIdA).empty());

  aTwitter.postTweet(TwitterTest::kUserIdA, TwitterTest::kTwitterA);
  ASSERT_EQ(aTwitter.getTweetsListOfUser(TwitterTest::kUserIdA).size(), 1ull);

  ASSERT_EQ(aTwitter.getNewsFeed(TwitterTest::kUserIdA), TwitterTest::kFeedsA);
}

TEST(Twitter, FollowSelf) {
  TwitterTest aTwitter;

  ASSERT_TRUE(aTwitter.getFollowees(TwitterTest::kUserIdA).empty());

  aTwitter.postTweet(TwitterTest::kUserIdA, TwitterTest::kTwitterA);

  // Still empty because cannot self follow
  aTwitter.follow(TwitterTest::kUserIdA, TwitterTest::kUserIdA);
  ASSERT_TRUE(aTwitter.getFollowees(TwitterTest::kUserIdA).empty());

  ASSERT_EQ(aTwitter.getNewsFeed(TwitterTest::kUserIdA), TwitterTest::kFeedsA);
}

TEST(Twitter, Follow) {
  TwitterTest aTwitter;

  ASSERT_TRUE(aTwitter.getFollowees(TwitterTest::kUserIdA).empty());

  aTwitter.follow(TwitterTest::kUserIdA, TwitterTest::kUserIdB);
  ASSERT_EQ(aTwitter.getFollowees(TwitterTest::kUserIdA).size(), 1ull);
  ASSERT_EQ(*aTwitter.getFollowees(TwitterTest::kUserIdA).cbegin(),
            TwitterTest::kUserIdB);
}

TEST(Twitter, UnFollow) {
  TwitterTest aTwitter;

  aTwitter.follow(TwitterTest::kUserIdA, TwitterTest::kUserIdB);
  aTwitter.unfollow(TwitterTest::kUserIdA, TwitterTest::kUserIdB);
  ASSERT_TRUE(aTwitter.getFollowees(TwitterTest::kUserIdA).empty());
}

TEST(Twitter, GetOwnTweetsOrder) {
  TwitterTest aTwitter;
  aTwitter.postTweet(TwitterTest::kUserIdA, TwitterTest::kTwitterA);
  aTwitter.postTweet(TwitterTest::kUserIdA, TwitterTest::kTwitterB);

  ASSERT_EQ(aTwitter.getNewsFeed(TwitterTest::kUserIdA), TwitterTest::kFeedsBA);
}

TEST(Twitter, SeeFolloweeFeeds) {
  TwitterTest aTwitter;

  // user A post A
  aTwitter.postTweet(TwitterTest::kUserIdA, TwitterTest::kTwitterA);

  // see only post A
  ASSERT_EQ(aTwitter.getNewsFeed(TwitterTest::kUserIdA), TwitterTest::kFeedsA);

  // user A follows user B
  aTwitter.follow(TwitterTest::kUserIdA, TwitterTest::kUserIdB);

  // user B post B
  aTwitter.postTweet(TwitterTest::kUserIdB, TwitterTest::kTwitterB);

  // A see its tweet and B's one
  ASSERT_EQ(aTwitter.getNewsFeed(TwitterTest::kUserIdA), TwitterTest::kFeedsBA);

  // user A unfollows user B
  aTwitter.unfollow(TwitterTest::kUserIdA, TwitterTest::kUserIdB);

  // see only post A, again
  ASSERT_EQ(aTwitter.getNewsFeed(TwitterTest::kUserIdA), TwitterTest::kFeedsA);
}

}  // namespace algorithms::test
