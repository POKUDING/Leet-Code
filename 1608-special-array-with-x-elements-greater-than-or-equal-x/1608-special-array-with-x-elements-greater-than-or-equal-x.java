class Solution {
    public int specialArray(int[] nums) {
        int[] counts = new int[nums.length + 1];
        for(int num : nums)
            ++counts[num > nums.length ? nums.length : num];
        int addCount = 0;
        for(int i = counts.length - 1; i >= 0; --i) {
            addCount += counts[i];
            if(addCount > i)
                return -1;
            if(addCount == i)
                return i;
        }
        return -1;
    }
}