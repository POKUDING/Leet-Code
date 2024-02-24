class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        queue<tuple<int,int>> que;
        vector<int> know(n, INT_MAX);
        set<int> rtn;
        vector<vector<vector<int>>> memo(n);

        for(int i = 0; i < meetings.size(); ++i) {
            memo[meetings[i][0]].push_back({meetings[i][1], meetings[i][2]});
            memo[meetings[i][1]].push_back({meetings[i][0], meetings[i][2]});
        }
        que.push(make_tuple(0, 0));
        que.push(make_tuple(firstPerson, 0));
        know[0] = 0;
        know[firstPerson] = 0;
        while(!que.empty()) {
            auto [from, time] = que.front();
            rtn.insert(from);
            que.pop();
            for(int i = 0; i < memo[from].size(); ++i) {
                int meeted = memo[from][i][0];
                int meetedtime = memo[from][i][1];
                if(know[meeted] > meetedtime && meetedtime >= time) {
                    know[meeted] = meetedtime;
                    que.push(make_tuple(meeted, meetedtime));
                }
            }
        }
        return vector<int>(rtn.begin(), rtn.end());
    }
};