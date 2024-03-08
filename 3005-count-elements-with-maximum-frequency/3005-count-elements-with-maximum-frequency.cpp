class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int prev = nums[0], ans = 0, max_cnt = 0, cnt = 0;
        for(int i = 0 ; i < nums.size(); ++i) {
            if(nums[i] == prev)
                ++cnt;
            else {
                if(cnt == max_cnt)
                    ans += cnt;
                else if (cnt > max_cnt) {
                    ans = cnt;
                    max_cnt = cnt;
                }
                cnt = 1;
            }
            prev = nums[i];
        }
        if(cnt == max_cnt)
            ans += cnt;
        else if (cnt > max_cnt)
            ans = cnt;
        return ans;
    }
};