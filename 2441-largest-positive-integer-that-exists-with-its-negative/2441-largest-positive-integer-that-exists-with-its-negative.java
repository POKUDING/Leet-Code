class Solution {
    public int findMaxK(int[] nums) {
        Map<Integer,Boolean> map = new HashMap<>();
        int ans = -1;

        for(int i = 0; i < nums.length; ++i) {
            if(map.containsKey(nums[i] * -1) == true)
                ans = Math.max(ans, Math.abs(nums[i]));
            map.put(nums[i], true);
        }
        return ans;
    }
}