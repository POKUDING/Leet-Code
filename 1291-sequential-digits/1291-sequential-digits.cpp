class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> rtn;
        for(int i = 1 ; i <= 9; ++i){
            int tmp = 0;
            int j = i;
            while(true && j <= 9){
                tmp = (tmp * 10) + j++;
                if(tmp > high)
                    break;
                if(tmp >= low)
                    rtn.push_back(tmp);
            }
        }
        sort(rtn.begin(), rtn.end());
        return rtn;
    }
};