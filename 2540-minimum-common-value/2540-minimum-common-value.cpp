class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int nums1_len = nums1.size(), nums2_len = nums2.size();
        for(int i = 0, j = 0; i < nums1_len && j < nums2_len;++i){
            while(j < nums2_len && nums1[i] > nums2[j])
                ++j;
            if (j < nums2_len && nums1[i] == nums2[j])
                return nums1[i];
        }
        return -1;
    }
};