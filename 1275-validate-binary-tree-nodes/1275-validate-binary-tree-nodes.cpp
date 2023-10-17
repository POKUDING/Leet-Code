class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> par(n, -1);
        queue<int> que;

        for (int i = 0; i < n; ++i)
        {
            int left = leftChild[i];
            int right = rightChild[i];
            if (left != -1)
            {
                if (par[left] != -1)
                    return false;
                par[left] = i;
            }
            if (right != -1)
            {
                if (par[right] != -1)
                    return false;
                par[right] = i;
            }
        }
        vector<int>::iterator it = find(par.begin(), par.end(), -1);
        if (it == par.end())
            return false;

        que.push(it - par.begin());
        while(!que.empty())
        {
            cout << que.front() << "\n";
            par[que.front()] = -2;
            if (leftChild[que.front()] != -1)
                que.push(leftChild[que.front()]);
            if (rightChild[que.front()] != -1)
                que.push(rightChild[que.front()]);
            que.pop();
        }
        for(int i = 0; i < n; ++i)
        {
            if(par[i] != -2)
                return false;
        }
        return true;
    }
};