class Solution {
public:
    int pivotInteger(int n) {
        // double ans = sqrt(n*(n+1) / 2);
        return sqrt(n*(n+1) / 2) == floor(sqrt(n*(n+1) / 2)) ? sqrt(n*(n+1) / 2) : -1;
    }
};