class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>> memo;
        vector<vector<string>> rtn;

        for(int i = 0; i < strs.size(); ++i) {
            string tmp(strs[i]);
            sort(tmp.begin(), tmp.end());
            memo[tmp].push_back(strs[i]);
        }
        for(auto it = memo.begin(); it != memo.end(); ++it)
            rtn.push_back(it->second);
        return rtn;
    }
};