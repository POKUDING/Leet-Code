class Solution {
    public long maximumSubarraySum(int[] nums, int k) {
        Map<Integer,Integer> map = new HashMap<>();
        int dup = 0;
        long max = 0;
        int leftIdx = 0;
        int rightIdx = 0;
        long currVal = 0;

        while(rightIdx < nums.length) {
            // System.out.println("top ==== leftIdx: " + leftIdx + ", rightIdx: " + rightIdx +  ", dup: " + dup);
            if(rightIdx - leftIdx == k) {
                int leftCurr = map.get(nums[leftIdx]);
                if(leftCurr == 2)
                    --dup;
                currVal -= nums[leftIdx];
                map.put(nums[leftIdx], leftCurr - 1);
                ++leftIdx;
            }
            // System.out.println("bot ==== leftIdx: " + leftIdx + ", rightIdx: " + rightIdx +  ", dup: " + dup);

            int curr = map.getOrDefault(nums[rightIdx], 0);
            map.put(nums[rightIdx], curr + 1);
            currVal += nums[rightIdx];
            if (curr == 1)
                ++dup;
            if(dup == 0 && rightIdx - leftIdx == k - 1)
                max = Math.max(max, currVal);
            ++rightIdx;
        }
        return max;
    }
}