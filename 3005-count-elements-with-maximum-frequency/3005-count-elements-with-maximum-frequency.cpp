class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> cnt;
        int ans = 0, max_cnt = 0;
        for(int i = 0 ; i < nums.size(); ++i) {
            ++cnt[nums[i]];
            if(cnt[nums[i]] == max_cnt)
                ans++;
            else if(cnt[nums[i]] > max_cnt) {
                ans = 1;
                max_cnt = cnt[nums[i]];
            }
        }
        return ans * max_cnt;
    }
};