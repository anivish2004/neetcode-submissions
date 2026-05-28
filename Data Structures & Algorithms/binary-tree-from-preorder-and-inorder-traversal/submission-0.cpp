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

class Solution {
   public:
    unordered_map<int, int> mp;
    int preIndex = 0;

    TreeNode* buildTreeHelper(vector<int>& preorder, int inStart, int inEnd) {
        if (inStart > inEnd) return NULL;

        int rootVal = preorder[preIndex++];
        TreeNode* root = new TreeNode(rootVal);

        int inRootIndex = mp[rootVal];

        root->left = buildTreeHelper(preorder, inStart, inRootIndex - 1);
        root->right = buildTreeHelper(preorder, inRootIndex + 1, inEnd);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }
        return buildTreeHelper(preorder, 0, inorder.size() - 1);
    }
};
