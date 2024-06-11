class Solution {
    public int[] relativeSortArray(int[] arr1, int[] arr2) {
        int countNums[] = new int[1001];
        int rtn[] = new int[arr1.length];
        int idx = 0;

        for(int num : arr1)
            ++countNums[num];
        for(int arr2Num : arr2) {
            while(countNums[arr2Num] > 0) {
                --countNums[arr2Num];
                rtn[idx++] = arr2Num;
            }
        }
        for(int i = 0; i < 1001; ++ i) {
            while(countNums[i] > 0) {
                --countNums[i];
                rtn[idx++] = i;
            }
        }
        return rtn;
    }
}