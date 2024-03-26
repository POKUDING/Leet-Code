class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for(int i = 0; i < nums.size(); ++i)
            if(nums[i] <= 0)
                nums[i] = INT_MAX;
        for(int i = 0; i < nums.size(); ++i) {
            // cout << nums[i] << ": ";
            if(abs(nums[i]) - 1 < nums.size() && nums[abs(nums[i]) - 1] > 0) {
                
                nums[abs(nums[i]) - 1] *= -1;
            // cout << nums[abs(nums[i]) - 1] << " ";
            }
        }
        // cout << "\n";
        // for(int i = 0; i < nums.size(); ++i)
            // cout << nums[i] << " ";
        for(int i = 0 ; i < nums.size(); ++i)
            if(nums[i] >= 0)
                return i + 1;
        return nums.size() + 1;
    }
};