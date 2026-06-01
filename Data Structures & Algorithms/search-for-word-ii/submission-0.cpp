class Solution {
public:
    struct TrieNode {
        TrieNode* child[26];
        string word;

        TrieNode() {
            for (int i = 0; i < 26; i++)
                child[i] = NULL;
            word = "";
        }
    };

    TrieNode* root = new TrieNode();
    vector<string> ans;

    void insert(string word) {
        TrieNode* node = root;

        for (char ch : word) {
            int idx = ch - 'a';

            if (node->child[idx] == NULL)
                node->child[idx] = new TrieNode();

            node = node->child[idx];
        }

        node->word = word;
    }

    void dfs(vector<vector<char>>& board, int r, int c, TrieNode* node) {
        char ch = board[r][c];

        if (ch == '#' || node->child[ch - 'a'] == NULL)
            return;

        node = node->child[ch - 'a'];

        if (node->word != "") {
            ans.push_back(node->word);
            node->word = ""; // avoid duplicates
        }

        board[r][c] = '#';

        int rows = board.size();
        int cols = board[0].size();

        if (r > 0)
            dfs(board, r - 1, c, node);

        if (c > 0)
            dfs(board, r, c - 1, node);

        if (r < rows - 1)
            dfs(board, r + 1, c, node);

        if (c < cols - 1)
            dfs(board, r, c + 1, node);

        board[r][c] = ch;
    }

    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {

        for (string& word : words)
            insert(word);

        int rows = board.size();
        int cols = board[0].size();

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                dfs(board, i, j, root);
            }
        }

        return ans;
    }
};