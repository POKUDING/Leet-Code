class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        vector<int> dp(len);
        vector<int> revdp(len);
        vector<int> rtn(len);
        dp[0] = nums[0];
        for(int i = 1; i < len; ++i)
            dp[i] = dp[i - 1] * nums[i];
        revdp[len - 1] = nums[len - 1];
        for(int i = len - 2; i >= 0; --i)
            revdp[i] = revdp[i + 1] * nums[i];
        for(int i = 0; i < nums.size(); ++i) {
            rtn[i] = (i > 0 ? dp[i - 1] : 1) * (i < len - 1 ? revdp[i + 1] : 1);
        }
        return rtn;
    }
};