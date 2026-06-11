class Solution {
   public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        int n = intervals.size();
        int m = queries.size();

        sort(intervals.begin(), intervals.end());

        vector<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            q.push_back({queries[i], i});
        }
        sort(q.begin(), q.end());

        vector<int> ans(m, -1);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        // pair = {length, right}

        int i = 0;
        for (auto& [query, idx] : q) {
            while (i < n && intervals[i][0] <= query) {
                int l = intervals[i][0];
                int r = intervals[i][1];
                pq.push({r - l + 1, r});
                i++;
            }

            while (!pq.empty() && pq.top().second < query) {
                pq.pop();
            }

            if (!pq.empty()) {
                ans[idx] = pq.top().first;
            }
        }

        return ans;
    }
};
