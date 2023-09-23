
class Solution {
public:
    static bool compareByLength(std::string& a, std::string& b) {
        return a.length() < b.length();
    }
    int longestStrChain(vector<string>& words) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        int rtn = 0;
        unordered_map<string, int> map;
        int longest;

        sort(words.begin(), words.end(), compareByLength);
        for(string& s : words)
        {
            longest = 0;
            for (int i = 0, size = s.length(); i < size; ++i)
            {
                string tmp(s);
                tmp.erase(i, 1);
                longest = max(longest, map[tmp] + 1);
            }
            map[s] = longest;
            rtn = max(rtn, longest);
        }
        return rtn;
    }
};