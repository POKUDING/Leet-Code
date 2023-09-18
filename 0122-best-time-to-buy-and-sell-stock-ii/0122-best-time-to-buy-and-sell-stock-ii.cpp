class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ret = 0;
        ios::sync_with_stdio(0);
        cin.tie(0);

        for (int i = 1, size = prices.size(); i < size; ++i)
        {
            if (prices[i] > prices[i - 1])
                ret += prices[i] - prices[i - 1];
        }
        return ret;
    }
};