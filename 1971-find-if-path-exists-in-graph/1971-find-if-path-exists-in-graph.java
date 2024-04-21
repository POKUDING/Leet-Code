class Solution {
    public boolean validPath(int n, int[][] edges, int source, int destination) {
        boolean[] visit = new boolean[n];

        visit[source] = true;
        while(true) {
            boolean flag = true;
            for(int[] edge : edges) {
                if(visit[edge[0]] != visit[edge[1]]) {
                    visit[edge[0]] = true;
                    visit[edge[1]] = true;
                    flag = false;
                }
            }
            if(visit[destination])
                return true;
            if(flag)
                return false;
        }
        // return false;
    }
}