class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ret = 0;
        int hold = -1;
        ios::sync_with_stdio(0);
        cin.tie(0);

        for (int i = 0, size = prices.size(); i < size; ++i)
        {
            if (hold >= 0 && prices[i] > hold)
            {
                ret += prices[i] - hold;
                hold = -1;
            }
            if (hold < 0 && i < size - 1 && prices[i] < prices[i + 1])
                hold = prices[i];
        }
        return ret;
    }
};