class Solution {
    public long findScore(int[] nums) {
        long ans = 0;
        PriorityQueue<int[]> pq = new PriorityQueue<>((a,b)-> {
            if(a[0] == b[0])
                return a[1] - b[1];
            return a[0] - b[0];
        });

        for (int i = 0; i < nums.length; ++i)
            pq.add(new int[]{nums[i], i});

        while(!pq.isEmpty()) {
            int[] curr = pq.poll();
            if (nums[curr[1]] == -1)
                continue;
            ans += curr[0];
            nums[curr[1]] = -1;
            nums[Math.min(nums.length - 1, curr[1] + 1)] = -1;
            nums[Math.max(0, curr[1] - 1)] = -1;
        }

        return ans;
    }
}