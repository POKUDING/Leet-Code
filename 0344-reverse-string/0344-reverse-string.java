class Solution {
    public void reverseString(char[] s) {
        int sIdx = 0;
        int eIdx = s.length - 1;
        char tmp;
        while(sIdx < eIdx) {
            tmp = s[sIdx];
            s[sIdx++] = s[eIdx];
            s[eIdx--] = tmp;
        }
    }
}