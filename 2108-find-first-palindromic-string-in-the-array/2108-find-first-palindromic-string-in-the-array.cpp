class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(int i = 0; i < words.size(); ++i) {
            int start = 0;
            int end = words[i].size() - 1;
            while(start < words[i].size() && end >= 0) {
                if(start >= end)
                    return words[i];
                if(words[i][start] != words[i][end])
                    break;
                ++start;
                --end;
            }
        }
        return "";
    }
};