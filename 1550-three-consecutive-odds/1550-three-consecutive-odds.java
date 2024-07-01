class Solution {
    public boolean threeConsecutiveOdds(int[] arr) {
        int i = 0;
        int j = 0;
        while(i < arr.length) {
            j = i;
            while(j < arr.length && arr[j] % 2 == 1) {
                ++j;
                if(j - i == 3)
                    return true;
            }
            i = j + 1;
        }
        return false;
    }
}