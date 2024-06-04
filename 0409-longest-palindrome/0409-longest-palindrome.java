class Solution {
    public int longestPalindrome(String s) {
        Map<Character,Integer> counts = new HashMap<>();
        int oddCnt = 0;
        for(char c : s.toCharArray()) {
            counts.put(c, counts.getOrDefault(c,0) + 1);
            if(counts.get(c) % 2 == 1)
                ++oddCnt;
            else
                --oddCnt;
        }
        if(oddCnt > 1)
            return s.length() - oddCnt + 1;
        return s.length();
    }
}