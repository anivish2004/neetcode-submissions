class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, priority_queue<string, vector<string>, greater<string>>> graph;

        for (auto &t : tickets) {
            graph[t[0]].push(t[1]);
        }

        vector<string> route;
        dfs("JFK", graph, route);
        reverse(route.begin(), route.end());
        return route;
    }

    void dfs(const string& airport,
             unordered_map<string, priority_queue<string, vector<string>, greater<string>>>& graph,
             vector<string>& route) {
        auto &pq = graph[airport];
        while (!pq.empty()) {
            string next = pq.top();
            pq.pop();
            dfs(next, graph, route);
        }
        route.push_back(airport);
    }
};