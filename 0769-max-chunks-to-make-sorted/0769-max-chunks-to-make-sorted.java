class Solution {
    public int maxChunksToSorted(int[] arr) {
        int ans = 0;
        boolean[] include = new boolean[arr.length];
        Arrays.fill(include, false);

        for(int leftIdx = 0; leftIdx < arr.length; ++leftIdx) {
            int rightIdx = leftIdx;
            int cnt = 0;
            while (rightIdx < arr.length) {
                include[arr[rightIdx]] = true;
                if(arr[rightIdx] < rightIdx)
                    ++cnt;
                if(include[rightIdx] == true)
                    ++cnt;

                if(cnt == rightIdx - leftIdx + 1) {
                    leftIdx = rightIdx;
                    break;
                }
                ++rightIdx;
            }
            if(rightIdx == arr.length)
                leftIdx = rightIdx;
            ++ans;
        }
        return ans;
    }
}