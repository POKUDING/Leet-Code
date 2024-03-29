const static auto _ = [](){cin.tie(0); cout.tie(0); ios::sync_with_stdio(0); return nullptr;}();
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int max_num = *max_element(nums.begin(),nums.end());
        int cnt = 0;
        long long ans = 0;
        int len = nums.size();
        for(int s = 0, e = 0; e < len; ++e) {
            if(nums[e] == max_num)
                ++cnt;
            while (cnt >= k){
                ans += len - e;
                if(nums[s++] == max_num)
                    --cnt;
            }
        }
        return ans;
    }
};