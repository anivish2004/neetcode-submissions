class Solution {
   public:
    vector<vector<int>> ans;
    vector<int> temp;

    void solve(vector<int>& nums, vector<bool>& used) {
        if (temp.size() == nums.size()) {
            ans.push_back(temp);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) continue;

            used[i] = true;
            temp.push_back(nums[i]);

            solve(nums, used);

            temp.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        solve(nums, used);
        return ans;
    }
};