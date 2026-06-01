class WordDictionary {
private:
    struct TrieNode {
        TrieNode* child[26];
        bool isEnd;

        TrieNode() {
            for (int i = 0; i < 26; i++) child[i] = NULL;
            isEnd = false;
        }
    };

    TrieNode* root;

    bool dfs(string& word, int idx, TrieNode* node) {
        if (idx == word.size()) return node->isEnd;

        char ch = word[idx];

        if (ch == '.') {
            for (int i = 0; i < 26; i++) {
                if (node->child[i] != NULL && dfs(word, idx + 1, node->child[i])) {
                    return true;
                }
            }
            return false;
        } else {
            int pos = ch - 'a';
            if (node->child[pos] == NULL) return false;
            return dfs(word, idx + 1, node->child[pos]);
        }
    }

public:
    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(string word) {
        TrieNode* node = root;

        for (char ch : word) {
            int pos = ch - 'a';
            if (node->child[pos] == NULL) {
                node->child[pos] = new TrieNode();
            }
            node = node->child[pos];
        }

        node->isEnd = true;
    }

    bool search(string word) {
        return dfs(word, 0, root);
    }
};