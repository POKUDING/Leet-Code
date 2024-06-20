class Solution {
    public int maxDistance(int[] position, int m) {
        Arrays.sort(position);
        int min = 0;
        int max = position[position.length - 1] - position[0];
        int mid = 0;
        int cnt = 0;

        while(min < max && cnt++ < 50) {
            mid = (min + max) / 2 + 1;
            // System.out.println("mid: " + mid);
            if(isPossible(position, m, mid))
                min = mid;
            else
                max = mid - 1;
            // System.out.println("mid: " + mid + ", max: " + max + ", min: " + min);
        }
        return min;
    }

    public static boolean isPossible(int[] position, int m, int force) {
        int prevPos = position[0];
        --m;
        for(int i = 1; i < position.length; ++i) {
            if(position[i] >= force + prevPos) {
                --m;
                prevPos = position[i];
            }
            if(m == 0)
                return true;
        }
        return false;
    }
}