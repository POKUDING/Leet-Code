class Solution {
    public String reversePrefix(String word, char ch) {
        StringBuilder sb = new StringBuilder();
        boolean flag = false;
        for(int i = 0; i < word.length(); ++i) {
            sb.append(word.charAt(i));
            if(word.charAt(i) == ch && flag == false) {
                flag = true;
                sb.reverse();
            }
        }
        return sb.toString();
    }
}