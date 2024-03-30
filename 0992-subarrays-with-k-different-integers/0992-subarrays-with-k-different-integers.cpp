const static auto _ = [](){cin.tie(0); cout.tie(0); ios::sync_with_stdio(0); return nullptr;}();
class Solution {
private:
    int subarraysUnderKDistinct(vector<int>& nums, int k) {
        int ans = 0, diff = 0;
        int len = nums.size();
        vector<int> cnt(len + 1);
        for(int s = 0, e = 0; e < len; ++e) {
            if(++cnt[nums[e]] == 1)
                ++diff;
            while(s <= e && diff > k) {
                if(--cnt[nums[s++]] == 0)
                    --diff;
            }
            ans += e - s + 1;
        }
        return ans;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return(subarraysUnderKDistinct(nums,k) - subarraysUnderKDistinct(nums,k - 1));
    }
};