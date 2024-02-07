class Solution {
public:
    static bool sortFunc(string a, string b) {
        if (a.size() == b.size())
            return a[0] - b[0] < 0;
        if (a.size() > b.size())
            return true;
        return false;
    }
    string frequencySort(string s) {
        vector<string> vec;
        string rtn;

        sort(s.begin(), s.end());
        for (int i = 0, j = 0; i < s.size(); i = j) {
            j = i;
            while (s[i] == s[j])
                ++j;
            vec.push_back(s.substr(i, j - i));
        }
        sort(vec.begin(), vec.end(), sortFunc);
        for (int i = 0; i < vec.size(); ++i)
            rtn += vec[i];
        return rtn;
    }
};