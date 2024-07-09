class Solution {
    public double averageWaitingTime(int[][] customers) {
        int currTime = customers[0][0];
        long totalTime = 0;
        for(int i = 0 ; i < customers.length; ++i) {
            if(currTime > customers[i][0])
                totalTime += currTime - customers[i][0];
            else
                currTime = customers[i][0];
            totalTime += customers[i][1];
            currTime += customers[i][1];
            // System.out.println(totalTime + " " + currTime);
        }
        return totalTime / (double)customers.length;
    }
}