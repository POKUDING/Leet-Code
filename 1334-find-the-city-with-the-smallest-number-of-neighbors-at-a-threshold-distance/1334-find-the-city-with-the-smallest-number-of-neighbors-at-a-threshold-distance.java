class Solution {
    public int findTheCity(int n, int[][] edges, int distanceThreshold) {
        int[][] distance = new int[n][n];

        for(int i = 0 ; i < n; ++i) {
            Arrays.fill(distance[i], 1000000000);
            distance[i][i] = 0;
        }

        for(int[] edge : edges) {
            distance[edge[0]][edge[1]] = edge[2];
            distance[edge[1]][edge[0]] = edge[2];
        }
        
        for(int k = 0; k < n; ++k) {
            for(int i = 0; i < n; ++i) {
                for(int j = 0; j < n; ++j)
                    distance[i][j] = Math.min(distance[i][j], distance[i][k] + distance[k][j]);
            }
        }

        int ans = -1;
        int mini = Integer.MAX_VALUE;
        int[] reachable = new int[n];
        for(int i = 0; i < n; ++i) {
            int cnt = 0;
            for(int j = 0; j < n; ++j) {
                if (i != j && distance[i][j] <= distanceThreshold) {
                    ++cnt;
                }
            }
            reachable[i] = cnt;
            if(cnt <= mini) {
                mini = cnt;
                ans = i;
            }
        }
        return ans;
    }
}