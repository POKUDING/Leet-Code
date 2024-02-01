class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int len = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> empty;
        vector<vector<int>> rtn(len / 3, vector<int>());

        for (int i = 0; i < len; i += 3) {
            if (nums[i + 2] - nums[i] <= k) {
                rtn[i / 3].push_back(nums[i]);
                rtn[i / 3].push_back(nums[i + 1]);
                rtn[i / 3].push_back(nums[i + 2]);
            } else
                return empty;
        }
        return rtn;
    }
};