class Solution {
   public:
    vector<string> ans;
    string temp;

    void solve(int open, int close, int n) {
        if (temp.size() == 2 * n) {
            ans.push_back(temp);
            return;
        }

        if (open < n) {
            temp.push_back('(');
            solve(open + 1, close, n);
            temp.pop_back();
        }

        if (close < open) {
            temp.push_back(')');
            solve(open, close + 1, n);
            temp.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        solve(0, 0, n);
        return ans;
    }
};