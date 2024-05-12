class Solution {
    public int[][] largestLocal(int[][] grid) {
        int len = grid.length;
        int[][] rtn = new int[len - 2][len - 2];

        for(int i = 1; i < len - 1; ++i) {
            for(int j = 1; j < len - 1; ++j) {
                int tmp = 0;
                for(int k = i - 1; k <= i + 1; ++k)
                    for(int l = j - 1; l <= j + 1; ++l)
                        tmp = Math.max(tmp, grid[k][l]);
                rtn[i - 1][j - 1] = tmp;
            }
        }
        return rtn;
    }
}