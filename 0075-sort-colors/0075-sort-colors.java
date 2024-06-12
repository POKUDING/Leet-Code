class Solution {
    public void sortColors(int[] nums) {
        int i = 0;
        int l = 0;
        int r = nums.length - 1;

        while(i < nums.length) {
            if (l < i && nums[i] == 0)
                swap(nums, i, l++);
            else if(i < r && nums[i] == 2)
                swap(nums, i, r--);
            else ++i;
        }
    }

    public void swap(int[] nums, int l, int r) {
        nums[l] ^= nums[r];
        nums[r] ^= nums[l];
        nums[l] ^= nums[r];
    }
}