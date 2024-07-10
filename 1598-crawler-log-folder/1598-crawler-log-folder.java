class Solution {
    public int minOperations(String[] logs) {
        int curr = 0;
        for(String log : logs) {
            curr += log.charAt(1) == '.' ? curr > 0 ? -1 : 0 : log.charAt(0) == '.' ? 0 : 1;
        }
        return curr;
    }
}