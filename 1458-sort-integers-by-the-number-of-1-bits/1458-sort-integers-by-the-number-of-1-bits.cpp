class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [](int num1, int num2){
            int num1_bit = __builtin_popcount(num1);
            int num2_bit = __builtin_popcount(num2);
            return (num1_bit == num2_bit) ? num1 < num2 : num1_bit < num2_bit;
        });
        return arr;
    }
};