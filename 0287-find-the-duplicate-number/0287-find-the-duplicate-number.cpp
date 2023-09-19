class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        sort(nums.begin(),nums.end());
        for(int i = 0, size = nums.size() - 1; i < size; ++i)
        {
          if (nums[i] == nums[i + 1])
            return nums[i];
        }
        return -1;
    }
};