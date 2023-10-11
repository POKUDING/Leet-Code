class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<int> ans;
        vector<int> start;
        vector<int> end;
        for (auto i : flowers)
        {
            start.push_back(i[0]);
            end.push_back(i[1]);
        }
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());
        for(auto i : people)
        {
            int startflower = upper_bound(start.begin(),start.end(), i) - start.begin();
            int endflower = lower_bound(end.begin(),end.end(), i) - end.begin();
            ans.push_back(startflower - endflower);
        }
        return ans;
    }
};