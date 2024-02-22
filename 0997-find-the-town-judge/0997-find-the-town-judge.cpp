class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int max_idx = -1;
        int max_trusted = 0;
        vector<int> memo(n + 1, 0);
        vector<int> memo_trust(n + 1, 0);
        if(n == 1)
            return n;
        for(int i = 0; i < trust.size(); ++i) {
            ++memo[trust[i][1]];
            ++memo_trust[trust[i][0]];
            if (memo[trust[i][1]] > max_trusted && memo_trust[trust[i][1]] == 0) {
                max_trusted = memo[trust[i][1]];
                max_idx = trust[i][1];
            }
        }
        if(max_trusted == n - 1 && memo_trust[max_idx] == 0)
            return max_idx;
        return -1;
    }
};