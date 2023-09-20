class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        int checker = 0;
        int answer = -1;
        int size = nums.size();

        for (int i = 0; i < size; ++i)
            checker += nums[i];
        if (checker < x)
            return -1;
        checker -= x;
        if (!checker)
            return nums.size();
        for(int l = 0, r = 0; r < size; ++r)
        {
            checker -= nums[r];
            while (l < r && checker < 0)
                checker += nums[l++];
            if (!checker)
                answer = max(answer, r - l + 1);
        }
        if (answer >= 0)
            answer = size - answer;
        return answer;
    }
};