class Solution {
   public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = 0;
        for (int x : nums) totalSum += x;

        if (abs(target) > totalSum) return 0;
        if ((totalSum + target) % 2 != 0) return 0;

        int subsetSum = (totalSum + target) / 2;

        vector<int> dp(subsetSum + 1, 0);
        dp[0] = 1;

        for (int num : nums) {
            for (int s = subsetSum; s >= num; s--) {
                dp[s] += dp[s - num];
            }
        }

        return dp[subsetSum];
    }
};
