class Solution {
    public boolean judgeSquareSum(int c) {
        long l = 0;
        long r = (int)Math.sqrt(c);

        while(l <= r) {
            long tmp = (l*l) + (r*r);
            // System.out.println(tmp);
            if(tmp == c)
                return true;
            else if(tmp < c)
                ++l;
            else
                --r;
        }
        return false;
    }
}