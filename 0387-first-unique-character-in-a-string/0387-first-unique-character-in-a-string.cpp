class Solution {
public:
    int firstUniqChar(string s) {
        int memo[126] = {0};

        for(int i = 0, l = s.size(); i < l; ++i)
            ++memo[s[i]];
        for(int i = 0, l = s.size(); i < l; ++i)
            if(memo[s[i]] == 1)
                return i;
        return -1;
    }
};