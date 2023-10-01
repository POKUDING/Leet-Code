class Solution {
public:
    string reverseWords(string s) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        string::iterator it = s.begin();
        string::iterator begin_it = s.begin();
        int size = s.size();
        for(int i = 0; i <= size; ++i)
        {
            if (i == size || isspace(s[i]))
            {
                reverse(it,begin_it + i);
                it = begin_it + i + 1;
            }
        }
        return s;
    }
};