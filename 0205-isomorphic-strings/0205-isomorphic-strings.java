class Solution {
    public boolean isIsomorphic(String s, String t) {
        int len = s.length();
        Map<Character, Character> map = new HashMap<Character,Character>();
        Set<Character> set = new HashSet<Character>();
        char[] sArr = s.toCharArray();
        char[] tArr = t.toCharArray();
        for(int i = 0; i < len; ++i){
            if(map.containsKey(sArr[i])) {
                if(map.get(sArr[i]) != tArr[i])
                    return false;
            } else if(map.containsValue(tArr[i]))
                return false;
            else
                map.put(sArr[i], tArr[i]);
        }
        return true;
    }
}