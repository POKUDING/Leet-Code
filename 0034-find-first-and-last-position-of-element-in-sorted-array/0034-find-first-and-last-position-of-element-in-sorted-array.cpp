class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> rtn(2, -1);
        vector<int>::iterator low, up;
        
        low = lower_bound(nums.begin(), nums.end(), target);
        up = upper_bound(nums.begin(), nums.end(), target);
        if (low != nums.end() && *low == target)
        {
            rtn[0] = (low - nums.begin());
            rtn[1] = (up - nums.begin() - 1);
        }
        return rtn;
    }
};