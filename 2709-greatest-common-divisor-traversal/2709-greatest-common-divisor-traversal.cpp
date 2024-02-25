class Solution {
private:
    vector<int> root = vector<int>(100001, -1);
public:
    int findRoot(int n) {
        if (root[n] == -1)
            root[n] = n;
        else if (root[n] != n)
            root[n] = findRoot(root[n]);
        return root[n];
    }
    bool canTraverseAllPairs(vector<int>& nums) {
        int cnt = 0;
        if (nums.size() == 1)
            return true;
        for (int i = 0; i < nums.size(); ++i) {
            int tmp = nums[i];
            if (tmp == 1)
                return false;
            int tmp_root = 0;
            for (int j = 2; j * j <= tmp; ++j) {
                if (tmp % j == 0) {
                    int j_root = findRoot(j);
                    if (tmp_root == 0) {
                        tmp_root = j_root;
                    } else {
                        root[j_root] = tmp_root;
                    }
                    while (tmp % j == 0) {
                        tmp /= j;
                    }
                }
            }
            if (tmp > 1) {
                if (root[tmp] == -1 && tmp_root == 0)
                    root[tmp] = tmp;
                else if (tmp_root != 0)
                    root[findRoot(tmp)] = tmp_root;
            }
        }
        for (int i = 2; i <= 100000; ++i) {
            if (root[i] == i)
                ++cnt;
            if (cnt > 1)
                return false;
        }
        return cnt == 1;
    }
};