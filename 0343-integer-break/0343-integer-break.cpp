class Solution {
public:
    int integerBreak(int n) {
        int rtn = 0;
        int cnt = 0;
        if (n == 2)
            return 1;
        else if (n == 3)
            return 2;
        while(n > 3 && n - 3 > 1)
        {
            n -= 3;
            ++cnt;
        }
        rtn = n * pow(3,cnt);
        return rtn;
    }
};