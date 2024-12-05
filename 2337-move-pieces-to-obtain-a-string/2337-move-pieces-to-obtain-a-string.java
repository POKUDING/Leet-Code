class Solution {
    public boolean canChange(String start, String target) {
        int startIdx = 0;
        int targetIdx = 0;

        while(targetIdx < target.length()) {
            char targetCurr = target.charAt(targetIdx);
            if(targetCurr == '_') {
                ++targetIdx;
                continue;
            }
            while (startIdx <= start.length()) {
                if(startIdx == start.length())
                    return false;
                char startCurr = start.charAt(startIdx);
                if(startCurr == '_') {
                    ++startIdx;
                    continue;
                }
                if(targetCurr == 'L' && startCurr == 'L' && targetIdx <= startIdx){
                    ++startIdx;
                    break;
                }
                if(targetCurr == 'R' && startCurr == 'R' && targetIdx >= startIdx){
                    ++startIdx;
                    break;
                }
                return false;
            }
            ++targetIdx;
        }
        while(startIdx < start.length()) {
            if(start.charAt(startIdx) != '_')
                return false;
            ++startIdx;
        }
        return true;
    }
}