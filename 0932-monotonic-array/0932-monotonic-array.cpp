class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int size = nums.size();
        int i = 0;
        while(i < size - 1 && nums[i] <= nums[i + 1])
            ++i;
        if (i == size - 1)
            return true;
        i = 0;
        while(i < size - 1 && nums[i] >= nums[i + 1])
            ++i;
        if (i == size -1)
            return true;
        return false;
    }
};