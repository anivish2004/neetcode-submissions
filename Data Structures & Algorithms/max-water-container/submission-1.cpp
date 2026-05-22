class Solution {
   public:
    int maxArea(vector<int>& heights) {
        int maxWater = 0;

        int lp = 0;
        int rp = heights.size() - 1;

        while (lp < rp) {
            int w = rp - lp;

            int ht = min(heights[lp], heights[rp]);

            int currWater = w * ht;

            maxWater = max(maxWater, currWater);

            if (heights[lp] < heights[rp]) {
                lp++;
            } else {
                rp--;
            }
        }

        return maxWater;
    }
};