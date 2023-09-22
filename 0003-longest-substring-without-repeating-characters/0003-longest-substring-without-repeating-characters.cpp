class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int rtn = 0;
        string tmp;

        for(int i = 0, size = s.size(); i < size; ++i)
        {
            for(int j = i; j < size; ++j)
            {
                if (tmp.find(s[j]) != string::npos)
                {
                    if (rtn < tmp.size())
                        rtn = tmp.size();
                    tmp.clear();
                    break;
                }
                tmp += s[j];
            }
        }
        if (rtn < tmp.size())
            rtn = tmp.size();
        return rtn;
    }
};