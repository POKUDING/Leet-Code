class Solution {
    public int numSteps(String s) {
        int step = 0;
        int tmp = 0;
        char[] charArr = s.toCharArray();

        for(int i = charArr.length - 1; i > 0; --i) {
            if(charArr[i] == '0' && tmp == 0)
                ++step;
            else if(charArr[i] == '1' && tmp == 1)
                ++step;
            else {
                step += 2;
                tmp = 1;
            }
        }
        if(tmp == 1)
            ++step;
        return step;
    }
}