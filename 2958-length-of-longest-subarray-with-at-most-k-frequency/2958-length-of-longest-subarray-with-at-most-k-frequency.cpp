const static auto _ = [](){cin.tie(0); cout.tie(0); ios::sync_with_stdio(0); return nullptr;}();
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