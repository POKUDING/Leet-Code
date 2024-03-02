const static auto _ = [](){cin.tie(0); cout.tie(0); ios::sync_with_stdio(0); return nullptr;}();
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int size = nums.size();
        vector<int> rtn(size);
        for(int i = size - 1, s = 0, e = i; i >= 0; --i){
            if(abs(nums[s]) >= abs(nums[e]))
                rtn[i] = pow(nums[s++],2);
            else
                rtn[i] = pow(nums[e--],2);
        }
        return rtn;
    }
};