class Twitter {
   private:
    int timer = 0;
    unordered_map<int, vector<pair<int, int>>> tweets;
    unordered_map<int, unordered_set<int>> following;

   public:
    Twitter() {}

    void postTweet(int userId, int tweetId) { tweets[userId].push_back({timer++, tweetId}); }

    vector<int> getNewsFeed(int userId) {
        using Tweet = pair<int, int>;
        priority_queue<Tweet, vector<Tweet>, greater<Tweet>> pq;

        for (auto tweet : tweets[userId]) {
            pq.push(tweet);
            if (pq.size() > 10) pq.pop();
        }

        for (int user : following[userId]) {
            for (auto tweet : tweets[user]) {
                pq.push(tweet);
                if (pq.size() > 10) pq.pop();
            }
        }

        vector<int> res;
        while (!pq.empty()) {
            Tweet tweet = pq.top();
            res.push_back(tweet.second);
            pq.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }

    void follow(int followerId, int followeeId) {
        if (followerId == followeeId) return;
        following[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) { following[followerId].erase(followeeId); }
};
