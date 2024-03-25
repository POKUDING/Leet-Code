class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        vector<bool> check(nums.size());
        for(int i = 0; i < nums.size(); ++i) {
            if(check[nums[i]])
                ans.push_back(nums[i]);
            check[nums[i]] = true;
        }
        return ans;
    }
};