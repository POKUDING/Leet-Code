class Solution {
public:
    int dir[3] = {-1, 0, 1};
    int dp[71][71][71];
    int rowmax;
    int colmax;

    int dfs(int i, int j, int row, vector<vector<int>>& grid) {
        int rtn = 0;
        if (rowmax == row)
            return 0;
        if (i < 0 || j < 0 || i >= colmax || j >= colmax)
            return INT_MIN;
        if (dp[i][j][row] != -1)
            return dp[i][j][row];
        for (int next_i = 0; next_i < 3; ++next_i) {
            for (int next_j = 0; next_j < 3; ++next_j)
                rtn = max(rtn,
                          dfs(i + dir[next_i], j + dir[next_j], row + 1, grid));
        }
        rtn += (i == j) ? grid[row][i] : grid[row][i] + grid[row][j];
        return dp[i][j][row] = rtn;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        rowmax = grid.size();
        colmax = grid[0].size();
        memset(dp, -1, sizeof dp);
        return dfs(0, colmax - 1, 0, grid);
    }
};