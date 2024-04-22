class Solution {
    int[] nextPow = new int[]{ 1000, 100, 10, 1};
    int[] nextPlus = new int[] {1, -1};
    public int openLock(String[] deadends, String target) {
        boolean[] visit = new boolean[10000];
        visit[0] = true;
        for(int i = 0; i < deadends.length; ++i)
            visit[Integer.parseInt(deadends[i])] = true;
        return bfs(visit, Integer.parseInt(target));
    }

    public int bfs(boolean[] visit, int target) {
        Deque<int[]> que = new ArrayDeque<>();

        que.push(new int[]{0, 0});
        while(!que.isEmpty()) {
            int[] curr = que.poll();
            // System.out.println(target + " " + curr[0] + " " + curr[1] + " " + curr[2] + " "+curr[3]);
            if(curr[0] == target)
                return curr[1];
            for(int i = 0; i < 8; ++i) {
                // int nextNum = (10000 + curr[0] + nextPow[i]) % 10000;
                int pickNum = (curr[0] / nextPow[i / 2] % 10);
                int changeNum = pickNum + nextPlus[i % 2];
                changeNum = changeNum == -1 ? 9 : (changeNum == 10 ? 0 : changeNum);
                int nextNum = curr[0] + (changeNum - pickNum) * nextPow[i / 2];
                if(visit[nextNum]) continue;
                visit[nextNum] = true;
                que.add(new int[]{nextNum, curr[1] + 1});
            }
        }
        return -1;
    }
}