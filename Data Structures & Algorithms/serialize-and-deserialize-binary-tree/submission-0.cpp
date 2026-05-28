/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Codec {
   public:
    // Helper for serialization
    void serializeHelper(TreeNode* root, string& s) {
        if (root == NULL) {
            s += "#,";
            return;
        }

        s += to_string(root->val) + ",";
        serializeHelper(root->left, s);
        serializeHelper(root->right, s);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;
        serializeHelper(root, s);
        return s;
    }

    // Helper for deserialization
    TreeNode* deserializeHelper(vector<string>& vals, int& i) {
        if (vals[i] == "#") {
            i++;
            return NULL;
        }

        TreeNode* root = new TreeNode(stoi(vals[i]));
        i++;
        root->left = deserializeHelper(vals, i);
        root->right = deserializeHelper(vals, i);

        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> vals;
        string temp = "";

        for (char c : data) {
            if (c == ',') {
                vals.push_back(temp);
                temp = "";
            } else {
                temp += c;
            }
        }

        int i = 0;
        return deserializeHelper(vals, i);
    }
};
