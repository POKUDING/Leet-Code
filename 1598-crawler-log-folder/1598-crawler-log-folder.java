class Solution {
    public int minOperations(String[] logs) {
        int curr = 0;
        for(String log : logs) {
            if(log.equals("../"))
                curr -= curr > 0 ? 1 : 0;
            else if(!log.equals("./"))
                ++curr;
        }
        return curr;
    }
}