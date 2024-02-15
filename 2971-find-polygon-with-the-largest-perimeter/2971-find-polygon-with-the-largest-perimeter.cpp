class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        long long ans = -1;
        sort(nums.begin(),nums.end());
        long long sums = nums[0] + nums[1];
        for(int i = 2; i < nums.size(); ++i) {
            if(sums > nums[i])
                ans = sums + nums[i];
            sums += nums[i];
        }
        return ans;
    }
};