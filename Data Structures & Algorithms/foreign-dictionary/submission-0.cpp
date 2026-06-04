class Solution {
   public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char, unordered_set<char>> graph;
        unordered_map<char, int> indegree;

        for (auto& word : words) {
            for (char ch : word) {
                indegree[ch] = 0;
            }
        }

        for (int i = 0; i < words.size() - 1; i++) {
            string& w1 = words[i];
            string& w2 = words[i + 1];

            int len = min(w1.size(), w2.size());
            int j = 0;

            while (j < len && w1[j] == w2[j]) j++;

            if (j == len && w1.size() > w2.size()) return "";

            if (j < len) {
                char u = w1[j];
                char v = w2[j];

                if (!graph[u].count(v)) {
                    graph[u].insert(v);
                    indegree[v]++;
                }
            }
        }

        queue<char> q;

        for (auto& p : indegree) {
            if (p.second == 0) q.push(p.first);
        }

        string order;

        while (!q.empty()) {
            char cur = q.front();
            q.pop();

            order += cur;

            for (char nei : graph[cur]) {
                indegree[nei]--;

                if (indegree[nei] == 0) q.push(nei);
            }
        }

        if (order.size() != indegree.size()) return "";

        return order;
    }
};