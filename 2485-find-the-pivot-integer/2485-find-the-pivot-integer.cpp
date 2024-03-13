class Solution {
public:
    int pivotInteger(int n) {
        int left = 0, right = n, pivot = n;
        for(int i = 1; i <= n; ++i)
            left += i;
        while(left >= right) {
            if(left == right)
                return pivot;
            left -= pivot--;
            right += pivot;
        }
        return -1;
    }
};