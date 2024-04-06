class Solution {
    public String minRemoveToMakeValid(String s) {
        ArrayList<Integer> arr = new ArrayList<>();
        StringBuilder sb = new StringBuilder();

        for(int i = 0; i < s.length(); ++i) {
            if(s.charAt(i) == '(')
                arr.add(i);
            else if (s.charAt(i) == ')') {
                if(arr.size() != 0 && s.charAt(arr.get(arr.size() - 1)) == '(')
                    arr.remove(arr.size() - 1);
                else
                    arr.add(i);
            }
        }
        for(int i = 0, j = 0; i < s.length(); ++i) {
            if(j < arr.size() && arr.get(j) == i)
                ++j;
            else
                sb.append(s.charAt(i));
        }
        return sb.toString();
    }
}