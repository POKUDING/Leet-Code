const static auto _ = [](){cin.tie(0); cout.tie(0); ios::sync_with_stdio(0); return nullptr;}();
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int s = -1, e = -1, n = -1;
        long long ans = 0;
        int len = nums.size();
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] == minK)
                s = i;
            if(nums[i] == maxK)
                e = i;
            if(nums[i] < minK || nums[i] > maxK)
                n = i;
            ans += max(0, min(s, e) - n);
        }
        return ans;
    }
};