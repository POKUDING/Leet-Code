class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int ans = 0;
        for(int s = 0, e = 0; e < nums.size(); ++e) {
            ++mp[nums[e]];
            while(mp[nums[e]] > k)
                --mp[nums[s++]];
            ans = max(ans, e - s + 1);
        }
        return ans;
    }
};