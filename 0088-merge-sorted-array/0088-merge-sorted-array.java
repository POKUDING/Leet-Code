class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int nums1_idx = m - 1, nums2_idx = n - 1, curr_idx = m + n - 1;
        while(nums1_idx >=0 && nums2_idx >= 0) {
            if(nums1[nums1_idx] > nums2[nums2_idx])
                nums1[curr_idx--] = nums1[nums1_idx--];
            else
                nums1[curr_idx--] = nums2[nums2_idx--];
        }
        while(nums2_idx >= 0)
            nums1[curr_idx--] = nums2[nums2_idx--];
    }
}