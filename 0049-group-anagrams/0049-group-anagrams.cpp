class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        cin.tie(0);
        ios::sync_with_stdio(0);
        map<string,vector<string>> memo;
        vector<vector<string>> rtn;

        for(auto it = strs.begin(); it != strs.end(); ++it) {
            string tmp(*it);
            sort(tmp.begin(), tmp.end());
            memo[tmp].push_back(*it);
        }
        for(auto it = memo.begin(); it != memo.end(); ++it)
            rtn.push_back(it->second);
        return rtn;
    }
};