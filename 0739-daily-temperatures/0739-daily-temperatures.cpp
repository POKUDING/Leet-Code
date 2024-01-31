class Solution {
public:
    int idx = 0;
    map<int,int> res;
    void cntDay(vector<int>& temps) {
        int cur = idx++;
        if(idx != temps.size()) {
            while(idx < temps.size() && temps[cur] >= temps[idx])
                cntDay(temps);
        }
        res[cur] = idx != temps.size()? idx - cur : 0;
        return;
    }
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> rtn;
        while (idx < temperatures.size())
            cntDay(temperatures);
        for(int i = 0; i < temperatures.size(); ++i)
            rtn.push_back(res[i]);
        return rtn;
    }
};