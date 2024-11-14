class Solution {
    public int minimizedMaximum(int n, int[] quantities) {
        int min = 1;
        int max = 0;

        for(int quantity: quantities)
            max = Math.max(max, quantity);

        if (n == quantities.length)
            return max;

        int curr = 0;
        int cnt = 0;
        while (min < max) {
            curr = (min + max) / 2;
            if (isPossible(n, quantities, curr))
                max = curr;
            else
                min = curr + 1;
            // System.out.println("curr: " + curr + ", min: " + min + ", max: " + max);
        }
        return max;
    }

    private boolean isPossible(int n, int[] quantities, int curr) {
        int cnt = 0;
        for (int quantity: quantities) {
            cnt += quantity / curr;
            if (quantity % curr > 0)
                ++cnt;
            // System.out.println(cnt);
            if (cnt > n)
                return false;
        }
        return true;
    }
}