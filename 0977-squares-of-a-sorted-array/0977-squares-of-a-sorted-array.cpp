class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> rtn(nums.size());
        for(int i = nums.size() - 1, s = 0, e = i; i >= 0; --i){
            if(abs(nums[s]) >= abs(nums[e]))
                rtn[i] = pow(nums[s++],2);
            else
                rtn[i] = pow(nums[e--],2);
        }
        return rtn;
    }
};