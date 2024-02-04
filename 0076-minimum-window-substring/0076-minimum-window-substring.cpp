class Solution {
public:
    string minWindow(string s, string t) {
        int mp[126] = {0};
        pair<int,int> rtn = {-1,INT_MAX};
        int cnt = t.size();

        for(int i = 0; i < t.size(); ++i)
            ++mp[t[i]];
        
        for(int end = 0, start = 0; end < s.size(); ++end) {
            if (--mp[s[end]] >= 0)
                --cnt;
            while(cnt == 0) {
                if(end - start + 1 < rtn.second)
                    rtn = {start, end - start + 1};
                if (++mp[s[start]] > 0)
                    ++cnt;
                ++start;
            }
        }
        if (rtn.second == INT_MAX)
            return "";
        return s.substr(rtn.first, rtn.second);
    }
};