const static auto _ = [](){cin.tie(0); cout.tie(0); ios::sync_with_stdio(0); return nullptr;}();
class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int cnt0 = 0;
        int len = s.size();
        string rtn;
        for(int i = 0; i < len; ++i) {
            if(s[i] == '0')
                ++cnt0;
        }
        while((len--) - cnt0 > 1)
            rtn += '1';
        while(cnt0-- > 0)
            rtn += '0';
        return rtn + '1';
    }
};