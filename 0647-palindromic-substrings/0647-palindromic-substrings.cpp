class Solution {
public:
    int cnt(int s, int e, string& str) {
        int rtn = 0;
        while(s >= 0 && e < str.size()) {
            if(str[s--] == str[e++])
                ++rtn;
            else 
                break;
        }
        return rtn;
    }
    int countSubstrings(string s) {
        int ans = 0;
        for(int i = 0; i < s.size(); ++i) {
            ans += cnt(i, i, s);
            ans += cnt(i, i + 1, s);
        }
        return ans;
    }
};