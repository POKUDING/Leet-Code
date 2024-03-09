class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        for(int i = 0, j = 0; i < nums1.size() && j < nums2.size();++i){
            while(j < nums2.size() && nums1[i] > nums2[j])
                ++j;
            if (j < nums2.size() && nums1[i] == nums2[j])
                return nums1[i];
        }
        return -1;
    }
};