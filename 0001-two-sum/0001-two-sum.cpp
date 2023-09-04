class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> rtn;
        for (int i = 0,end = nums.size(); i < end; ++i)
        {
            for (int j = i + 1; j < end; ++j)
            {
                if (nums[i] + nums[j] == target)
                {
                    rtn.push_back(i);
                    rtn.push_back(j);
                    return rtn;
                }
            }
        }
        return rtn;
    }
};