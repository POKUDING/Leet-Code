class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int mod = pow(10,9) + 7;
        int size = arr.size();
        int ans = 0;
        unordered_map<int, long> dp;
        
        sort(arr.begin(), arr.end());
        for(int i = 0; i < size; ++i)
        {
            dp[arr[i]] = 1;
            for(auto j : dp)
            {
                if(arr[i] % j.first == 0 && dp.find(arr[i] / j.first) != dp.end())
                {
                    dp[arr[i]] += dp[j.first] * dp[arr[i] / j.first];            
                }
            }
        }
        for (auto i : dp)
            ans = (ans + i.second) % mod;
        return ans;
    }
};