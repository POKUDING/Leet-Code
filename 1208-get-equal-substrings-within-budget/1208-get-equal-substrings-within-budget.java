class Solution {
    public int equalSubstring(String s, String t, int maxCost) {
        int[] prefixSum = new int[s.length() + 1];
        int rtn = 0;

        prefixSum[1] = Math.abs(s.charAt(0) - t.charAt(0));
        for(int i = 1; i < s.length(); ++i)
            prefixSum[i + 1] = prefixSum[i] + Math.abs(s.charAt(i) - t.charAt(i));
        for(int i = 0, j = 1; j < prefixSum.length; ++j) {
            prefixSum[j] = prefixSum[j - 1] + Math.abs(s.charAt(j - 1) - t.charAt(j - 1));
            while(prefixSum[j] - prefixSum[i] > maxCost)
                ++i;
            rtn = Math.max(rtn, j - i);
        }
        return rtn;
    }
}