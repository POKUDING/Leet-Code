class Solution {
    public int findChampion(int n, int[][] edges) {
        boolean[] isDefeated = new boolean[n];
        
        for (int[] edge : edges)
            isDefeated[edge[1]] = true;
        
        int champion = -1;
        int championCount = 0;
        
        for (int team = 0; team < n; team++) {
            if (!isDefeated[team]) {
                champion = team;
                if (++championCount > 1)
                    return -1;
            }
        }
        
        return champion;
    }
}