class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        vector<int> lens;
        int prev = arr[0];
        int len = 1;

        for(int i = 1; i <= arr.size(); ++i, ++len) {
            if(i < arr.size() && arr[i] == prev)
                continue;
            lens.push_back(len);
            len = 0;
            if(i < arr.size())
                prev = arr[i];
        }
        sort(lens.begin(),lens.end());
        for(int i = 0; i < lens.size(); ++i){
            if(k >= lens[i])
                k -= lens[i];
            else
                return lens.size() - i;
        }
        return 0;
    }
};