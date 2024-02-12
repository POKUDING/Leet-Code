class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cur = 0, cnt = 0;
        for(int i = 0; i < nums.size(); ++i) {
            if (cnt == 0) {
                cur = nums[i];
                ++cnt;
            } else if (cur == nums[i])
                ++cnt;
            else
                --cnt;
        }
        return cur;
    }
};