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
#ifndef ALGORITHMS__TWITTER__HPP
#define ALGORITHMS__TWITTER__HPP
#include <set>
#include <unordered_map>
#include <utility>
#include <vector>

namespace algorithms {

/*! \brief Design a simplified version of Twitter where users can post tweets,
 *  follow/unfollow another user and is able to see the 10 most recent tweets in
 *  the user's news feed.
 *  Your design should support the following methods:
 *      - postTweet(userId, tweetId): Compose a new tweet.
 *      - getNewsFeed(userId): Retrieve the 10 most recent tweet ids in the
          user's news feed. Each item in the news feed must be posted by users
          who the user followed or by the user herself. Tweets must be ordered
          from most recent to least recent.
 *      - follow(followerId, followeeId): Follower follows a followee.
 *      - unfollow(followerId, followeeId): Follower unfollows a followee.
 * \note https://leetcode.com/problems/design-twitter/
 */
class Twitter {
 public:
  using TweetId_t = int;
  using UserId_t = int;

  /*! \brief Compose a new tweet.
   *  \note  Complexity ->   Time: O(1) Amortized constant.
   */
  void postTweet(const UserId_t userId, const TweetId_t tweetId);

  /*! \brief Retrieve the 10 most recent tweet ids in the user's news feed. Each
   *  item in the news feed must be posted by users who the user followed or by
   *  the user herself. Tweets must be ordered from most recent to least recent.
   *  \note  Complexity ->  Time: O(|F|)   where |F| followees set
   */
  std::vector<TweetId_t> getNewsFeed(const UserId_t userId);

  /*! \brief Follower follows a followee. If the operation is invalid, it should
   *  be a no-op.
   *  \note  Complexity ->  Time: O(log|F|)   where |F| followees set
   *  \note If the user follows herself, it is like a no-op.
   */
  void follow(const UserId_t followerId, const UserId_t followeeId);

  /*! \brief Follower unfollows a followee. If the operation is invalid, it
   *  should be a no-op.
   *  \note  Complexity ->    Time: O(log|F|)   where |F| followees set
   */
  void unfollow(const UserId_t followerId, const UserId_t followeeId);

 protected:
  using Counter_t = unsigned long long;
  using MetaTweet_t = std::pair<TweetId_t, Counter_t>;
  using ListTweets_t = std::vector<MetaTweet_t>;

  const ListTweets_t& getTweetsListOfUser(const UserId_t userId);

  const std::set<UserId_t>& getFollowees(const UserId_t userId);

 private:
  template <typename Key, typename Value>
  using Map_t = std::unordered_map<Key, Value>;

  class RefTweetList_t {
   public:
    explicit RefTweetList_t(const ListTweets_t& iRefListTweet);

    //! \return whether the internal index is valid.
    bool isIndexValid() const noexcept;

    /*! \return the tweet of the reference tweets-list in accordance with the
     *  internal index.
     *  \note the behaviour is undefined whether the index is not valid.
     *  \see isIndexValid
     */
    const MetaTweet_t& getTweetOnIndex() const;

    /*! \brief It advances the index to the successive element.
     *  \note It can invalidate the index.
     */
    void advanceIndex() noexcept;

    //! \brief comparison operator.
    bool operator<(const RefTweetList_t& oth) const;

   private:
    const ListTweets_t& _refListTweet;
    std::size_t _index;
  };

  Counter_t _tweetCounter = 0ull;
  Map_t<UserId_t, ListTweets_t> _user2tweets;
  Map_t<UserId_t, std::set<UserId_t>> _user2followee;
};

}  // namespace algorithms

#endif  // ALGORITHMS__TWITTER__HPP
