class Solution {
    public long pickGifts(int[] gifts, int k) {
        PriorityQueue<Integer> pq = new PriorityQueue<>((a,b)->b-a);
        long ans = 0;

        for(int gift: gifts)
            pq.add(gift);

        while(k-- > 0)
            pq.add((int)Math.sqrt(pq.poll()));
        while(!pq.isEmpty())
            ans += pq.poll();
        return ans;
    }
}