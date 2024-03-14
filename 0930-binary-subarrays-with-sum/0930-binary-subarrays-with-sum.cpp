class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int s = 0, e = 0, backzero = 0, frontzero = 0, ans = 0;
        while(s < nums.size()) {
            e = s;
            int sum = nums[e];
            int frontzero = 0;
            int backzero = 0;
            if (sum > goal) {
                ++s;
                continue;
            }
            while(e + 1 < nums.size() && sum != goal)
                sum += nums[++e];
            if(e + 1 == nums.size() && sum != goal)
                return ans;
            while(s < e && nums[s] == 0) {
                ++s;
                ++frontzero;
            }
            int min_len = e - s + 1;
            while(e + 1 < nums.size() && nums[e + 1] == 0){
                ++e;
                ++backzero;
            }
            int max_len = min_len + backzero + frontzero;
            // cout << "here: "<<frontzero << " "<<backzero <<"\n";
            ans += (frontzero + 1) * (backzero + 1);
            // frontzero = min(frontzero, backzero) + 1;
            // for(int i = 1; max_len >= min_len; ++i, --max_len) {
            //     if (i - min_len > frontzero)
            //         --frontzero;
            //     ans += min(i, frontzero);
            //     cout << max_len << " "<< min_len <<"\n";
            //     cout << s << " " << e << " " <<i << " " << ans << "\n";
            // }
            s++;
        }
        return ans;
    }
};