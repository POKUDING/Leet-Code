class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        queue<tuple<int,int>> que;
        vector<int> know(n, INT_MAX);
        set<int> rtn;
        vector<vector<vector<int>>> memo(n);

        sort(meetings.begin(), meetings.end(), [](vector<int>& vec1, vector<int>&vec2) { return (vec1[2] < vec2[2]);} );
        for(int i = 0; i < meetings.size(); ++i) {
            memo[meetings[i][0]].push_back({meetings[i][1], meetings[i][2]});
            memo[meetings[i][1]].push_back({meetings[i][0], meetings[i][2]});
        }
        // for(int i = 0; i < memo.size(); ++i) {
        //     cout << i << " : ";
        //     for(int j = 0; j < memo[i].size(); ++j) {
        //         cout << "[" << memo[i][j][0] << ", " << memo[i][j][1] << "], ";
        //     }
        //     cout << "\n";
        // }
        que.push(make_tuple(0, 0));
        que.push(make_tuple(firstPerson, 0));
        know[0] = 0;
        know[firstPerson] = 0;
        while(!que.empty()) {
            auto [from, time] = que.front();
            // know[from] = true;
            rtn.insert(from);
            que.pop();
            for(int i = 0; i < memo[from].size(); ++i) {
                if(know[memo[from][i][0]] > memo[from][i][1] && memo[from][i][1] >= time) {
                    know[memo[from][i][0]] = memo[from][i][1];
                    que.push(make_tuple(memo[from][i][0], memo[from][i][1]));
                }
            }
        }
        //비밀을 알고있는 사람의 배열 알게된 시간을 업데이트?
        //미팅이 진행되며 해당 시간에 비밀을 알고있는 사람들을 업데이트
        //동시에 퍼지면 어떻게 해야하지?
        //미팅을 진행하고 있는 사람들의 배열을 만들어서 업데이트?
        //미팅목록을 먼저 사람을 key 상대와 시간을 value로 저장하고 한번에 업데이트?
        //각 사람의 미팅 목록을 배열로 정리 -> bfs로 탐색 시간이 알게된 시간 이후이고 만약 상대방이 모르고 있었다면 상대방을 que에 시간과 함께 넣어줌. 
        // sort(rtn.begin(),rtn.end());
        // for (int i = 0; i < know.size(); ++i) {
        //     cout << i << ": " << know[i] << "\n";
        // }
        return vector<int>(rtn.begin(), rtn.end());
    }
};