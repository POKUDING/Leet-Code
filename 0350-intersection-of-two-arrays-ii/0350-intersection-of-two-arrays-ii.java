class Solution {
    public int[] intersect(int[] nums1, int[] nums2) {
        List<Integer> list = new ArrayList<>();
        Arrays.sort(nums1);
        Arrays.sort(nums2);
        int num2Idx = 0;
        for(int num1Idx = 0; num1Idx < nums1.length && num2Idx < nums2.length; ++num1Idx) {
            while(num2Idx < nums2.length && nums2[num2Idx] < nums1[num1Idx])
                ++num2Idx;
            if(num2Idx < nums2.length && nums1[num1Idx] == nums2[num2Idx])
                list.add(nums2[num2Idx++]);
        }
        return list.stream().mapToInt(i->i).toArray();
    }
}