class Solution {

    public int minimumObstacles(int[][] grid) {
        int[][] dirs = {{0,1}, {1, 0}, {0, -1}, {-1, 0}};
        int m = grid.length;
        int n = grid[0].length;
        int[][] visit = new int[m][n];
        Deque<int[]> deque = new ArrayDeque<>();

        for(int[] visitrow : visit)
            Arrays.fill(visitrow, Integer.MAX_VALUE);

        deque.offerFirst(new int[]{0, 0});
        visit[0][0] = 0;

        while(!deque.isEmpty()) {
            int[] curr = deque.pollFirst();

            for(int[] dir : dirs) {
                int nextY = curr[0] + dir[0];
                int nextX = curr[1] + dir[1];
                if(!(nextY >= 0 && nextY < m && nextX >= 0 && nextX < n))
                    continue;
                int nextRm = visit[curr[0]][curr[1]] + grid[nextY][nextX];
                if(visit[nextY][nextX] <= nextRm)
                    continue;
                visit[nextY][nextX] = nextRm;
                if(grid[nextY][nextX] == 0)
                    deque.offerFirst(new int[]{nextY, nextX});
                else
                    deque.offerLast(new int[]{nextY, nextX});
            }
        }

        return visit[m - 1][n - 1];
    }
}