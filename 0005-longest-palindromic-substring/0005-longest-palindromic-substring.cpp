class Solution {
public:
    bool checker(string& str,int i, int j)
    {
        while (i < j)
        {
            if (str[i] != str[j])
                return false;
            ++i;
            --j;
        }
        return true;
    }
    string longestPalindrome(string s) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        int len = s.length();
        int max = 0;
        string ans;
        for (int i = 0; i < len - 1; ++i)
        {
            for (int j = len; j > i; --j)
            {
                if (j - i < max)
                    break ;
                if (checker(s,i,j))
                {
                    ans = s.substr(i, j - i + 1);
                    max = ans.length();
                }
            }
        }
        if(max == 0)
            return s.substr(0, 1);
        return ans;
    }
};