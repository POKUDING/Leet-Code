class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 1;
        sort(nums.begin(),nums.end());
        for(int i = 0; i < nums.size(); ++i) {
            if(i + 1 == nums.size() || nums[i] != nums[i + 1]) {
                if (cnt > nums.size() / 2)
                    return nums[i];
                cnt = 1;
            } else
                ++cnt;
        }
        return 0;
    }
};