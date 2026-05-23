class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int left = 0;   // buy day
        int right = 1;  // sell day
        int maxProfit = 0;

        while (right < prices.size()) {
            // profitable transaction
            if (prices[right] > prices[left]) {
                int profit = prices[right] - prices[left];
                maxProfit = max(maxProfit, profit);
            } else {
                // found cheaper buying day
                left = right;
            }

            right++;
        }

        return maxProfit;
    }
};