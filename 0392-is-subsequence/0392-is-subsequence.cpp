class Solution {
public:
    bool isSubsequence(string s, string t) {
        int t_size = t.size();
        int s_size = s.size();
        if (s_size == 0)
            return true;
        for(int i = 0, j = 0; i < t_size; ++i)
        {
            if (t[i] == s[j])
                if(s_size == ++j)
                    return true;
        }
        return false;
    }
};