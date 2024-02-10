class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int len = nums.size();
        int max_dp = 0, max_idx = 0;
        vector<int> dp(len, 0), before(len), ans;

        sort(nums.begin(), nums.end());
        for (int i = 0; i < len; ++i) {
            before[i] = -1;
            for (int j = 0; j < i; ++j) {
                if (nums[i] % nums[j] == 0 && dp[j] > dp[i]) {
                    dp[i] = dp[j];
                    before[i] = j;
                }
            }
            if (max_dp < ++dp[i]) {
                max_idx = i;
                max_dp = dp[i];
            }
        }
        while (max_idx != -1) {
            ans.push_back(nums[max_idx]);
            max_idx = before[max_idx];
        }
        return ans;
    }
};