static auto _ = []() { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return 
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        while(left < right)
            right &= right - 1;
        return right;
    }
};