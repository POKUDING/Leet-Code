class Solution {
    public int findLengthOfShortestSubarray(int[] arr) {
        int leftIdx = 0;
        int rightIdx = arr.length - 1;

        while (leftIdx + 1 < arr.length && arr[leftIdx] <= arr[leftIdx + 1])
            ++leftIdx;
        while (rightIdx > 0 && arr[rightIdx] >= arr[rightIdx - 1])
            --rightIdx;

        int ans = Math.min(arr.length - leftIdx - 1, rightIdx);
        
        int i = leftIdx;
        int j = arr.length - 1;
        while (i >= 0 && j >= rightIdx && j > i) {
            if (arr[i] <= arr[j])
                --j;
            else
                --i;
            ans = Math.min(ans, j - i);
        }
        return ans;
    }
}