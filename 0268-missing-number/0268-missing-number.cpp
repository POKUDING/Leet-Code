class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int len = nums.size();
        int total_num = len + 1;
        for(int i = 0; i < len; ++i) {
            total_num += i + 1;
            total_num -= nums[i] + 1;
        }
        return total_num == 0 ? len : total_num - 1;
    }
};