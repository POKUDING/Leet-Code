class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size() / 3;
        unordered_map<int, int> store;
        vector<int> rtn;
    
        for(auto i : nums) {
            ++store[i];
            if(store[i] == n + 1)
                rtn.push_back(i);
        }
        return rtn;
    }
};