class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> empty;
        vector<vector<int>> rtn;
        for (int i = 0,size = nums.size(); i < size; i += 3) {
            if (nums[i + 2] - nums[i] > k)
                return empty;
            rtn.push_back({nums[i], nums[i + 1], nums[i + 2]});
        }
        return rtn;
    }
};