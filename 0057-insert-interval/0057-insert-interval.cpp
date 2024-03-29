class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> rtn;
        int i = 0;
        for(;i < intervals.size() && intervals[i][1] < newInterval[0]; ++i)
            rtn.push_back(intervals[i]);
        for(;i < intervals.size() && intervals[i][0] <= newInterval[1]; ++i) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
        }
        rtn.push_back(newInterval);
        for(;i < intervals.size(); ++i)
            rtn.push_back(intervals[i]);
        return rtn;
    }
};