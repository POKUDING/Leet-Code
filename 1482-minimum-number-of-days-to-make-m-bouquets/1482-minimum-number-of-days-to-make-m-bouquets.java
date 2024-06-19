class Solution {
    public int minDays(int[] bloomDay, int m, int k) {
        long min = 1;
        long max = 2147483647;
        long mid = -1;
        if(bloomDay.length < m * k || (long)m * (long)k > max)
            return -1;

        while(min < max) {
            mid = (min + max) / 2;
            System.out.println("min: " + min + ", max: " + max + ", mid: " +mid);
            if (canMake(mid, bloomDay, m, k))
                max = mid;
            else
                min = mid + 1;
            System.out.println("min: " + min + ", max: " + max + ", mid: " +mid);
        }
        return (int)min;
    }

    public static boolean canMake(long day, int[] bloomDay, int m, int k) {
        int currLen = 0;
        for(int bloom : bloomDay) {
            currLen = bloom <= day ? currLen + 1 : 0;
            if(currLen == k) {
                currLen = 0;
                --m;
            }
        }
        if(m > 0)
            return false;
        return true;
    }
}