class Solution {
    public List<List<String>> partition(String s) {
        List<List<String>> rtn = new ArrayList<>();
        List<String> tmpList = new ArrayList<>();
        makePalindromePartition(s,0,tmpList,rtn);
        return rtn;
    }

    public void makePalindromePartition(String s, int i, List<String> tmpList, List<List<String>> rtn) {
        if(i == s.length())
            rtn.add(new ArrayList<>(tmpList));
        for(int j = i; j < s.length(); ++j) {
            if(checkPalindrome(s,i,j)) {
                tmpList.add(s.substring(i,j + 1));
                makePalindromePartition(s,j + 1, tmpList, rtn);
                tmpList.remove(tmpList.size() - 1);
            }
        }
    }

    public boolean checkPalindrome(String s, int i, int j) {
        while(i < j) {
            if (s.charAt(i) != s.charAt(j))
                return false;
            ++i;
            --j;
        }
        return true;
    }
}