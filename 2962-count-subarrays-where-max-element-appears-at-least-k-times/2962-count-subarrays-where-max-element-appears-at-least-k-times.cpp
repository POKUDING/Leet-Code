class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int max_num = *max_element(nums.begin(),nums.end());
        map<long long, int> mp;
        int cnt = 0;
        long long ans = 0;
        for(int e = 0; e < nums.size(); ++e) {
            if(nums[e] == max_num) {
                ++cnt;
                mp[cnt] = e;
            }
            if(cnt >= k)
                ans += mp[cnt - k + 1] + 1;
        }
        return ans;
    }
};