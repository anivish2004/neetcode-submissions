class Solution {
   public:
    int coinChange(vector<int>& coins, int amount) {
        const int INF = 1e9;
        vector<int> dp(amount + 1, INF);
        dp[0] = 0;

        for (int x = 1; x <= amount; x++) {
            for (int coin : coins) {
                if (x - coin >= 0 && dp[x - coin] != INF) {
                    dp[x] = min(dp[x], dp[x - coin] + 1);
                }
            }
        }

        return dp[amount] == INF ? -1 : dp[amount];
    }
};