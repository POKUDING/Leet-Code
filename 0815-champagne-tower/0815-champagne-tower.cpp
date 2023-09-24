class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double> > dp(query_row + 1, vector<double>(query_row + 1, 0));
        dp[0][0] = poured;
        for (int row = 0; row < query_row; ++row)
        {
          for (int glass = 0; glass <= row; ++glass)
          {
            double tmp = (dp[row][glass] - 1) / 2;
            if (tmp > 0)
            {
              dp[row + 1][glass] += tmp;
              dp[row + 1][glass + 1] += tmp;
            }
          }
        }
        return min(1.0, dp[query_row][query_glass]);
    }
};