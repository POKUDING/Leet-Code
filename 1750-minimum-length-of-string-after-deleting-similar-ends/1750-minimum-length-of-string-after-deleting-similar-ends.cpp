const static auto _ = [](){cin.tie(0); cout.tie(0); ios::sync_with_stdio(0); return nullptr;}
class Solution {
public:
    int minimumLength(string str) {
        int s = 0;
        int e = str.size() - 1;
        if (e == 0)
            return 1;
        while(true) {
            if(str[s] != str[e])
                return e - s + 1;
            while (str[s] == str[e] && s != e)
                --e;
            while(str[++s] == str[s - 1]);
            if (s == e)
                return 1;
            if(s > e)
                return 0;
        }
    }
};