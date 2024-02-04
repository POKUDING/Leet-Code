class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> Map;
        unordered_map<char,int> cnt;
        string rtn;
        pair<int, int> tmp = {-1, s.size() + 1};
        int start = -1, end;
        int len = t.size();

        for(int i = 0; i < t.size(); ++i) {
            ++Map[t[i]];
        }
        while(++start < s.size())
            if(Map[s[start]] > 0)
                break;
        end = start - 1;
        while(true) {
            while(len > 0 && ++end < s.size()) {
                if(Map[s[end]] > 0) {
                    if(Map[s[end]] > cnt[s[end]])
                        --len;
                    ++cnt[s[end]];
                }
            }
            if (len != 0 || (tmp.first == start && tmp.second == end - start + 1))
                break;
            if (tmp.second > end - start + 1)
                tmp = {start, end - start + 1};
            while(start < end && len <= 1) {
                if(Map[s[start]] > 0) {
                    if(Map[s[start]] < cnt[s[start]])
                        --cnt[s[start]];
                    else if(Map[s[start]] == cnt[s[start]] && len == 0) {
                        ++len;
                        --cnt[s[start]];
                    } else
                        break;
                }
                ++start;
                if (len == 0 && tmp.second > end - start + 1)
                    tmp = {start, end - start + 1};
            }
        }
        if(tmp.first == -1)
            return "";
        return s.substr(tmp.first, tmp.second);
    }
};