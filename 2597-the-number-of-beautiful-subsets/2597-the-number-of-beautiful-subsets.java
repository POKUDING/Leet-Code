class Solution {
    static int rtn;
    public int beautifulSubsets(int[] nums, int k) {
        rtn = 0;
        Arrays.sort(nums);
        dfs(nums, 0, new int[1001] , k);
        return rtn;
    }

    public void dfs(int[] nums, int idx, int[] visit, int k) {
        if (idx == nums.length)
            return ;
        for(int i = idx; i < nums.length; ++i) {
            if (nums[i] >= k && visit[nums[i] - k] != 0)
                continue;
            ++visit[nums[i]];
            dfs(nums,i + 1, visit, k);
            ++rtn;
            // System.out.println(i + " " + rtn);
            --visit[nums[i]];
        }
    }
}