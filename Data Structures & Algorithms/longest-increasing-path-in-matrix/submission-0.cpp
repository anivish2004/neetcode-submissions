class Solution {
   public:
    int n, m;
    vector<vector<int>> dp;
    vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    int dfs(int r, int c, vector<vector<int>>& matrix) {
        if (dp[r][c] != -1) return dp[r][c];

        int ans = 1;

        for (auto& d : dirs) {
            int nr = r + d[0];
            int nc = c + d[1];

            if (nr >= 0 && nr < n && nc >= 0 && nc < m && matrix[nr][nc] > matrix[r][c]) {
                ans = max(ans, 1 + dfs(nr, nc, matrix));
            }
        }

        return dp[r][c] = ans;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();

        dp.assign(n, vector<int>(m, -1));

        int res = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                res = max(res, dfs(i, j, matrix));
            }
        }

        return res;
    }
};