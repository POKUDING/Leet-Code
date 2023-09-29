class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
        int size = nums.size();
        int flag = 0;
        int i = 0;
        while(i < size - 1)
        {
            if (nums[i] != nums[i + 1])
            {
                flag = nums[i] - nums[i + 1];
                break;
            }
            ++i;
        }
        while(i < size - 1)
        {
            if (flag > 0 && nums[i] < nums[i + 1])
                return false;
            else if (flag < 0 && nums[i] > nums[i + 1])
                return false;
            ++i;
        }
        return true;
    }
};