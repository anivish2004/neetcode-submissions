class Solution {
   public:
    vector<vector<int>> ans;
    vector<int> temp;
    void solve(int index, vector<int>& nums) {
        if (index == nums.size()) {
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[index]);
        solve(index + 1, nums);
        temp.pop_back();
        solve(index + 1, nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        solve(0, nums);
        return ans;
    }
};
