class Solution {
    public int minIncrementForUnique(int[] nums) {
        int curr = 0;
        int rtn = 0;
        Arrays.sort(nums);

        for(int num : nums) {
            curr = Math.max(curr, num);
            rtn += curr - num;
            ++curr;
        }
        return rtn;
    }
}