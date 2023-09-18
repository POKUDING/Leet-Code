class Solution {
public:
    int jump(vector<int>& nums) {
        int size = nums.size();
        int tmp, ret = 0;
        for (int i = nums.size() - 1,j; i > 0; i = tmp)
        {
            j = i;
            while(--j >= 0)
            {
                if (nums[j] + j >= i)
                    tmp = j;
            }
            ++ret;
        }
        return ret;
    }
};