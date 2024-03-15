class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        vector<int> rtn;
        rtn.push_back(1);
        for(int i = 1; i < len; ++i)
            rtn.push_back(rtn[i - 1] * nums[i - 1]); 
        int right = 1;
        for(int i = len - 1; i >= 0; --i) {
            rtn[i] = rtn[i] * right;
            right *= nums[i];
        }
        return rtn;
    }
};