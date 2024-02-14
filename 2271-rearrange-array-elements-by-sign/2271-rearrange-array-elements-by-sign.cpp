class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int len = nums.size();
        vector<int> rtn(len);

        for (int i = 0, j = 0, k = 1; i < len; ++i) {
            if (nums[i] >= 0) {
                rtn[j] = nums[i];
                j += 2;
            } else {
                rtn[k] = nums[i];
                k += 2;
            }
        }
        return rtn;
    }
};