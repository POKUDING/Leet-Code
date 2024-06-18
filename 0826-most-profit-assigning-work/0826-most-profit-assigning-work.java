class Solution {
    public int maxProfitAssignment(int[] difficulty, int[] profit, int[] worker) {
        int[][] works = new int[difficulty.length][2];
        PriorityQueue<Integer> pq = new PriorityQueue<>((i1,i2)->i2-i1);
        int ans = 0;
        int workIdx = 0;

        for(int i = 0; i < difficulty.length; ++i) {
            works[i][0] = difficulty[i];
            works[i][1] = profit[i];
        }
        Arrays.sort(works,(work1, work2)->work1[0]-work2[0]);
        Arrays.sort(worker);

        for(int i = 0; i < worker.length; ++i) {
            while(workIdx < works.length && works[workIdx][0] <= worker[i]){
                // System.out.println("pq added : " + works[workIdx][1]);
                pq.add(works[workIdx++][1]);
            }
            if(!pq.isEmpty())
                ans += pq.peek();
        }

        return ans;
    }
}