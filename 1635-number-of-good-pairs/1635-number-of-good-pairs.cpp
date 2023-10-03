class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int rtn = 0;
        unordered_map<int, int> map;

        for (int i = 0, size = nums.size(); i < size; ++i)
            ++map[nums[i]];
        for (unordered_map<int,int>::iterator it = map.begin(); it != map.end(); ++it)
            rtn += (it->second * (it->second - 1)) / 2;
        return rtn;
    }
};