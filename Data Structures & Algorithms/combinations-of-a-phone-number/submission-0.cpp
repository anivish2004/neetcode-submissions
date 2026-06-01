class Solution {
public:
    vector<string> ans;
    string path;

    void backtrack(string &digits, int idx, vector<string> &mp) {
        if (idx == digits.size()) {
            ans.push_back(path);
            return;
        }

        string letters = mp[digits[idx] - '0'];
        for (char ch : letters) {
            path.push_back(ch);
            backtrack(digits, idx + 1, mp);
            path.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        vector<string> mp = {
            "",     "",     "abc",  "def",
            "ghi",  "jkl",  "mno",  "pqrs",
            "tuv",  "wxyz"
        };

        backtrack(digits, 0, mp);
        return ans;
    }
};