class Solution {
    public boolean canMakeSubsequence(String str1, String str2) {
        char[] str1arr = str1.toCharArray();
        char[] str2arr = str2.toCharArray();
        int str1Idx = 0;
        int str2Idx = 0;

        while(str1Idx < str1arr.length && str2Idx < str2arr.length){
            if (str1arr[str1Idx] == str2arr[str2Idx] ||
             nextChar(str1arr[str1Idx]) == str2arr[str2Idx]) {
                ++str1Idx;
                ++str2Idx;
            } else
                ++str1Idx;
        }

        if(str2Idx < str2arr.length)
            return false;

        return true;
    }

    public char nextChar(char c){
        char nextChar = c;

        nextChar += 1;

        if(nextChar > 'z')
            nextChar = 'a';

        return nextChar;
    }
}