class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> rtn;
        vector<int>::iterator low, up;
        
        low = lower_bound(nums.begin(), nums.end(), target);
        up = upper_bound(nums.begin(), nums.end(), target);
        if (low == nums.end() || *low != target)
        {
            rtn.push_back(-1);
            rtn.push_back(-1);
        }
        else
        {
            rtn.push_back(low - nums.begin());
            rtn.push_back(up - nums.begin() - 1);
        }
        return rtn;
    }
};