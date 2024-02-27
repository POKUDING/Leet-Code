const static auto _ = [] { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return nullptr; }();
class Solution {
public:
    int dfs(TreeNode* root, int& maxlen) {
        if (!root)
            return 0;
        int left_len = dfs(root->left, maxlen);
        int right_len = dfs(root->right, maxlen);
        maxlen = max(maxlen, left_len + right_len);
        return max(left_len, right_len) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxlen = 0;
        dfs(root, maxlen);
        return maxlen;
    }
};