class Solution {
    public String smallestNumber(String pattern) {
        int length = pattern.length();
        StringBuilder sb = new StringBuilder();
        int[] stack = new int[length + 1];
        int index = 0;

        for(int i = 0; i <= length; ++i) {
            stack[index++] = i + 1;

            if (i == length || pattern.charAt(i) == 'I') {
                while (index > 0) {
                    sb.append(stack[--index]);
                }
            } 
        }
        return sb.toString();
    }
}