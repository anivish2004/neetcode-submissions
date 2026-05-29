class Solution {
   public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>> pq;  // max-heap by distance squared

        for (auto& p : points) {
            int x = p[0], y = p[1];
            int dist = x * x + y * y;

            pq.push({dist, p});

            if ((int)pq.size() > k) {
                pq.pop();
            }
        }

        vector<vector<int>> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};