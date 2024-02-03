class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int size = arr.size();
        vector<int> dp(size + 1, 0);

        for (int i = 1; i <= size; ++i) {
            int maxnum = 0;
            int maxsum = 0;
            for (int j = 1; j <= k && i - j >= 0; ++j) {
                maxnum = max(maxnum, arr[i - j]);
                maxsum = max(maxsum, dp[i - j] + maxnum * j);
            }
            dp[i] = maxsum;
        }
        return dp[size];
    }
};