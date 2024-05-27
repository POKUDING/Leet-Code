class Solution {
    public int specialArray(int[] nums) {
        Arrays.sort(nums);
        int sIdx = 0;
        int eIdx = nums.length;

        while(sIdx <= eIdx) {
            int mid = (sIdx + eIdx) / 2;
            int currIdx = nums.length - mid;
            // System.out.println(sIdx + " " + eIdx + " " + mid + " " + currIdx);
            if ((mid == 0 || nums[currIdx] >= mid) && (currIdx - 1 == -1 || nums[currIdx - 1] < mid))
                return mid;
            if(currIdx >= nums.length || nums[currIdx] > mid)
                sIdx = mid + 1;
            else
                eIdx = mid - 1;
            // System.out.println(sIdx + " " + eIdx + " " + mid + " " + currIdx +"\n");
        }
        return -1;
    }
}