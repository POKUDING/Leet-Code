/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int pseudoPalindromicPaths(TreeNode* root) {
        cin.tie(0);
        ios::sync_with_stdio(0);
        size_t cnt = 0;
        stack<pair<TreeNode*, int>> stk;

        stk.push({root, 0});
        while (!stk.empty()) {
            auto [node, path] = stk.top();
            stk.pop();
            if (node != nullptr) {
                path = path ^ (1 << node->val);
                if (node->left == nullptr && node->right == nullptr) {
                    if ((path & (path - 1)) == 0)
                        ++cnt;
                } else {
                    stk.push({node->left, path});
                    stk.push({node->right, path});
                }
            }
        }
        return cnt;
    }
};