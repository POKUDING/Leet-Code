class Solution {
    public int numberOfSubarrays(int[] nums, int k) {
        int[] cnt = new int[nums.length + 1];
        int rtn = 0;
        cnt[0] = 1;

        int currOddCnt = 0;
        for(int currNum : nums) {
            currOddCnt += currNum & 1;
            if(currOddCnt - k >= 0)
                rtn += cnt[currOddCnt - k];
            ++cnt[currOddCnt];
        }
        return rtn;
    }
}