class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        int rtn = 0;

        for (int r = 0; r < row; ++r)
            for (int c = 1; c < col; ++c)
                matrix[r][c] += matrix[r][c - 1];

        unordered_map<int, int> map;
        for (int c1 = 0; c1 < col; ++c1) {
            for (int c2 = c1; c2 < col; ++c2) {
                map.clear();
                map[0] = 1;
                int sum = 0;

                for (int r = 0; r < row; ++r) {
                    sum += matrix[r][c2] - (c1 <= 0 ? 0 : matrix[r][c1 - 1]);
                    rtn += map[sum - target];
                    map[sum]++;
                }
            }
        }
        return rtn;
    }
};