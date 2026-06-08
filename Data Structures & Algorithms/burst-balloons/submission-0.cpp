class Solution {
   public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(n + 2, 1);

        for (int i = 0; i < n; i++) {
            arr[i + 1] = nums[i];
        }

        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

        for (int len = 2; len < n + 2; len++) {
            for (int l = 0; l + len < n + 2; l++) {
                int r = l + len;

                for (int k = l + 1; k < r; k++) {
                    dp[l][r] = max(dp[l][r], dp[l][k] + arr[l] * arr[k] * arr[r] + dp[k][r]);
                }
            }
        }

        return dp[0][n + 1];
    }
};