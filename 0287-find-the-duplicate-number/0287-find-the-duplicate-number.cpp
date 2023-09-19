class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        int visit[100001] = {0};
        for(int i = 0, size = nums.size(); i < size; ++i)
        {
          if (visit[nums[i]])
            return nums[i];
          visit[nums[i]] = 1;
        }
        return -1;
    }
};