class Solution {
    public int maxSatisfied(int[] customers, int[] grumpy, int minutes) {
        int currSatisfied = 0;
        int rtn = 0;
        for(int i = 0; i < customers.length; ++i) {
            if(i < minutes)
                currSatisfied += customers[i];
            else
                currSatisfied += grumpy[i] == 1 ? 0 : customers[i];
        }
        rtn = currSatisfied;
        // System.out.println(rtn);
        for(int i = 0; i + minutes < customers.length; ++i) {
            currSatisfied -= grumpy[i] == 1 ? customers[i] : 0;
            currSatisfied += grumpy[i + minutes] == 1 ? customers[i + minutes] : 0;
            rtn = Math.max(rtn, currSatisfied);
            // System.out.println(i + " " + (i + minutes) + " " + rtn);
        }
        return rtn;
    }
}