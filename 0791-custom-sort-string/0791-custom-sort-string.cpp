class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char,int> pos;
        for(int i = 0; i < order.size(); ++i)
            pos[order[i]] = i + 1;
        sort(s.begin(),s.end(),[&](char s1, char s2){return pos[s1] < pos[s2];});
        return s;
    }
};