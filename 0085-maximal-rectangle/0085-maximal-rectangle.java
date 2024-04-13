class Solution {
    static int row, col, max;
    static int dp[][];
    public int maximalRectangle(char[][] matrix) {
        col = matrix.length;
        row = matrix[0].length;
        dp = new int[col + 1][row + 1];
        max = 0;

        for(int i = 0; i < col; ++i)
            for(int j = 0; j < row; ++j)
                dp[i + 1][j] = (matrix[i][j] - '0') * ((matrix[i][j] - '0') + dp[i][j]);

        for(int i = 1; i <= col; ++i)
            rectangleSize(dp[i]);
        return max;
    }

    public void rectangleSize(int[] rowArr) {
        Deque<int[]> st = new ArrayDeque<>();

        for(int i = 0; i <= row; ++i) {
            int start = i;
            while(!st.isEmpty() && st.peekLast()[0] > rowArr[i]) {
                int[] curr = st.pollLast();
                // System.out.println(max);
                max = Math.max(max, curr[0] * (i - curr[1]));
                start = curr[1];
            }
            st.add(new int[]{rowArr[i], start});
        }
    }
}