class Solution {
    public int scoreOfString(String s) {
        char[] charArr = s.toCharArray();
        int ans = 0;

        for(int i = 1; i < charArr.length; ++i)
            ans += Math.abs(charArr[i - 1] - charArr[i]);
        return ans;
    }
}