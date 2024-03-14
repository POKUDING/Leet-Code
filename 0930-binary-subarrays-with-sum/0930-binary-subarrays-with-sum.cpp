class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int s = 0, e = 0, backzero = 0, frontzero = 0, ans = 0;
        while(s < nums.size()) {
            e = s;
            int sum = nums[e];
            int frontzero = 0;
            int backzero = 0;
            if (sum > goal) {
                ++s;
                continue;
            }
            while(e + 1 < nums.size() && sum != goal)
                sum += nums[++e];
            if(e + 1 == nums.size() && sum != goal)
                return ans;
            while(s < e && nums[s] == 0) {
                ++s;
                ++frontzero;
            }
            int min_len = e - s + 1;
            while(e + 1 < nums.size() && nums[e + 1] == 0){
                ++e;
                ++backzero;
            }
            int max_len = min_len + backzero + frontzero;
            ans += (frontzero + 1) * (backzero + 1);
            s++;
        }
        return ans;
    }
};