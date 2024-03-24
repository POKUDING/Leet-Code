const static auto _ =[](){cin.tie(0); cout.tie(0); ios::sync_with_stdio(0); return nullptr;}();
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int i = 0; i < nums.size(); ++i) {
            int num = abs(nums[i]);
            if(nums[num] < 0)
                return num;
            nums[num] = -nums[num];
        }
        return 0;
    }
};