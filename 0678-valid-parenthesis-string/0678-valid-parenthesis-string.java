class Solution {
    public boolean checkValidString(String s) {
        int unusedStar = 0, leftStar = 0, rightStar = 0;
        int left = 0, right = 0;
        for(int i = 0; i < s.length(); ++i) {
            if(s.charAt(i) == '*') {
                if (left != 0) {
                    --left;
                    ++rightStar;
                }
                else
                    ++unusedStar;
            }
            else if (s.charAt(i) == '(')
                ++left;
            else if (s.charAt(i) == ')') {
                if(left != 0)
                    --left;
                else if (rightStar != 0) {
                    --rightStar;
                    ++unusedStar;
                } else if (unusedStar != 0) {
                    --unusedStar;
                    ++leftStar;
                } else {
                    System.out.println(i);
                    return false;
                }
            }


            // System.out.println(s.charAt(i) + " " + left + " " + leftStar + " " + rightStar + " " + unusedStar);
        }
        return left != 0 ? false : true;
    }
}