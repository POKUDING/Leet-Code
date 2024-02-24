class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        queue<int> que;
        vector<int> know(n, INT_MAX);
        vector<int> rtn;
        vector<vector<vector<int>>> memo(n);

        for(int i = 0; i < meetings.size(); ++i) {
            memo[meetings[i][0]].push_back({meetings[i][1], meetings[i][2]});
            memo[meetings[i][1]].push_back({meetings[i][0], meetings[i][2]});
        }
        que.push(0);
        que.push(firstPerson);
        know[0] = 0;
        know[firstPerson] = 0;
        while(!que.empty()) {
            int from = que.front();
            int time = know[from];
            que.pop();
            for(int i = 0; i < memo[from].size(); ++i) {
                int met = memo[from][i][0];
                int mettime = memo[from][i][1];
                if(know[met] > mettime && mettime >= time) {
                    know[met] = mettime;
                    que.push(met);
                }
            }
        }
        for(int i = 0; i < n; ++i) {
            if(know[i] != INT_MAX)
                rtn.push_back(i);
        }
        return rtn;
    }
};