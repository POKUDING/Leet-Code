class Solution {
public:
    bool canJump(vector<int>& nums) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        int size = nums.size();
        for(int i = 0; i < size - 1; ++i)
        {
            if (nums[i] == 0)
            {
                int j = i - 1;

                while (j >= 0)
                {
                    if(nums[j] + j > i)
                        break;
                    --j;
                }
                if (j < 0)
                    return false;
            }
        }
        return true;
    }
};