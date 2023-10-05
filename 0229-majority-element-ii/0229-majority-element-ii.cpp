class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size() / 3;
        unordered_map<int, int> store;
        vector<int> rtn;
    
        for(auto i : nums) {
            ++store[i];
        }
        for(auto num : store)
        {
            if(num.second > n)
                rtn.push_back(num.first);    
        }
        return rtn;
    }
};