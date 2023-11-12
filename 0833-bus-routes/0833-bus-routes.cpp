class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        queue<pair<int, int> > que;
        int               visit_bus[501] = {0,};
        int               visit_station[1000001] = {0, };
        map<int, vector<int> >  station_info;

        if(target == source)
            return 0;
        visit_station[target] = 1;
        for(int i = 0; i < routes.size(); ++i)
        {
            for(int j = 0; j < routes[i].size(); ++j)
            {
                station_info[routes[i][j]].push_back(i);
                if (routes[i][j] == target)
                {
                    que.push(make_pair(1, i));
                    visit_bus[i] = 1;
                }
            }
        }
        while(!que.empty())
        {
            pair<int, int> bus = que.front();
            for (int i = 0; i < routes[bus.second].size(); ++i)
            {
                if (routes[bus.second][i] == source)
                    return bus.first;
                if (visit_station[routes[bus.second][i]])
                    continue ;
                for (int j = 0; j < station_info[routes[bus.second][i]].size(); ++j)
                {
                    if (!visit_bus[station_info[routes[bus.second][i]][j]])
                    {
                        que.push(make_pair(bus.first + 1, station_info[routes[bus.second][i]][j]));
                        visit_station[routes[bus.second][i]] = 1;
                        visit_bus[station_info[routes[bus.second][i]][j]] = 1;
                    }
                }
            }
            que.pop();
        }
        return -1;
    }
};