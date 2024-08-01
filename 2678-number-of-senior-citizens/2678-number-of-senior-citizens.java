class Solution {
    public int countSeniors(String[] details) {
        int ans = 0;

        for(String detail : details) {
            int age = 0;
            age += (detail.charAt(11) - '0') * 10;
            age += detail.charAt(12) - '0';
            // System.out.println(age);
            if(age > 60)
                ++ans;
        }
        return ans;
    }
}