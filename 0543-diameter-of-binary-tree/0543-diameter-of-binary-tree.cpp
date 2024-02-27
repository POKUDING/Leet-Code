const static auto _ = [] { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return nullptr; }();
class Solution {
public:
    int dfs(TreeNode* root, int& maxlen) {
        if (!root)
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