class Twitter {
    int timer;
    unordered_map<int, vector<pair<int, int>>> tweets;  // userId -> {time, tweetId}
    unordered_map<int, unordered_set<int>> following;   // userId -> set of followees

   public:
    Twitter() { timer = 0; }

    void postTweet(int userId, int tweetId) { tweets[userId].push_back({timer++, tweetId}); }

    vector<int> getNewsFeed(int userId) {
        vector<int> feed;
        priority_queue<tuple<int, int, int, int>> pq;

        following[userId].insert(userId);
        for (int followeeId : following[userId]) {
            auto& v = tweets[followeeId];
            if (!v.empty()) {
                int idx = (int)v.size() - 1;
                pq.push({v[idx].first, v[idx].second, followeeId, idx});
            }
        }

        while (!pq.empty() && (int)feed.size() < 10) {
            auto [time, tweetId, uid, idx] = pq.top();
            pq.pop();
            feed.push_back(tweetId);

            if (idx > 0) {
                auto& v = tweets[uid];
                idx--;
                pq.push({v[idx].first, v[idx].second, uid, idx});
            }
        }

        return feed;
    }

    void follow(int followerId, int followeeId) {
        if (followerId == followeeId) return;
        following[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        if (followerId == followeeId) return;
        if (following.count(followerId)) {
            following[followerId].erase(followeeId);
        }
    }
};