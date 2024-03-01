const static auto _ = [](){cin.tie(0); cout.tie(0); ios::sync_with_stdio(0); return nullptr;}();
class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int cnt1 = count(begin(s),end(s), '1');
        for(int i = 0; i < s.size(); ++i)
            s[i] = cnt1-- > 1 ? '1' : '0';
        s.back() = '1';
        return s;
    }
};