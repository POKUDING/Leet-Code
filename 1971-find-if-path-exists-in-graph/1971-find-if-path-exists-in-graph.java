class Solution {
    public boolean validPath(int n, int[][] edges, int source, int destination) {
        boolean[] visit = new boolean[n];
        ArrayList<ArrayList<Integer>> arr = new ArrayList<>();
        for(int i = 0; i < n; ++i)
            arr.add(new ArrayList<Integer>());
        for(int i = 0; i < edges.length; ++i) {
            arr.get(edges[i][0]).add(edges[i][1]);
            arr.get(edges[i][1]).add(edges[i][0]);
        }
        visit[source] = true;
        return bfs(visit, arr, source, destination);
    }

    public boolean bfs(boolean[] visit, ArrayList<ArrayList<Integer>> arr, int start, int dest) {
        Deque<Integer> que = new ArrayDeque<>();

        que.add(start);
        while(!que.isEmpty()) {
            int curr = que.poll();
            if(curr == dest)
                return true;
            for(int i = 0; i < arr.get(curr).size(); ++i) {
                int next = arr.get(curr).get(i);
                if(!visit[next]) {
                    visit[next] = true;
                    que.add(next);
                }
            }
        }
        return false;
    }
}