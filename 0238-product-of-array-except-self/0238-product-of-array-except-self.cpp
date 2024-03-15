class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> output;
        int n=nums.size();
        output.push_back(1);
        for(int i=1;i<=n;i++){
            output.push_back(output[i-1]*nums[i-1]);
        }
        int right=1;
        for(int i=n-1;i>=0;i--){
            output[i]*=right;
            right*=nums[i];
        }
        output.pop_back();
        return output;
    }
};