class Solution {
    public String removeKdigits(String num, int k) {
        Stack<Character> st = new Stack<>();
        StringBuilder sb = new StringBuilder();
        
        for(char c : num.toCharArray()) {
            while (!st.isEmpty() && k > 0 && st.peek() > c) {
                st.pop();
                --k;
            }
            st.add(c);
        }
        while(k-- > 0)
            st.pop();
        while(!st.isEmpty())
            sb.append(st.pop());
        sb.reverse();
        while(sb.length() > 0 && sb.charAt(0) == '0')
            sb.deleteCharAt(0);
        if(sb.length() == 0)
            return "0";
        return sb.toString();
    }
}