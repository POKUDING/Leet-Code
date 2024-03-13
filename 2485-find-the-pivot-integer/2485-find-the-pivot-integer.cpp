class Solution {
public:
    int pivotInteger(int n) {
        double ans = sqrt(n*(n+1) / 2);
        return ans == floor(ans) ? ans : -1;
    }
};