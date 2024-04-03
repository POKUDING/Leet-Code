class Solution {
    int x_size, y_size;
    boolean[][] visit;
    int[] dirX = {0, 1, 0, -1};
    int[] dirY = {1, 0, -1, 0};
    public boolean exist(char[][] board, String word) {
        y_size = board.length;
        x_size = board[0].length;
        visit = new boolean[y_size][x_size];
        char[] charArr = word.toCharArray();

        for(int i = 0; i < y_size; ++i) {
            for(int j = 0; j < x_size; ++j) {
                if(dfs(i,j,0,board,charArr))
                    return true;
            }
        }
        return false;
    }

    boolean dfs(int y, int x, int dep, char[][] board, char[] charArr) {
        if(dep == charArr.length)
            return true;
        if(y < 0 || x < 0 || y >= y_size || x >= x_size)
            return false;
        if(visit[y][x] == true || board[y][x] != charArr[dep])
            return false;
        visit[y][x] = true;
        for(int i = 0; i < 4; ++i) {
            if(dfs(y + dirY[i], x + dirX[i], dep + 1, board, charArr))
                return true;
        }
        visit[y][x] = false;
        return false;
    }
}