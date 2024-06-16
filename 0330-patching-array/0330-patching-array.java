class Solution {
    public int minPatches(int[] nums, int n) {
        long possible = 1;
        int ans = 0;
        int idx = 0;

        while(possible <= n) {
            if(idx < nums.length && nums[idx] <= possible)
                possible += nums[idx++];
            else {
                ++ans;
                possible += possible;
            }
        }
        return ans;
    }
}