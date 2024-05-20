class Solution {
    public int subsetXORSum(int[] nums) {
        return dfs(nums, 0, 0);
    }

    public int dfs(int[] nums, int level, int curr) {
        if(level == nums.length)
            return curr;
        int include = dfs(nums, level + 1, curr^nums[level]);
        int exclude = dfs(nums, level + 1, curr);
        return include + exclude;
    }
}