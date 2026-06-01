class PrefixTree {
private:
    struct TrieNode {
        TrieNode* child[26];
        bool isEnd;

        TrieNode() {
            for (int i = 0; i < 26; i++)
                child[i] = NULL;
            isEnd = false;
        }
    };

    TrieNode* root;

public:
    PrefixTree() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* node = root;

        for (char ch : word) {
            int idx = ch - 'a';

            if (node->child[idx] == NULL)
                node->child[idx] = new TrieNode();

            node = node->child[idx];
        }

        node->isEnd = true;
    }

    bool search(string word) {
        TrieNode* node = root;

        for (char ch : word) {
            int idx = ch - 'a';

            if (node->child[idx] == NULL)
                return false;

            node = node->child[idx];
        }

        return node->isEnd;
    }

    bool startsWith(string prefix) {
        TrieNode* node = root;

        for (char ch : prefix) {
            int idx = ch - 'a';

            if (node->child[idx] == NULL)
                return false;

            node = node->child[idx];
        }

        return true;
    }
};