const static auto _ = []() {cin.tie(0); cout.tie(0); ios::sync_with_stdio(0); return nullptr;}();
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> mp;
        int sum = 0;
        int max_len = 0;
        for(int i = 0; i < nums.size(); ++i) {
            sum += nums[i] == 0 ? 1 : -1;
            if(sum == 0)
                max_len = i + 1;
            if(mp[sum] != 0)
                max_len = max(max_len, i - mp[sum] + 1);
            else
                mp[sum] = i + 1;
        }
        return max_len;
    }
};