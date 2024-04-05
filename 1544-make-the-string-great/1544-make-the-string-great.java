class Solution {
    public String makeGood(String s) {
        StringBuilder sb = new StringBuilder();
        sb.append(s.charAt(0));
        for(int i = 1; i < s.length(); ++i) {
            int len = sb.length();
            if(len != 0 && sb.charAt(len - 1) != s.charAt(i) &&
                Character.toLowerCase(sb.charAt(len - 1)) == Character.toLowerCase(s.charAt(i)))
                sb.setLength(len - 1);
            else
                sb.append(s.charAt(i));
        }
        return sb.toString();
    }
}