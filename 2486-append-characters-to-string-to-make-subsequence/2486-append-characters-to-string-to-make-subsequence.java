class Solution {
    public int appendCharacters(String s, String t) {
        int tIdx = 0;
        for(int sIdx = 0; sIdx < s.length() && tIdx < t.length(); ++sIdx) {
            if(s.charAt(sIdx) == t.charAt(tIdx))
                ++tIdx;
        }
        return t.length() - tIdx;
    }
}