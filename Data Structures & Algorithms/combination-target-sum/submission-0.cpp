class Solution {
   public:
    vector<vector<int>> ans;
    vector<int> temp;

    void solve(int index, int target, vector<int>& nums) {
        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        if (index == nums.size() || target < 0) return;

        temp.push_back(nums[index]);
        solve(index, target - nums[index], nums);
        temp.pop_back();

        solve(index + 1, target, nums);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        solve(0, target, nums);
        return ans;
    }
};