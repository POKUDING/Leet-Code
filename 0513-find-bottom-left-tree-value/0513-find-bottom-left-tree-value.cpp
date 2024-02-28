const static auto _ = [](){cin.tie(0); cout.tie(0); ios::sync_with_stdio(0); return nullptr;}();
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> que(deque<TreeNode*>(1,root));
        TreeNode* curr;
        while(!que.empty()) {
            curr = que.front();
            que.pop();
            if(curr->right) que.push(curr->right);
            if(curr->left) que.push(curr->left);
        }
        return curr->val;
    }
};