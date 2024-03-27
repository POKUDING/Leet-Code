class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ans = 0;
        int mul = 1;
        for(int s = 0, e = 0; e < nums.size(); ++e) {
            mul *= nums[e];
            while(s < e && mul >= k)
                mul /= nums[s++];
            // cout << s << " " << e << " " << nums[s] << " " << nums[e] << " " <<mul <<"\n";
            if(mul < k)
                ans += e - s + 1;
        }
        return ans;
    }
};