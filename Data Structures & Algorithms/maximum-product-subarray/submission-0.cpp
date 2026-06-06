#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxProd = nums[0];
        int minProd = nums[0];
        int ans = nums[0];

        for (int i = 1; i < n; i++) {
            int x = nums[i];

            if (x < 0) swap(maxProd, minProd);

            maxProd = max(x, maxProd * x);
            minProd = min(x, minProd * x);

            ans = max(ans, maxProd);
        }

        return ans;
    }
};