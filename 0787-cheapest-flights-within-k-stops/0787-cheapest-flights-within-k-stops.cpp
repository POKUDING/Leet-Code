class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<int>> memo(n + 1, vector<int>(n + 1));
        queue<tuple<int,int, int>> que;

        for (int i = 0; i < flights.size(); ++i) {
            if (flights[i][0] == src)
                que.push(make_tuple(flights[i][1], 0, flights[i][2]));
            if (flights[i][1] != src)
               memo[flights[i][0]][flights[i][1]] = flights[i][2];
        }
        while(!que.empty()) {
            auto [cur, dep, cost] = que.front();
            que.pop();
            for (int i = 0; i <= n; ++i) {
                if(memo[cur][i] == 0 || ( memo[src][i] && memo[src][i] <= cost + memo[cur][i]))
                    continue;
                memo[src][i] = cost + memo[cur][i];
                if(i != dst && dep < k)
                    que.push(make_tuple(i, dep + 1, memo[src][i]));
            }
        }
        return memo[src][dst] > 0 ? memo[src][dst] : -1;
    }
};