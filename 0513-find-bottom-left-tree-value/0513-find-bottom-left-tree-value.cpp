const static auto _ = [](){cin.tie(0); cout.tie(0); ios::sync_with_stdio(0); return nullptr;}();
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<pair<int,TreeNode*>> que;
        pair<int,int> rtn = make_pair(-1,0);
        que.push(make_pair(0, root));
        while(!que.empty()) {
            auto [dep, head] = que.front();
            que.pop();
            if(head == nullptr)
                continue;
            if(dep > rtn.first)
                rtn = make_pair(dep, head->val);
            que.push(make_pair(dep + 1, head->left));
            que.push(make_pair(dep + 1, head->right));
        }
        return rtn.second;
    }
};