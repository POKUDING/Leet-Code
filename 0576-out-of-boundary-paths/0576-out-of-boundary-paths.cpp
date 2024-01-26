class Solution {
public:
    int dir[4] = {1, 0 , -1, 0};
    int mod = 1000000007;
    int cntWays(int dp[51][51][51], int x, int y,int m,int n, int maxMove, int moves) {
        int rtn = 0;
        if (moves >= maxMove)
            return 0;
        if (dp[moves][y][x] != -1)
            return dp[moves][y][x];
        for(int i = 0; i < 4; ++i){
            int next_x = x + dir[i];
            int next_y = y + dir[(i + 1) % 4];
            if (next_x < 0 || next_y < 0 || next_x >= n || next_y >= m)
                ++rtn;
            else
                rtn += cntWays(dp,next_x, next_y, m, n, maxMove,moves + 1) % mod;
            rtn %= mod;
        }
        dp[moves][y][x] = rtn;
        return rtn;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        int ans = 0;
        int dp[51][51][51];

        memset(dp, -1, sizeof dp);
        ans = cntWays(dp, startColumn, startRow, m, n, maxMove,0);
        return ans;
    }
};