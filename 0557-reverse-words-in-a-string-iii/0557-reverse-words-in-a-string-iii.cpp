class Solution {
public:
    string reverseWords(string s) {
        string::iterator it = s.begin();
        string::iterator begin_it = s.begin();
        int size = s.size();
        for(int i = 0; i <= size; ++i)
        {
            if (i == size || s[i] == ' ')
            {
                reverse(it,begin_it + i);
                it = begin_it + i + 1;
            }
        }
        return s;
    }
};