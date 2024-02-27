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
    // int maxlen = 0;
    int dfs(TreeNode* root, int& maxlen) {
        if(!root)
            return -1;
        int left_len = dfs(root->left, maxlen) + 1;
        int right_len = dfs(root->right, maxlen) + 1;
        maxlen = max(maxlen, left_len + right_len);
        return max(left_len, right_len);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxlen = 0;
        dfs(root, maxlen);
        return maxlen;
    }
};