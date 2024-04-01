class Solution {
    public int lengthOfLastWord(String s) {
        String[] splitArr = s.split(" ");
        return splitArr[splitArr.length - 1].length();
    }
}