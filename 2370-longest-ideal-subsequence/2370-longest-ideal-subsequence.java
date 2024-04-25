class Solution {
    public int longestIdealString(String s, int k) {
        int[] dp = new int[27];
        int n = s.length();

        for(int i = 0; i < n; ++i ){
            int curr = s.charAt(i) - 'a';
            int max = Integer.MIN_VALUE;

            int left = Math.max((curr - k), 0);
            int right = Math.min((curr + k), 26);

            for(int j = left; j <=right; ++j) {
                max = Math.max(max, dp[j]);
            }
            dp[curr] = max + 1;
        }
        int ans = Integer.MIN_VALUE;
        for(int num : dp) {
            ans = Math.max(num,ans);
        }
        return ans;
    }
}