const static auto _ = [](){cin.tie(0); cout.tie(0); ios::sync_with_stdio(0); return nullptr;}();
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int ans = 1;
        sort(points.begin(), points.end(),[](vector<int>& vec1, vector<int>& vec2) {
            if (vec1[1] == vec2[1])
                return vec1[0] < vec2[0];
            return vec1[1] < vec2[1];
        });
        int curr_end = points[0][1];
        for(int i = 1; i < points.size(); ++i) {
            if(points[i][0] <= curr_end)
                continue;
            curr_end = points[i][1];
            ++ans;
        }
        return ans;
    }
};