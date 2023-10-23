class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0)
            return false;
        long long tmp = 1;
        
        while(tmp <= n)
        {
            if (tmp == n)
                return true;
            tmp *= 4;
        }
        return false;
    }
};