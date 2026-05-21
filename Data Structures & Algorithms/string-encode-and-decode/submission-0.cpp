class Solution {
   public:
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string result;
        for (string& s : strs) {
            result += to_string(s.size()) + "#" + s;
        }
        return result;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> result;
        int i = 0;

        while (i < s.size()) {
            int j = i;
            while (s[j] != '#') {
                j++;
            }

            int len = stoi(s.substr(i, j - i));
            i = j + 1;

            result.push_back(s.substr(i, len));
            i += len;
        }

        return result;
    }
};