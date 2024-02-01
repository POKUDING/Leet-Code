class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int len = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> empty;
        vector<vector<int>> rtn(len / 3, vector<int>());

        for (int i = 0; i < len; ++i) {
            if (rtn[i / 3].empty() || nums[i] - rtn[i / 3].front() <= k)
                rtn[i / 3].push_back(nums[i]);
            else
                return empty;
        }
        return rtn;
    }
};