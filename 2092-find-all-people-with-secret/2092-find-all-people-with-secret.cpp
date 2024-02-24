class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<pair<int,int>>graph[n];
        vector<int>result;
        for(int i=0;i<meetings.size();i++){
            graph[meetings[i][0]].push_back(make_pair(meetings[i][1],meetings[i][2]));
            graph[meetings[i][1]].push_back(make_pair(meetings[i][0],meetings[i][2]));
        }
        queue<int>q;
        vector<int>infoTime(n,-1);
        q.push(0);
        q.push(firstPerson);
        infoTime[0]=0;
        infoTime[firstPerson]=0;
        while(q.size()!=0){
            int f=q.front();
            q.pop();
            for(int i=0;i<graph[f].size();i++){
                int child=graph[f][i].first;
                int time=graph[f][i].second;
                if((infoTime[child]==-1 && infoTime[f]<=time) ||
                  (infoTime[child]!=-1 && infoTime[f]<=time && time<infoTime[child])){
                      infoTime[child]=time;
                      q.push(child);
                  }
            }
        }
        for(int i=0;i<infoTime.size();i++){
            if(infoTime[i]!=-1)
                result.push_back(i);
        }
        return result;
    }
};