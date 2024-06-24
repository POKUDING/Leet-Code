class Solution {
    public int minKBitFlips(int[] nums, int k) {
        int flip = 0;
        int ans = 0;

        for(int i = 0; i < nums.length; ++i) {
            if((nums[i] + flip) % 2 == 0) {
                if(i + k > nums.length)
                    return -1;
                ++ans;
                ++flip;
                nums[i] = -1;
            }
            if (i - k + 1 >= 0)
                flip -= nums[i - k + 1] < 0 ? 1 : 0;
        }
        return ans;
    }
}