class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int num1_i = 0;
        int num2_i = 0;
        int num1_size = nums1.size();
        int num2_size = nums2.size();
        double rtn;
        vector<int> tmp;
        while(num1_i < num1_size && num2_i < num2_size)
        {
            if (nums1[num1_i] < nums2[num2_i])
                tmp.push_back(nums1[num1_i++]);
            else
                tmp.push_back(nums2[num2_i++]);
        }
        while(num1_i < num1_size)
            tmp.push_back(nums1[num1_i++]);
        while(num2_i < num2_size)
            tmp.push_back(nums2[num2_i++]);
        rtn = tmp[(num1_size + num2_size)/ 2];
        // cout << rtn;
        if (!((num1_size + num2_size) % 2))
        {
            rtn += tmp[((num1_size + num2_size) / 2) - 1];
            cout << rtn;
            rtn /= 2;
        }
        return rtn;
    }
};