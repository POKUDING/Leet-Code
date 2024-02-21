class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        string bitleft = bitset<32>(left).to_string();
        string bitright = bitset<32>(right).to_string();
        int rtn = 0;
        for (size_t i = bitright.find('1'); i < 32; ++i) {
            rtn <<= 1;
            if (bitleft[i] == '1')
                ++rtn;
            else
                bitleft[i + 1] = '0';
        }
        return rtn;
    }
};