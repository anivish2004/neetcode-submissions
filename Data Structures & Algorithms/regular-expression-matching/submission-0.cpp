class Solution {
   public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

        function<bool(int, int)> solve = [&](int i, int j) -> bool {
            if (dp[i][j] != -1) return dp[i][j];

            if (j == m) return dp[i][j] = (i == n);

            bool firstMatch = (i < n && (s[i] == p[j] || p[j] == '.'));

            bool ans;
            if (j + 1 < m && p[j + 1] == '*') {
                ans = solve(i, j + 2) || (firstMatch && solve(i + 1, j));
            } else {
                ans = firstMatch && solve(i + 1, j + 1);
            }

            return dp[i][j] = ans;
        };

        return solve(0, 0);
    }
};