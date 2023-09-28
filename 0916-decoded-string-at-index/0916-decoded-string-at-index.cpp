class Solution {
public:
    string decodeAtIndex(string s, int k) {
        long long len = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (isdigit(s[i]))
                len *= s[i] - '0';
            else
                ++len;
        }

        for (int i = s.size() - 1; i >= 0; --i) {
            if(isdigit(s[i])) {
                len /= (s[i] - '0');
                k = k % len;
            } else {
                if (k == 0 || len == k)
                    return s.substr(i, 1);
                --len;
            }
        }
        return "";
    }
};