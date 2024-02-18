class Solution {
public:
    static bool sortFunc(vector<int>& a, vector<int>&b) {
        if (a[0] != b[0])
            return a[0] > b[0];
        return a[1] < b[1];
    }
    int mostBooked(int n, vector<vector<int>>& meetings) {
        // if(n > meetings.size())
        //     return 0;
        priority_queue<pair<long long,int>,vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
        priority_queue<int,vector<int>, greater<int>> empty_room;
        vector<vector<int>> rooms(101, vector<int>(2));
        sort(meetings.begin(),meetings.end());
        // for(int i = 0; i < meetings.size(); ++i)
        //     cout <<meetings[i][0] << " " <<meetings[i][1] << "\n";
        for(int i = 0; i < n; ++i) {
            empty_room.push(i);
            rooms[i][1] = i;
        }
        for(int i = 0; i < meetings.size(); ++i) {
            long long start = meetings[i][0];
            long long end = meetings[i][1];
            while(!pq.empty() && pq.top().first <= (long long)start) {
                int roomnum = pq.top().second;
                pq.pop();
                empty_room.push(roomnum);
            }
            if(empty_room.empty()) {
                // cout << "not empty!\n";
                auto[roomend, roomnum ] = pq.top();
                // cout << "roomend: " << roomend << " roomnum: " << roomnum << " start: " << start <<  " end:  " << end << "\n";
                pq.pop();
                ++rooms[roomnum][0];
                if(roomend > (long long)start)
                    end += roomend - start;
                pq.push({end, roomnum});
            } else {
                int roomnum = empty_room.top();
                // cout << "empty! " << end << " " << roomnum << "\n";
                pq.push({end, roomnum});
                ++rooms[roomnum][0];
                // cout << rooms[roomnum][0] << "\n";
                empty_room.pop();
            }
        }
        sort(rooms.begin(),rooms.begin() + n, sortFunc);
        for(int i = 0; i < n; ++i) {
            cout << rooms[i][1] << " " <<rooms[i][0] << "\n";
        }
        return rooms[0][1];
    }
};