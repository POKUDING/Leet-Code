class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int mid = INT_MIN;
        stack<int> before;
        before.push(nums.back());
        for (int i = nums.size() - 2; i >= 0; --i)
        {
            if (nums[i] < mid)
                return true;
            while (!before.empty() && nums[i] > before.top())
            {
                mid = before.top();
                before.pop();
            }
            before.push(nums[i]);
        }
        return false;
    }
};