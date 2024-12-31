class Solution {
    public int mincostTickets(int[] days, int[] costs) {
        int maxDay = days[days.length - 1];
        boolean[] travelDays = new boolean[maxDay + 1];
        int[] dp = new int[maxDay + 1];

        for(int day: days)
            travelDays[day] = true;

        dp[0] = 0;

        for(int day = 1; day <= maxDay; ++day) {
            if(travelDays[day] == false) {
                dp[day] = dp[day - 1];
                continue;
            }

            dp[day] = dp[day - 1] + costs[0];
            dp[day] = Math.min(dp[day], dp[Math.max(0, day - 7)] + costs[1]);
            dp[day] = Math.min(dp[day], dp[Math.max(0, day - 30)] + costs[2]);
        }
        return dp[maxDay];
    }
}