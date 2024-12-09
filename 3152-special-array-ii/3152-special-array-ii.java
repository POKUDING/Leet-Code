class Solution {
    public boolean[] isArraySpecial(int[] nums, int[][] queries) {
        int n = nums.length;
        int[] prefix = new int[n];
        boolean[] result = new boolean[queries.length];
        
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1];
            if (nums[i - 1] % 2 == nums[i] % 2) {
                prefix[i]++;
            }
        }

        for (int i = 0; i < queries.length; i++) {
            
            result[i] = (prefix[queries[i][0]] - prefix[queries[i][1]] == 0);
        }

        return result;
    }
}