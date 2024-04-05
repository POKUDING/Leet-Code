class Solution {
    public String makeGood(String s) {
        StringBuilder sb = new StringBuilder();
        sb.append(s.charAt(0));
        for(int i = 1; i < s.length(); ++i) {
            int len = sb.length();
            if(len != 0 && Math.abs(sb.charAt(len - 1) - s.charAt(i)) == 32)
                sb.setLength(len - 1);
            else
                sb.append(s.charAt(i));
        }
        return sb.toString();
    }
}