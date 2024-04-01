class Solution {
public:
    int lengthOfLastWord(string s) {
        int rev_s = s.size() - 1;
        int rev_e;
        while(rev_s >= 0 && s[rev_s] == ' ')
            --rev_s;
        rev_e = rev_s;
        while(rev_e >= 0 && s[rev_e] != ' ')
            --rev_e;
        return rev_s - rev_e;
    }
};