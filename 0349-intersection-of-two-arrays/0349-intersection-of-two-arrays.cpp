class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> rtn;
        int check[1001] = {0};
        for(int i = 0; i < nums1.size(); ++i)
            if(check[nums1[i]] == 0)
                ++check[nums1[i]];
        for(int i = 0; i <nums2.size(); ++i)
            if(check[nums2[i]] == 1) {
                rtn.push_back(nums2[i]);
                --check[nums2[i]];
            }
        return rtn;
    }
};