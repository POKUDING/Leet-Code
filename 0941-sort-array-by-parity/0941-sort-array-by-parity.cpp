class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int front = 0;
        int end = nums.size() - 1;
        while(front < end)
        {
            while (front < end && nums[front] % 2 == 0)
                ++front;
            while(front < end && nums[end] % 2 == 1)
                --end;
            if (front < end)
                swap(nums[front], nums[end]);
        }
        return nums;
    }
};