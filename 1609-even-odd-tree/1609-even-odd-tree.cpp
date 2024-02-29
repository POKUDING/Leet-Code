class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        queue<pair<int,TreeNode*>> que;
        pair<int,TreeNode*> curr, prev = make_pair(-1,nullptr);
        que.push(make_pair(0,root));
        while(!que.empty()) {
            curr = que.front();
            que.pop();
            if(curr.first % 2 == curr.second->val % 2)
                return false;
            if((prev.first == curr.first) && \
                ((prev.first % 2 && prev.second->val <= curr.second->val) || (!(prev.first % 2) && prev.second->val >= curr.second->val)))
                return false;
            prev = curr;
            if(curr.second->left) que.push(make_pair(curr.first + 1, curr.second->left));
            if(curr.second->right) que.push(make_pair(curr.first + 1, curr.second->right));
        }
        return true;
    }
};