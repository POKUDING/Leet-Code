class Solution {
public:
    bool search(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end()); 
        if (find(nums.begin(),nums.end(), target) != nums.end())
            return true;
        return false;
    }
};