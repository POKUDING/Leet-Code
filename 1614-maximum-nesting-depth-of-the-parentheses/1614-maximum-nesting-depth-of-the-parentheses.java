class Solution {
    public int maxDepth(String s) {
        int depth = 0, max_depth = 0;
        for(int i = 0; i < s.length(); ++i) {
            if(s.charAt(i) == '(')
                ++depth;
            else if (s.charAt(i) == ')')
                --depth;
            max_depth = max_depth > depth ? max_depth : depth;
        }
        return max_depth;
    }
}