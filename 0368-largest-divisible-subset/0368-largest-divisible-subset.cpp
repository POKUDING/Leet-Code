class Solution {
public:
    vector<vector<int>> dp;
    vector<int> getMax(int idx, vector<int>& nums) {
        int maxsize = 0;
        vector<int> tmp;
        if (dp[idx].size() != 0)
            return dp[idx];
        for (int i = 0; i < idx; ++i) {
            if (nums[idx] % nums[i] == 0) {
                tmp = getMax(i, nums);
                if (tmp.size() > maxsize) {
                    dp[idx] = tmp;
                    maxsize = tmp.size();
                }
            }
        }
        dp[idx].push_back(nums[idx]);
        return dp[idx];
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        dp = vector<vector<int>>(1001, vector<int>());
        int maxidx = 0;
        int maxsize = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (maxsize < getMax(i, nums).size()) {
                maxidx = i;
                maxsize = dp[i].size();
            }
        }
        return dp[maxidx];
    }
};