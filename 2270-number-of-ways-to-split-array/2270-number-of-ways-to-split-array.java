class Solution {
    public int waysToSplitArray(int[] nums) {
        long[] prefixSum = new long[nums.length];
        int ans = 0;

        prefixSum[0] = nums[0];
        for(int i = 1; i < nums.length; ++i)
            prefixSum[i] = prefixSum[i - 1] + nums[i];
        
        long maxSum = prefixSum[nums.length - 1];
        for(int i = 0; i < nums.length - 1; ++i) {
            if(prefixSum[i] >= maxSum - prefixSum[i])
                ++ans;
        }
        return ans;
    }
}