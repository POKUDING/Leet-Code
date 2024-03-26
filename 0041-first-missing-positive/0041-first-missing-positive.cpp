const static auto _ = [](){cin.tie(0); cout.tie(0); ios::sync_with_stdio(0); return nullptr;}();

// class Solution {
// public:
//     int firstMissingPositive(vector<int>& nums) {
//         for(int i = 0; i < nums.size(); ++i)
//             if(nums[i] <= 0)
//                 nums[i] = INT_MAX;
//         for(int i = 0; i < nums.size(); ++i)
//             if(abs(nums[i]) - 1 < nums.size() && nums[abs(nums[i]) - 1] > 0)
//                 nums[abs(nums[i]) - 1] *= -1;
//         for(int i = 0 ; i < nums.size(); ++i)
//             if(nums[i] >= 0)
//                 return i + 1;
//         return nums.size() + 1;
//     }
// };

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int N = nums.size();
        for(int i = 0; i < N; ++i) {
            while(0 < nums[i] && nums[i] <= N && nums[nums[i] - 1] != nums[i]) {
                int idx = nums[i] - 1;
                int tmp = nums[idx];
                nums[idx] = nums[i];
                nums[i] = tmp;
            }
        }
        for(int i = 0; i < N; ++i)
            if(nums[i] != i + 1)
                return i + 1;
        return N + 1;
    }
};