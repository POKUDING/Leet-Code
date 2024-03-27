const static auto _ = [](){cin.tie(0); cout.tie(0); ios::sync_with_stdio(0); return nullptr;}();
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ans = 0;
        int mul = 1;
        for(int s = 0, e = 0; e < nums.size(); ++e) {
            mul *= nums[e];
            while(s < e && mul >= k)
                mul /= nums[s++];
            if(mul < k)
                ans += e - s + 1;
        }
        return ans;
    }
};