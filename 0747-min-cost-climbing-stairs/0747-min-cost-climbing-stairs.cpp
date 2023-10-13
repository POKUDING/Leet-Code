class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(2, 0);
        int len = cost.size();

        for(int i = 2; i < len; ++i)
            dp.push_back(min({dp[i - 2] + cost[i - 2], dp[i - 1] + cost[i - 1]}));
        return min({dp[len - 2] + cost[len - 2], dp[len - 1] + cost[len - 1]});
    }
};