class Solution {
    public String[] divideString(String s, int k, char fill) {
        int groupSize = s.length() / k + (s.length() % k == 0 ? 0 : 1);
        String[] rtn = new String[groupSize];
        StringBuilder sb = new StringBuilder();
        int rtnIdx = 0;

        for(int i = 0; i < s.length(); i += k) {
            for(int j = 0; j < k; ++j) {
                if(i + j < s.length())
                    sb.append(s.charAt(i + j));
                else
                    sb.append(fill);
            }
            rtn[rtnIdx++] = sb.toString();
            sb.setLength(0);
        }
        return rtn;
    }
}